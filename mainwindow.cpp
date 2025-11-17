#include <string>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Derivatives/lexer.h"
#include "Derivatives/node.h"
#include "Derivatives/token.h"
#include "Derivatives/parser.h"
#include "Derivatives/simplifier.h"
#include "Derivatives/differentiator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculusEngine)
{
    ui->setupUi(this);
    // Set the central widget background (this is what you see)
    // if (centralWidget()) {
    //     centralWidget()->setStyleSheet(
    //         "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, "
    //         "stop:0 #0f0c29, stop:0.5 #302b63, stop:1 #24243e);"
    //         );
    // }

    // Make window size fixed (not resizable)
    // setFixedSize(1000, 500);  // Change width and height as needed

    // OR if you want to use the current size from Qt Designer:
    setFixedSize(size());

    // OR disable only maximize button but allow resize:
    // setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateBtn_clicked()
{
    std::string function = ui->txtInputFunction->text().toStdString();
    std::string vars = ui->txtInputVariables->text().toStdString();
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
    Node *root = parser.build_tree();
    Differentiator diff;
    Simplifier simp;

    std::vector<std::pair<std::string, std::string>> derivatives;
    for (int i = 0; i < vars.length(); i++) {
        if (!std::isalpha(static_cast<unsigned char>(vars[i]))) {
            continue;
        }
        std::string var = std::string(1, vars[i]);
        Node *temp = diff.differentiate(root, var);
        temp = simp.advanced_simplify(temp);
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

// ===== NUMBER BUTTONS =====
void MainWindow::on_num0_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "0");
}

void MainWindow::on_num1_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "1");
}

void MainWindow::on_num2_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "2");
}

void MainWindow::on_num3_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "3");
}

void MainWindow::on_num4_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "4");
}

void MainWindow::on_num5_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "5");
}

void MainWindow::on_num6_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "6");
}

void MainWindow::on_num7_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "7");
}

void MainWindow::on_num8_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "8");
}

void MainWindow::on_num9_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "9");
}

// ===== OPERATOR BUTTONS =====
void MainWindow::on_opPlus_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "+");
}

void MainWindow::on_opMinus_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "-");
}

void MainWindow::on_opMultiply_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "*");
}

void MainWindow::on_opDivide_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "/");
}

void MainWindow::on_opDot_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + ".");
}

void MainWindow::on_opEquals_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "=");
}

void MainWindow::on_opX_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "x");
}

// ===== FUNCTION BUTTONS =====
void MainWindow::on_funcSin_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "sin(");
}

void MainWindow::on_funcCos_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "cos(");
}

void MainWindow::on_funcTan_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "tan(");
}

void MainWindow::on_funcExp_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "e^");
}

void MainWindow::on_funcLog_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "log(");
}

void MainWindow::on_funcPower_clicked()
{
    ui->txtInputFunction->setText(ui->txtInputFunction->text() + "^");
}

// ===== CLEAR BUTTON =====
void MainWindow::on_clearBtn_clicked()
{
    ui->txtInputFunction->clear();
    ui->txtOutput->clear();
    ui->txtInputVariables->clear();
}
