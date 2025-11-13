#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = R"(
        /* ===== MODERN PARTIAL DERIVATIVE CALCULATOR THEME ===== */

        /* Main Window - Sophisticated gradient background */
        QMainWindow {
            background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,
                                       stop:0 #0f0c29, stop:0.5 #302b63, stop:1 #24243e);
        }

        /* Labels - Clean, modern typography */
        QLabel {
            color: #e8eaf6;
            font-family: "Segoe UI", Arial, sans-serif;
            font-size: 13px;
            font-weight: 500;
            letter-spacing: 0.5px;
        }

        /* Section Headers */
        QLabel[objectName="headerLabel"] {
            color: #b39ddb;
            font-size: 16px;
            font-weight: 600;
            letter-spacing: 2px;
            text-transform: uppercase;
        }

        /* Input Fields - Glass morphism effect */
        QLineEdit {
            background: rgba(255, 255, 255, 0.08);
            backdrop-filter: blur(10px);
            color: #ffffff;
            border: 2px solid rgba(179, 157, 219, 0.3);
            border-radius: 12px;
            padding: 12px 16px;
            font-size: 14px;
            font-family: "Consolas", "Courier New", monospace;
            selection-background-color: #7c4dff;
        }

        QLineEdit:focus {
            border: 2px solid #b39ddb;
            background: rgba(255, 255, 255, 0.12);
        }

        QLineEdit:hover {
            border: 2px solid rgba(179, 157, 219, 0.5);
            background: rgba(255, 255, 255, 0.10);
        }

        /* Calculate Button - Premium gradient */
        QPushButton#calculateBtn {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                       stop:0 #667eea, stop:1 #764ba2);
            color: #ffffff;
            border: none;
            border-radius: 12px;
            padding: 14px 24px;
            font-size: 15px;
            font-weight: 600;
            letter-spacing: 1px;
            text-transform: uppercase;
        }

        QPushButton#calculateBtn:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                       stop:0 #7c8ef5, stop:1 #8a5bb5);
        }

        QPushButton#calculateBtn:pressed {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                       stop:0 #5568d3, stop:1 #653a8f);
            padding: 15px 24px 13px 24px;
        }

        /* Number Buttons - Sleek cards */
        QPushButton[objectName^="num"] {
            background: rgba(255, 255, 255, 0.10);
            color: #ffffff;
            border: 1px solid rgba(255, 255, 255, 0.15);
            border-radius: 10px;
            padding: 12px;
            font-size: 16px;
            font-weight: 600;
            min-height: 45px;
            min-width: 45px;
        }

        QPushButton[objectName^="num"]:hover {
            background: rgba(255, 255, 255, 0.18);
            border: 1px solid rgba(179, 157, 219, 0.5);
            transform: translateY(-2px);
        }

        QPushButton[objectName^="num"]:pressed {
            background: rgba(255, 255, 255, 0.08);
            transform: translateY(0px);
        }

        /* Operator Buttons - Distinct accent */
        QPushButton[objectName^="op"] {
            background: rgba(124, 77, 255, 0.2);
            color: #b39ddb;
            border: 1px solid rgba(124, 77, 255, 0.4);
            border-radius: 10px;
            padding: 12px;
            font-size: 16px;
            font-weight: 600;
            min-height: 45px;
            min-width: 45px;
        }

        QPushButton[objectName^="op"]:hover {
            background: rgba(124, 77, 255, 0.3);
            border: 1px solid rgba(124, 77, 255, 0.6);
            color: #d1c4e9;
        }

        QPushButton[objectName^="op"]:pressed {
            background: rgba(124, 77, 255, 0.15);
        }

        /* Function Buttons - Special styling */
        QPushButton[objectName^="func"] {
            background: rgba(102, 126, 234, 0.2);
            color: #9fa8da;
            border: 1px solid rgba(102, 126, 234, 0.4);
            border-radius: 10px;
            padding: 10px;
            font-size: 13px;
            font-weight: 600;
            min-height: 42px;
        }

        QPushButton[objectName^="func"]:hover {
            background: rgba(102, 126, 234, 0.3);
            border: 1px solid rgba(102, 126, 234, 0.6);
            color: #c5cae9;
        }

        QPushButton[objectName^="func"]:pressed {
            background: rgba(102, 126, 234, 0.15);
        }

        /* Clear Button - Warning style */
        QPushButton#clearBtn {
            background: rgba(239, 83, 80, 0.2);
            color: #ef9a9a;
            border: 1px solid rgba(239, 83, 80, 0.4);
            border-radius: 10px;
            padding: 10px;
            font-size: 13px;
            font-weight: 600;
            min-height: 42px;
            text-transform: uppercase;
            letter-spacing: 1px;
        }

        QPushButton#clearBtn:hover {
            background: rgba(239, 83, 80, 0.3);
            border: 1px solid rgba(239, 83, 80, 0.6);
            color: #ffcdd2;
        }

        QPushButton#clearBtn:pressed {
            background: rgba(239, 83, 80, 0.15);
        }

        /* Output Area - Premium display */
        QPlainTextEdit {
            background: rgba(0, 0, 0, 0.3);
            backdrop-filter: blur(10px);
            color: #e8eaf6;
            border: 2px solid rgba(179, 157, 219, 0.2);
            border-radius: 12px;
            padding: 16px;
            font-family: "Consolas", "Courier New", monospace;
            font-size: 13px;
            line-height: 1.6;
            selection-background-color: #7c4dff;
        }

        QPlainTextEdit:focus {
            border: 2px solid rgba(179, 157, 219, 0.4);
        }

        /* Scrollbars - Minimalist design */
        QScrollBar:vertical {
            background: rgba(255, 255, 255, 0.05);
            width: 10px;
            border-radius: 5px;
            margin: 0px;
        }

        QScrollBar::handle:vertical {
            background: rgba(179, 157, 219, 0.4);
            min-height: 30px;
            border-radius: 5px;
        }

        QScrollBar::handle:vertical:hover {
            background: rgba(179, 157, 219, 0.6);
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }

        QScrollBar:horizontal {
            background: rgba(255, 255, 255, 0.05);
            height: 10px;
            border-radius: 5px;
            margin: 0px;
        }

        QScrollBar::handle:horizontal {
            background: rgba(179, 157, 219, 0.4);
            min-width: 30px;
            border-radius: 5px;
        }

        QScrollBar::handle:horizontal:hover {
            background: rgba(179, 157, 219, 0.6);
        }

        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
            width: 0px;
        }

        /* Tooltip styling */
        QToolTip {
            background: rgba(48, 43, 99, 0.95);
            color: #e8eaf6;
            border: 1px solid rgba(179, 157, 219, 0.5);
            border-radius: 6px;
            padding: 6px 10px;
            font-size: 12px;
        }
    )";

    a.setStyleSheet(style);

    MainWindow w;
    w.setWindowTitle("Partial Derivative Calculator");
    w.show();

    return a.exec();
}
