/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculusEngine
{
public:
    QWidget *centralwidget;
    QLabel *labelInput;
    QLineEdit *txtInputFunction;
    QPushButton *btnCalculate;
    QFrame *line;
    QLabel *labelInput_2;
    QLineEdit *txtInputVariables;
    QPlainTextEdit *txtOutput;
    QFrame *line_2;
    QLabel *labelInput_3;

    void setupUi(QMainWindow *CalculusEngine)
    {
        if (CalculusEngine->objectName().isEmpty())
            CalculusEngine->setObjectName("CalculusEngine");
        CalculusEngine->resize(630, 495);
        CalculusEngine->setAutoFillBackground(true);
        centralwidget = new QWidget(CalculusEngine);
        centralwidget->setObjectName("centralwidget");
        labelInput = new QLabel(centralwidget);
        labelInput->setObjectName("labelInput");
        labelInput->setGeometry(QRect(60, 140, 21, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        labelInput->setFont(font);
        txtInputFunction = new QLineEdit(centralwidget);
        txtInputFunction->setObjectName("txtInputFunction");
        txtInputFunction->setGeometry(QRect(90, 130, 381, 31));
        txtInputFunction->setAutoFillBackground(true);
        btnCalculate = new QPushButton(centralwidget);
        btnCalculate->setObjectName("btnCalculate");
        btnCalculate->setGeometry(QRect(480, 130, 91, 31));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        btnCalculate->setFont(font1);
        btnCalculate->setAutoFillBackground(false);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(60, 220, 531, 21));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        labelInput_2 = new QLabel(centralwidget);
        labelInput_2->setObjectName("labelInput_2");
        labelInput_2->setGeometry(QRect(60, 180, 111, 16));
        labelInput_2->setFont(font);
        txtInputVariables = new QLineEdit(centralwidget);
        txtInputVariables->setObjectName("txtInputVariables");
        txtInputVariables->setGeometry(QRect(180, 170, 291, 31));
        txtOutput = new QPlainTextEdit(centralwidget);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setGeometry(QRect(140, 250, 361, 181));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        txtOutput->setFont(font2);
        txtOutput->setAutoFillBackground(false);
        txtOutput->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
        txtOutput->setBackgroundVisible(false);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(50, 100, 531, 21));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        labelInput_3 = new QLabel(centralwidget);
        labelInput_3->setObjectName("labelInput_3");
        labelInput_3->setGeometry(QRect(200, 40, 221, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setStrikeOut(false);
        labelInput_3->setFont(font3);
        CalculusEngine->setCentralWidget(centralwidget);

        retranslateUi(CalculusEngine);

        QMetaObject::connectSlotsByName(CalculusEngine);
    } // setupUi

    void retranslateUi(QMainWindow *CalculusEngine)
    {
        CalculusEngine->setWindowTitle(QCoreApplication::translate("CalculusEngine", "MainWindow", nullptr));
        labelInput->setText(QCoreApplication::translate("CalculusEngine", "f =", nullptr));
        txtInputFunction->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "Enter function here (x^2 * y) (x * y / y) etc...", nullptr));
        btnCalculate->setText(QCoreApplication::translate("CalculusEngine", "Differentiate", nullptr));
        labelInput_2->setText(QCoreApplication::translate("CalculusEngine", "Differentiate w.r.t", nullptr));
        txtInputVariables->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "Variables goes here x y z....", nullptr));
        txtOutput->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "Derivatives will be shown here...", nullptr));
        labelInput_3->setText(QCoreApplication::translate("CalculusEngine", "Calculus Engine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculusEngine: public Ui_CalculusEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
