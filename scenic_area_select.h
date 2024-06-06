/********************************************************************************
** Form generated from reading UI file 'scenic_area_select.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SCENIC_AREA_SELECT_H
#define SCENIC_AREA_SELECT_H

#include"place_list.h"
#include"scenic_area_recommend_and_search.h"
#include"cd_comments.h"
#include"datastr_wyq/datastr_wyq/shc/Database.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include<QMessageBox>
#include"diarydialog.h"
QT_BEGIN_NAMESPACE

extern  int scenicAreaNumber;
extern Database database;

class Ui_Dialog
{
public:
    QTextBrowser *rule_text;
    QTextBrowser *input_hint;
    QLineEdit *sequence_number;
    QPushButton *submit;
    QPushButton *search_and_recommend;
    QPushButton *go_back;
    QPushButton *cd_food;
    QPushButton *cd_comments;
    QPushButton *cd_diary;
    QPushButton *cd_place_list;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1537, 958);
        rule_text = new QTextBrowser(Dialog);
        rule_text->setObjectName(QStringLiteral("rule_text"));
        rule_text->setGeometry(QRect(370, 90, 871, 271));
        input_hint = new QTextBrowser(Dialog);
        input_hint->setObjectName(QStringLiteral("input_hint"));
        input_hint->setGeometry(QRect(430, 470, 331, 81));
        sequence_number = new QLineEdit(Dialog);
        sequence_number->setObjectName(QStringLiteral("sequence_number"));
        sequence_number->setGeometry(QRect(880, 470, 251, 81));
        submit = new QPushButton(Dialog);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(660, 600, 271, 81));
        QFont font;
        font.setPointSize(20);
        submit->setFont(font);
        search_and_recommend = new QPushButton(Dialog);
        search_and_recommend->setObjectName(QStringLiteral("search_and_recommend"));
        search_and_recommend->setGeometry(QRect(80, 610, 251, 101));
        QFont font1;
        font1.setPointSize(10);
        search_and_recommend->setFont(font1);
        go_back = new QPushButton(Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(80, 760, 251, 91));
        QFont font2;
        font2.setPointSize(15);
        go_back->setFont(font2);
        cd_food = new QPushButton(Dialog);
        cd_food->setObjectName(QStringLiteral("cd_food"));
        cd_food->setGeometry(QRect(1290, 590, 201, 91));
        cd_food->setFont(font2);
        cd_comments = new QPushButton(Dialog);
        cd_comments->setObjectName(QStringLiteral("cd_comments"));
        cd_comments->setGeometry(QRect(1290, 710, 201, 91));
        cd_comments->setFont(font2);
        cd_diary = new QPushButton(Dialog);
        cd_diary->setObjectName(QStringLiteral("cd_diary"));
        cd_diary->setGeometry(QRect(1290, 830, 201, 91));
        cd_diary->setFont(font2);
        cd_place_list = new QPushButton(Dialog);
        cd_place_list->setObjectName(QStringLiteral("cd_place_list"));
        cd_place_list->setGeometry(QRect(1290, 460, 201, 101));
        cd_place_list->setFont(font2);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "景区或校园选择", Q_NULLPTR));
        rule_text->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\346\270\270\345\255\246\347\263\273\347\273\237\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">1.\345\234\250\347\202\271\345\207\273\342\200\234\346\237\245\347\234\213\345\234\272\346\211\200\345\210\227\350\241\250\342\200\235\343\200\201\342\200\234\347\276\216"
                        "\351\243\237\346\216\250\350\215\220\342\200\235\343\200\201\342\200\234\346\237\245\347\234\213\350\257\204\350\256\272\342\200\235\345\222\214\342\200\234\346\237\245\347\234\213\346\270\270\345\255\246\346\227\245\350\256\260\342\200\235\346\214\211\351\222\256\344\271\213\345\211\215\357\274\214\350\257\267\345\205\210\346\217\220\344\272\244\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">2.\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\345\217\257\344\273\245\351\200\232\350\277\207\347\202\271\345\207\273\342\200\234\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\346\220\234\347\264\242\344\270\216\346\216\250\350\215\220\342\200\235\346\214\211\351"
                        "\222\256\350\277\233\345\205\245\345\257\271\345\272\224\351\241\265\351\235\242\345\220\216\346\237\245\350\257\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">3.\347\202\271\345\207\273\342\200\234\350\277\224\345\233\236\342\200\234\346\214\211\351\222\256\345\260\206\350\277\224\345\233\236\344\270\212\344\270\200\351\241\265\351\235\242\343\200\202</span></p></body></html>", Q_NULLPTR));
        input_hint->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:12pt;\">\350\257\267\350\276\223\345\205\245\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\272\217\345\210\227\345\217\267\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:12pt;\">\357\274\210\350\257\267\350\276\223\345\205\245\344\270\200\344\270\252\346\225\260\345\255\227\357\274\211</span></p></body></html>", Q_NULLPTR));
        submit->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244", Q_NULLPTR));
        search_and_recommend->setText(QApplication::translate("Dialog", "\346\231\257\345\214\272\345\222\214\346\240\241\345\233\255\347\232\204\346\220\234\347\264\242\344\270\216\346\216\250\350\215\220", Q_NULLPTR));
        go_back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        cd_food->setText(QApplication::translate("Dialog", "\347\276\216\351\243\237\346\216\250\350\215\220", Q_NULLPTR));
        cd_comments->setText(QApplication::translate("Dialog", "\346\237\245\347\234\213\350\257\204\350\256\272", Q_NULLPTR));
        cd_diary->setText(QApplication::translate("Dialog", "\346\237\245\347\234\213\346\270\270\345\255\246\346\227\245\350\256\260", Q_NULLPTR));
        cd_place_list->setText(QApplication::translate("Dialog", "\346\237\245\347\234\213\345\234\272\346\211\200\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE



class scenic_area_select_Dialog : public QDialog, public Ui::Dialog {
    Q_OBJECT

public:
    scenic_area_select_Dialog(QWidget *parent = nullptr) : QDialog(parent) {
        setupUi(this);
        connect(submit, &QPushButton::clicked, this, &scenic_area_select_Dialog::onSubmitClicked);
        connect(search_and_recommend, &QPushButton::clicked, this, &scenic_area_select_Dialog::onSearchAndRecommendClicked);
        connect(go_back, &QPushButton::clicked, this, &scenic_area_select_Dialog::onGoBackClicked);
        connect(cd_food, &QPushButton::clicked, this, &scenic_area_select_Dialog::onCdFoodClicked);
        connect(cd_comments, &QPushButton::clicked, this, &scenic_area_select_Dialog::onCdCommentsClicked);
        connect(cd_diary, &QPushButton::clicked, this, &scenic_area_select_Dialog::onCdDiaryClicked);
        connect(cd_place_list, &QPushButton::clicked, this, &scenic_area_select_Dialog::onCdPlaceListClicked);
    }

private slots:
    void onSubmitClicked() {
        QString seqNumber = sequence_number->text();
                bool ok;
                int seqNumberInt = seqNumber.toInt(&ok);
                if (ok&&(seqNumberInt>=0&&seqNumberInt<=399)) {
                    scenicAreaNumber = seqNumberInt;
                    QMessageBox::information(this, "提交", "序列号: " + QString::number(seqNumberInt)+"     景区或校园的名称： " + QString :: fromStdString(* database.get_toursite_name(seqNumberInt)));
                } else {
                    // The conversion failed, handle the error
                    QMessageBox::warning(this, "错误", "请输入有效的序列号(0~399)");
                }
    }

    void onSearchAndRecommendClicked() {
        // accept();
        ScenicAreaRecommendSearchDialog dialogScenicAreaRecommendSearch(this);
        dialogScenicAreaRecommendSearch.exec();
    }

    void onGoBackClicked() {
        QMessageBox::information(NULL,"退出","欢迎下次使用！");
         accept();
    }

    void onCdFoodClicked() {
        QMessageBox::information(this, "餐饮", "餐饮按钮被点击");
    }

    void onCdCommentsClicked() {
        // accept();
        Comments_Dialog dialogComments;
        dialogComments.exec();
    }

    void onCdDiaryClicked() {
        DiaryDialog dd;
        dd.exec();
    }

    void onCdPlaceListClicked() {
        // accept();
        PlaceListDialog dialogPlaceList(this);
         dialogPlaceList.exec();
    }
};

#endif // SCENIC_AREA_SELECT_H
