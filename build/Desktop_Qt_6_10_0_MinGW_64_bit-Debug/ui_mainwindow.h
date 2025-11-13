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
    QLineEdit *txtInputFunction;
    QPushButton *calculateBtn;
    QLineEdit *txtInputVariables;
    QPlainTextEdit *txtOutput;
    QLabel *label;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *opDivide;
    QPushButton *num5;
    QPushButton *opMultiply;
    QPushButton *num6;
    QPushButton *num4;
    QPushButton *num2;
    QPushButton *opMinus;
    QPushButton *num3;
    QPushButton *num1;
    QPushButton *opDot_2;
    QPushButton *opPlus;
    QPushButton *opEquals;
    QPushButton *num0;
    QPushButton *funcSin;
    QPushButton *funcCos;
    QPushButton *funcTan;
    QPushButton *funcExp;
    QPushButton *opDot;
    QPushButton *funcLog;
    QPushButton *clearBtn;

    void setupUi(QMainWindow *CalculusEngine)
    {
        if (CalculusEngine->objectName().isEmpty())
            CalculusEngine->setObjectName("CalculusEngine");
        CalculusEngine->resize(993, 517);
        QFont font;
        font.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font.setPointSize(13);
        CalculusEngine->setFont(font);
        CalculusEngine->setAutoFillBackground(false);
        CalculusEngine->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(CalculusEngine);
        centralwidget->setObjectName("centralwidget");
        txtInputFunction = new QLineEdit(centralwidget);
        txtInputFunction->setObjectName("txtInputFunction");
        txtInputFunction->setGeometry(QRect(20, 30, 551, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font1.setPointSize(13);
        font1.setUnderline(false);
        txtInputFunction->setFont(font1);
        txtInputFunction->setAutoFillBackground(false);
        calculateBtn = new QPushButton(centralwidget);
        calculateBtn->setObjectName("calculateBtn");
        calculateBtn->setGeometry(QRect(370, 110, 201, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font2.setPointSize(13);
        font2.setWeight(QFont::DemiBold);
        font2.setUnderline(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::NoAntialias);
        font2.setHintingPreference(QFont::PreferDefaultHinting);
        calculateBtn->setFont(font2);
        calculateBtn->setAutoFillBackground(false);
        txtInputVariables = new QLineEdit(centralwidget);
        txtInputVariables->setObjectName("txtInputVariables");
        txtInputVariables->setGeometry(QRect(20, 110, 341, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font3.setPointSize(13);
        font3.setBold(false);
        txtInputVariables->setFont(font3);
        txtOutput = new QPlainTextEdit(centralwidget);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setGeometry(QRect(600, 70, 371, 221));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setKerning(true);
        txtOutput->setFont(font4);
        txtOutput->setAutoFillBackground(false);
        txtOutput->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
        txtOutput->setBackgroundVisible(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(600, 20, 181, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Poppins")});
        font5.setPointSize(15);
        font5.setWeight(QFont::ExtraBold);
        font5.setItalic(false);
        font5.setStrikeOut(false);
        font5.setStyleStrategy(QFont::PreferDefault);
        font5.setHintingPreference(QFont::PreferDefaultHinting);
        label->setFont(font5);
        num7 = new QPushButton(centralwidget);
        num7->setObjectName("num7");
        num7->setGeometry(QRect(20, 190, 121, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Berlin Sans FB")});
        font6.setPointSize(13);
        font6.setWeight(QFont::DemiBold);
        font6.setUnderline(false);
        font6.setKerning(true);
        font6.setStyleStrategy(QFont::PreferDefault);
        font6.setHintingPreference(QFont::PreferDefaultHinting);
        num7->setFont(font6);
        num7->setAutoFillBackground(false);
        num8 = new QPushButton(centralwidget);
        num8->setObjectName("num8");
        num8->setGeometry(QRect(150, 190, 121, 51));
        num8->setFont(font6);
        num8->setAutoFillBackground(false);
        num9 = new QPushButton(centralwidget);
        num9->setObjectName("num9");
        num9->setGeometry(QRect(280, 190, 141, 51));
        num9->setFont(font6);
        num9->setAutoFillBackground(false);
        opDivide = new QPushButton(centralwidget);
        opDivide->setObjectName("opDivide");
        opDivide->setGeometry(QRect(430, 190, 141, 51));
        opDivide->setFont(font6);
        opDivide->setAutoFillBackground(false);
        num5 = new QPushButton(centralwidget);
        num5->setObjectName("num5");
        num5->setGeometry(QRect(150, 270, 121, 51));
        num5->setFont(font6);
        num5->setAutoFillBackground(false);
        opMultiply = new QPushButton(centralwidget);
        opMultiply->setObjectName("opMultiply");
        opMultiply->setGeometry(QRect(430, 270, 141, 51));
        opMultiply->setFont(font6);
        opMultiply->setAutoFillBackground(false);
        num6 = new QPushButton(centralwidget);
        num6->setObjectName("num6");
        num6->setGeometry(QRect(280, 270, 141, 51));
        num6->setFont(font6);
        num6->setAutoFillBackground(false);
        num4 = new QPushButton(centralwidget);
        num4->setObjectName("num4");
        num4->setGeometry(QRect(20, 270, 121, 51));
        num4->setFont(font6);
        num4->setAutoFillBackground(false);
        num2 = new QPushButton(centralwidget);
        num2->setObjectName("num2");
        num2->setGeometry(QRect(150, 350, 121, 51));
        num2->setFont(font6);
        num2->setAutoFillBackground(false);
        opMinus = new QPushButton(centralwidget);
        opMinus->setObjectName("opMinus");
        opMinus->setGeometry(QRect(430, 350, 141, 51));
        opMinus->setFont(font6);
        opMinus->setAutoFillBackground(false);
        num3 = new QPushButton(centralwidget);
        num3->setObjectName("num3");
        num3->setGeometry(QRect(280, 350, 141, 51));
        num3->setFont(font6);
        num3->setAutoFillBackground(false);
        num1 = new QPushButton(centralwidget);
        num1->setObjectName("num1");
        num1->setGeometry(QRect(20, 350, 121, 51));
        num1->setFont(font6);
        num1->setAutoFillBackground(false);
        opDot_2 = new QPushButton(centralwidget);
        opDot_2->setObjectName("opDot_2");
        opDot_2->setGeometry(QRect(150, 430, 121, 51));
        opDot_2->setFont(font6);
        opDot_2->setAutoFillBackground(false);
        opPlus = new QPushButton(centralwidget);
        opPlus->setObjectName("opPlus");
        opPlus->setGeometry(QRect(430, 430, 141, 51));
        opPlus->setFont(font6);
        opPlus->setAutoFillBackground(false);
        opEquals = new QPushButton(centralwidget);
        opEquals->setObjectName("opEquals");
        opEquals->setGeometry(QRect(280, 430, 141, 51));
        opEquals->setFont(font6);
        opEquals->setAutoFillBackground(false);
        num0 = new QPushButton(centralwidget);
        num0->setObjectName("num0");
        num0->setGeometry(QRect(20, 430, 121, 51));
        num0->setFont(font6);
        num0->setAutoFillBackground(false);
        funcSin = new QPushButton(centralwidget);
        funcSin->setObjectName("funcSin");
        funcSin->setGeometry(QRect(600, 320, 81, 51));
        funcSin->setFont(font6);
        funcSin->setAutoFillBackground(false);
        funcCos = new QPushButton(centralwidget);
        funcCos->setObjectName("funcCos");
        funcCos->setGeometry(QRect(690, 320, 81, 51));
        funcCos->setFont(font6);
        funcCos->setAutoFillBackground(false);
        funcTan = new QPushButton(centralwidget);
        funcTan->setObjectName("funcTan");
        funcTan->setGeometry(QRect(790, 320, 81, 51));
        funcTan->setFont(font6);
        funcTan->setAutoFillBackground(false);
        funcExp = new QPushButton(centralwidget);
        funcExp->setObjectName("funcExp");
        funcExp->setGeometry(QRect(890, 320, 81, 51));
        funcExp->setFont(font6);
        funcExp->setAutoFillBackground(false);
        opDot = new QPushButton(centralwidget);
        opDot->setObjectName("opDot");
        opDot->setGeometry(QRect(600, 410, 81, 51));
        opDot->setFont(font6);
        opDot->setAutoFillBackground(false);
        funcLog = new QPushButton(centralwidget);
        funcLog->setObjectName("funcLog");
        funcLog->setGeometry(QRect(690, 410, 81, 51));
        funcLog->setFont(font6);
        funcLog->setAutoFillBackground(false);
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        clearBtn->setGeometry(QRect(790, 410, 181, 51));
        clearBtn->setFont(font2);
        clearBtn->setAutoFillBackground(false);
        CalculusEngine->setCentralWidget(centralwidget);

        retranslateUi(CalculusEngine);

        QMetaObject::connectSlotsByName(CalculusEngine);
    } // setupUi

    void retranslateUi(QMainWindow *CalculusEngine)
    {
        CalculusEngine->setWindowTitle(QCoreApplication::translate("CalculusEngine", "MainWindow", nullptr));
        txtInputFunction->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "FUNCTION: f(x)", nullptr));
        calculateBtn->setText(QCoreApplication::translate("CalculusEngine", "CALCULATE", nullptr));
        txtInputVariables->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "VARIABLES: x, y, z", nullptr));
        txtOutput->setPlaceholderText(QCoreApplication::translate("CalculusEngine", "Derivaties...", nullptr));
        label->setText(QCoreApplication::translate("CalculusEngine", "DERIVATIVES", nullptr));
        num7->setText(QCoreApplication::translate("CalculusEngine", "7", nullptr));
        num8->setText(QCoreApplication::translate("CalculusEngine", "8", nullptr));
        num9->setText(QCoreApplication::translate("CalculusEngine", "9", nullptr));
        opDivide->setText(QCoreApplication::translate("CalculusEngine", "/", nullptr));
        num5->setText(QCoreApplication::translate("CalculusEngine", "5", nullptr));
        opMultiply->setText(QCoreApplication::translate("CalculusEngine", "x", nullptr));
        num6->setText(QCoreApplication::translate("CalculusEngine", "6", nullptr));
        num4->setText(QCoreApplication::translate("CalculusEngine", "4", nullptr));
        num2->setText(QCoreApplication::translate("CalculusEngine", "2", nullptr));
        opMinus->setText(QCoreApplication::translate("CalculusEngine", "-", nullptr));
        num3->setText(QCoreApplication::translate("CalculusEngine", "3", nullptr));
        num1->setText(QCoreApplication::translate("CalculusEngine", "1", nullptr));
        opDot_2->setText(QCoreApplication::translate("CalculusEngine", ".", nullptr));
        opPlus->setText(QCoreApplication::translate("CalculusEngine", "+", nullptr));
        opEquals->setText(QCoreApplication::translate("CalculusEngine", "=", nullptr));
        num0->setText(QCoreApplication::translate("CalculusEngine", "0", nullptr));
        funcSin->setText(QCoreApplication::translate("CalculusEngine", "sin", nullptr));
        funcCos->setText(QCoreApplication::translate("CalculusEngine", "cos", nullptr));
        funcTan->setText(QCoreApplication::translate("CalculusEngine", "tan", nullptr));
        funcExp->setText(QCoreApplication::translate("CalculusEngine", "e^x", nullptr));
        opDot->setText(QCoreApplication::translate("CalculusEngine", ".", nullptr));
        funcLog->setText(QCoreApplication::translate("CalculusEngine", "log", nullptr));
        clearBtn->setText(QCoreApplication::translate("CalculusEngine", "CLEAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculusEngine: public Ui_CalculusEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
