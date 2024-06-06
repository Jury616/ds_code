/********************************************************************************
** Form generated from reading UI file 'place_list.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PLACE_LIST_H
#define PLACE_LIST_H

#include"datastr_wyq/datastr_wyq/shc/Database.h"
extern Database database;

extern int scenicAreaNumber;

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <datastr_wyq/datastr_wyq/DatabaseIF.h>

QT_BEGIN_NAMESPACE

class list_Ui_Dialog
{
public:
    QTextBrowser *list_of_place;
    QPushButton *place_route;
    QPushButton *place_search;
    QPushButton *cd_comments;
    QTextBrowser *show_hint;
    QPushButton *go_back;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1537, 1174);
        list_of_place = new QTextBrowser(Dialog);
        list_of_place->setObjectName(QStringLiteral("list_of_place"));
        list_of_place->setGeometry(QRect(30, 240, 1441, 911));
        place_route = new QPushButton(Dialog);
        place_route->setObjectName(QStringLiteral("place_route"));
        place_route->setGeometry(QRect(1270, 20, 201, 91));
        QFont font;
        font.setPointSize(15);
        place_route->setFont(font);
        place_search = new QPushButton(Dialog);
        place_search->setObjectName(QStringLiteral("place_search"));
        place_search->setGeometry(QRect(980, 20, 201, 91));
        place_search->setFont(font);
        cd_comments = new QPushButton(Dialog);
        cd_comments->setObjectName(QStringLiteral("cd_comments"));
        cd_comments->setGeometry(QRect(670, 20, 211, 91));
        cd_comments->setFont(font);
        show_hint = new QTextBrowser(Dialog);
        show_hint->setObjectName(QStringLiteral("show_hint"));
        show_hint->setGeometry(QRect(30, 170, 681, 51));
        go_back = new QPushButton(Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(30, 20, 231, 91));
        QFont font1;
        font1.setPointSize(20);
        go_back->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "场所列表", Q_NULLPTR));
        place_route->setText(QApplication::translate("Dialog", "\350\267\257\347\272\277\350\247\204\345\210\222", Q_NULLPTR));
        place_search->setText(QApplication::translate("Dialog", "\345\234\272\346\211\200\346\237\245\350\257\242", Q_NULLPTR));
        cd_comments->setText(QApplication::translate("Dialog", "\346\237\245\347\234\213\350\257\204\350\256\272", Q_NULLPTR));
        show_hint->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\344\273\245\344\270\213\346\230\257\346\202\250\346\211\200\345\234\250\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\206\205\351\203\250\345\234\272\346\211\200\345\210\227\350\241\250\357\274\232</span></p></body></html>", Q_NULLPTR));
        go_back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace list_space {
    class Dialog: public list_Ui_Dialog {};
} // namespace list_space

QT_END_NAMESPACE

class PlaceListDialog : public QDialog
{
    Q_OBJECT

public:
    PlaceListDialog(QWidget *parent = nullptr);


private slots:
    void onPlaceRouteClicked();
    void onPlaceSearchClicked();
    void onCdCommentsClicked();
    void onGoBackClicked();

private:
    list_space::Dialog ui;

    void loadPlaces()
        {
            std::vector<std::string> places_info;
            ToursiteTopo * topo = database.get_toursite_topo(scenicAreaNumber);
            std::cout<<1;
            for (int i = 0; i < database.get_toursite_place_num( scenicAreaNumber ); ++i) {
                Place * this_place = topo->places[i];
                std::string info = "场所序列号: " + std::to_string(this_place->get_index()) + "\n" +
                                   "场所名称: " + *this_place->get_name() + "\n" +
                                   "场所介绍: " + *this_place->get_introduction() + "\n" +
                                   "场所类别: " + *this_place->get_label() + "\n" +
                                   "场所获赞数: " + std::to_string(this_place->get_comments_num()) + "\n" +
                                   "场所评论数: " + std::to_string(this_place->get_comments_num());
                places_info.push_back(info);
            }

            QString places_text;
            for (const auto &info : places_info) {
                places_text += QString::fromStdString(info) + "\n\n";
            }

            ui.list_of_place->setText(places_text);
        }


};

#endif // PLACE_LIST_H
