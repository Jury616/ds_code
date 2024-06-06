/********************************************************************************
** Form generated from reading UI file 'ui_select.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *search_and_recommend;
    QPushButton *cd_place_list;
    QPushButton *cd_comments;
    QPushButton *cd_diary;
    QPushButton *go_back;
    QTextBrowser *textBrowser;
    QPushButton *cd_food;
    QLineEdit *sequence_number;
    QPushButton *submit;
    QTextBrowser *textBrowser_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        search_and_recommend = new QPushButton(centralwidget);
        search_and_recommend->setObjectName(QStringLiteral("search_and_recommend"));
        search_and_recommend->setGeometry(QRect(40, 330, 131, 51));
        cd_place_list = new QPushButton(centralwidget);
        cd_place_list->setObjectName(QStringLiteral("cd_place_list"));
        cd_place_list->setGeometry(QRect(590, 210, 131, 51));
        cd_comments = new QPushButton(centralwidget);
        cd_comments->setObjectName(QStringLiteral("cd_comments"));
        cd_comments->setGeometry(QRect(590, 330, 131, 51));
        cd_diary = new QPushButton(centralwidget);
        cd_diary->setObjectName(QStringLiteral("cd_diary"));
        cd_diary->setGeometry(QRect(590, 390, 131, 51));
        go_back = new QPushButton(centralwidget);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(40, 390, 131, 51));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(140, 80, 431, 151));
        cd_food = new QPushButton(centralwidget);
        cd_food->setObjectName(QStringLiteral("cd_food"));
        cd_food->setGeometry(QRect(590, 270, 131, 51));
        sequence_number = new QLineEdit(centralwidget);
        sequence_number->setObjectName(QStringLiteral("sequence_number"));
        sequence_number->setGeometry(QRect(370, 280, 141, 41));
        submit = new QPushButton(centralwidget);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(290, 340, 141, 31));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(190, 280, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        search_and_recommend->setText(QApplication::translate("MainWindow", "\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\346\220\234\347\264\242\344\270\216\346\216\250\350\215\220", Q_NULLPTR));
        cd_place_list->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\234\272\346\211\200\345\210\227\350\241\250", Q_NULLPTR));
        cd_comments->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\204\350\256\272", Q_NULLPTR));
        cd_diary->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\270\270\345\255\246\346\227\245\350\256\260", Q_NULLPTR));
        go_back->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\346\270\270\345\255\246\347\263\273\347\273\237\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">1.\345\234\250\347\202\271\345\207\273\342\200\234\346\237\245"
                        "\347\234\213\345\234\272\346\211\200\345\210\227\350\241\250\342\200\235\343\200\201\342\200\234\347\276\216\351\243\237\346\216\250\350\215\220\342\200\235\343\200\201\342\200\234\346\237\245\347\234\213\350\257\204\350\256\272\342\200\235\345\222\214\342\200\234\346\237\245\347\234\213\346\270\270\345\255\246\346\227\245\350\256\260\342\200\235\346\214\211\351\222\256\344\271\213\345\211\215\357\274\214\350\257\267\345\205\210\346\217\220\344\272\244\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">2.\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\345\217\257\344\273\245\351\200\232\350\277\207\347\202\271\345\207\273\342\200\234\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\346\220\234\347"
                        "\264\242\344\270\216\346\216\250\350\215\220\342\200\235\346\214\211\351\222\256\350\277\233\345\205\245\345\257\271\345\272\224\351\241\265\351\235\242\345\220\216\346\237\245\350\257\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">3.\347\202\271\345\207\273\342\200\234\350\277\224\345\233\236\342\200\234\346\214\211\351\222\256\345\260\206\350\277\224\345\233\236\344\270\212\344\270\200\351\241\265\351\235\242\343\200\202</span></p></body></html>", Q_NULLPTR));
        cd_food->setText(QApplication::translate("MainWindow", "\347\276\216\351\243\237\346\216\250\350\215\220", Q_NULLPTR));
        submit->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">\350\257\267\350\276\223\345\205\245\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\357\274\210\350\257\267\350\276\223"
                        "\345\205\245\344\270\200\344\270\252\346\225\260\345\255\227\357\274\211</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
