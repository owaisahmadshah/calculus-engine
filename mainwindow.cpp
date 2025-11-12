#include <string>
#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Derivatives/lexer.h"
#include "Derivatives/node.h"
#include "Derivatives/token.h"
#include "Derivatives/parser.h"
#include "Derivatives/evaluator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculusEngine)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalculate_clicked()
{
    std::string function = ui->txtInputFunction->text().toStdString(); // "x^5 * y
    std::string vars = ui->txtInputVariables->text().toStdString(); // x y ...

    ui->txtOutput->setPlainText("");

    Lexer lexer(function);

    std::vector<Token> tokens;
    while(true) {
        Token token = lexer.get_token();
        if (token.get_type() == Token_Type::END_OF_LINE)
            break;
        tokens.push_back(token);
    }

    Parser parser(tokens);
    Evaluator eval;
    Node *root = parser.build_tree();

    std::vector<std::pair<std::string, std::string>> derivatives;

    for (int i = 0; i < vars.length(); i++) {
        if (!std::isalpha(static_cast<unsigned char>(vars[i]))) {
            continue;
        }

        std::string var = std::string(1, vars[i]);

        Node *temp = eval.differentiate(root, var);
        temp = eval.advanced_simplify(temp);
        std::string derivative = temp->pretty_print();

        derivatives.push_back({derivative, var});
    }

    bool multipleVars = derivatives.size() > 1;

    for (auto &d : derivatives) {
        std::string symbol = multipleVars ? "∂" : "d";
        std::string result =
            symbol + "f / " + symbol + d.second + " = " + d.first;

        ui->txtOutput->appendPlainText(QString::fromStdString(result));
    }
}
