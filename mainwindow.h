#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculusEngine;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateBtn_clicked();

    // Number buttons
    void on_num0_clicked();
    void on_num1_clicked();
    void on_num2_clicked();
    void on_num3_clicked();
    void on_num4_clicked();
    void on_num5_clicked();
    void on_num6_clicked();
    void on_num7_clicked();
    void on_num8_clicked();
    void on_num9_clicked();

    // Operator buttons
    void on_opPlus_clicked();
    void on_opMinus_clicked();
    void on_opMultiply_clicked();
    void on_opDivide_clicked();
    void on_opDot_clicked();
    void on_opEquals_clicked();
    void on_opX_clicked();

    // Function buttons
    void on_funcSin_clicked();
    void on_funcCos_clicked();
    void on_funcTan_clicked();
    void on_funcExp_clicked();
    void on_funcLog_clicked();
    void on_funcPower_clicked();

    // Clear button
    void on_clearBtn_clicked();

private:
    Ui::CalculusEngine *ui;
};
#endif // MAINWINDOW_H
