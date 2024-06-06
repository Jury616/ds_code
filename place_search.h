/********************************************************************************
** Form generated from reading UI file 'place_search.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PLACE_SEARCH_H
#define PLACE_SEARCH_H

#include "datastr_wyq\datastr_wyq./PlaceRecom.h"
#include"datastr_wyq/datastr_wyq/DatabaseIF.h"
#include"datastr_wyq/datastr_wyq/shc/Database.h"

extern int scenicAreaNumber;
extern Database database;

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class search_Ui_Dialog
{
public:
    QLineEdit *place_index_1;
    QLineEdit *place_label_1;
    QPushButton *go_back;
    QLineEdit *place_label;
    QPushButton *submit_3;
    QTextBrowser *place_information;
    QLineEdit *place_index;
    QPushButton *submit_1;
    QTextBrowser *input_hint_1;
    QTextBrowser *number_of_place;
    QTextBrowser *input_hint_2;
    QPushButton *submit_2;
    QTextBrowser *show_number_hint;
    QTextBrowser *input_hint_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1537, 1174);
        place_index_1 = new QLineEdit(Dialog);
        place_index_1->setObjectName(QStringLiteral("place_index_1"));
        place_index_1->setGeometry(QRect(670, 220, 151, 41));
        place_label_1 = new QLineEdit(Dialog);
        place_label_1->setObjectName(QStringLiteral("place_label_1"));
        place_label_1->setGeometry(QRect(940, 220, 261, 41));
        go_back = new QPushButton(Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(1240, 10, 251, 111));
        QFont font;
        font.setPointSize(20);
        go_back->setFont(font);
        place_label = new QLineEdit(Dialog);
        place_label->setObjectName(QStringLiteral("place_label"));
        place_label->setGeometry(QRect(350, 220, 221, 41));
        submit_3 = new QPushButton(Dialog);
        submit_3->setObjectName(QStringLiteral("submit_3"));
        submit_3->setGeometry(QRect(790, 290, 211, 81));
        submit_3->setFont(font);
        place_information = new QTextBrowser(Dialog);
        place_information->setObjectName(QStringLiteral("place_information"));
        place_information->setGeometry(QRect(10, 400, 1501, 751));
        place_index = new QLineEdit(Dialog);
        place_index->setObjectName(QStringLiteral("place_index"));
        place_index->setGeometry(QRect(10, 220, 291, 41));
        submit_1 = new QPushButton(Dialog);
        submit_1->setObjectName(QStringLiteral("submit_1"));
        submit_1->setGeometry(QRect(50, 290, 201, 81));
        submit_1->setFont(font);
        input_hint_1 = new QTextBrowser(Dialog);
        input_hint_1->setObjectName(QStringLiteral("input_hint_1"));
        input_hint_1->setGeometry(QRect(10, 120, 291, 71));
        number_of_place = new QTextBrowser(Dialog);
        number_of_place->setObjectName(QStringLiteral("number_of_place"));
        number_of_place->setGeometry(QRect(530, 10, 281, 61));
        input_hint_2 = new QTextBrowser(Dialog);
        input_hint_2->setObjectName(QStringLiteral("input_hint_2"));
        input_hint_2->setGeometry(QRect(350, 120, 221, 71));
        submit_2 = new QPushButton(Dialog);
        submit_2->setObjectName(QStringLiteral("submit_2"));
        submit_2->setGeometry(QRect(370, 290, 191, 81));
        submit_2->setFont(font);
        show_number_hint = new QTextBrowser(Dialog);
        show_number_hint->setObjectName(QStringLiteral("show_number_hint"));
        show_number_hint->setGeometry(QRect(10, 10, 481, 61));
        input_hint_3 = new QTextBrowser(Dialog);
        input_hint_3->setObjectName(QStringLiteral("input_hint_3"));
        input_hint_3->setGeometry(QRect(670, 120, 531, 71));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "场所查询", Q_NULLPTR));
        go_back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        submit_3->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244", Q_NULLPTR));
        submit_1->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244", Q_NULLPTR));
        input_hint_1->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\344\273\245\346\237\220\344\270\252\345\234\272\346\211\200\344\270\272\344\270\255\345\277\203\346\237\245\350\257\242\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\357\274\210\350\276\223\345\205\245\350\257\245\345\234\272\346\211\200\347\232\204\345\272\217\345\210\227\345\217\267\357\274\211</span></p></body></html>", Q_NULLPTR));
        input_hint_2->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\346\214\211\347\261\273\345\210\253\350\277\207\346\273\244:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\357\274\210\350\276\223\345\205\245\345\234\272\346\211\200\347\261\273\345\210\253\357\274\211</span></p></body></html>", Q_NULLPTR));
        submit_2->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244", Q_NULLPTR));
        show_number_hint->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\345\206\205\351\203\250\347\232\204\345\234\272\346\211\200\346\225\260\351\207\217\344\270\272\357\274\232</span></p></body></html>", Q_NULLPTR));
        input_hint_3->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\346\237\245\350\257\242\346\237\220\344\270\252\345\234\272\346\211\200\351\231\204\350\277\221\347\232\204\346\237\220\347\261\273\346\234\215\345\212\241\350\256\276\346\226\275:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\357\274\210\345\210\206\345\210\253\350\276\223\345\205\245\345\234\272\346\211\200\345\272\217\345\210\227\345\217\267"
                        "\357\274\210\345\267\246\357\274\211\345\222\214\347\261\273\345\210\253\357\274\210\345\217\263\357\274\211\357\274\211</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace search_Space {
    class Dialog: public search_Ui_Dialog {};
}

QT_END_NAMESPACE

class PlaceSearchDialog : public QDialog
{
    Q_OBJECT

public:
    PlaceSearchDialog(QWidget *parent = nullptr);

private slots:
    void onGoBackClicked();
    void onSubmit1Clicked();
    void onSubmit2Clicked();
    void onSubmit3Clicked();
    void onScenicAreaNumberChanged();

private:
    search_Space::Dialog ui;
    implement_place_choosing *placeRecom = new implement_place_choosing ( & database , scenicAreaNumber);

    void updateNumberOfPlaces();
};

#endif // PLACE_SEARCH_H
