#ifndef SCENIC_AREA_RECOMMEND_AND_SEARCH_H
#define SCENIC_AREA_RECOMMEND_AND_SEARCH_H

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

class area_recommend_search_Ui_Dialog
{
public:
    QPushButton *go_back;
    QPushButton *search_by_key_word;
    QPushButton *search_by_label;
    QTextBrowser *input_hint_label;
    QTextBrowser *scenic_area_from_search;
    QTextBrowser *recommend_hint;
    QPushButton *search_by_name;
    QTextBrowser *recommend_scenic_area;
    QLineEdit *key_word;
    QLineEdit *name;
    QLineEdit *label;
    QTextBrowser *input_hint_name;
    QTextBrowser *input_hint_ket_word;

    void setupUi(QDialog *Dialog)
    {
            Dialog->setObjectName(QStringLiteral("主页"));
        Dialog->resize(1534, 1174);
        go_back = new QPushButton(Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(20, 20, 191, 71));
        QFont font;
        font.setPointSize(20);
        go_back->setFont(font);
        search_by_key_word = new QPushButton(Dialog);
        search_by_key_word->setObjectName(QStringLiteral("search_by_key_word"));
        search_by_key_word->setGeometry(QRect(1260, 170, 221, 61));
        search_by_key_word->setFont(font);
        search_by_label = new QPushButton(Dialog);
        search_by_label->setObjectName(QStringLiteral("search_by_label"));
        search_by_label->setGeometry(QRect(950, 170, 211, 61));
        search_by_label->setFont(font);
        input_hint_label = new QTextBrowser(Dialog);
        input_hint_label->setObjectName(QStringLiteral("input_hint_label"));
        input_hint_label->setGeometry(QRect(910, 20, 281, 51));
        scenic_area_from_search = new QTextBrowser(Dialog);
        scenic_area_from_search->setObjectName(QStringLiteral("scenic_area_from_search"));
        scenic_area_from_search->setGeometry(QRect(600, 260, 921, 891));
        recommend_hint = new QTextBrowser(Dialog);
        recommend_hint->setObjectName(QStringLiteral("recommend_hint"));
        recommend_hint->setGeometry(QRect(20, 110, 491, 51));
        search_by_name = new QPushButton(Dialog);
        search_by_name->setObjectName(QStringLiteral("search_by_name"));
        search_by_name->setGeometry(QRect(630, 170, 221, 61));
        search_by_name->setFont(font);
        recommend_scenic_area = new QTextBrowser(Dialog);
        recommend_scenic_area->setObjectName(QStringLiteral("recommend_scenic_area"));
        recommend_scenic_area->setGeometry(QRect(20, 180, 491, 971));
        key_word = new QLineEdit(Dialog);
        key_word->setObjectName(QStringLiteral("key_word"));
        key_word->setGeometry(QRect(1220, 90, 301, 51));
        name = new QLineEdit(Dialog);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(600, 90, 281, 51));
        label = new QLineEdit(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(910, 90, 281, 51));
        input_hint_name = new QTextBrowser(Dialog);
        input_hint_name->setObjectName(QStringLiteral("input_hint_name"));
        input_hint_name->setGeometry(QRect(600, 20, 281, 51));
        input_hint_ket_word = new QTextBrowser(Dialog);
        input_hint_ket_word->setObjectName(QStringLiteral("input_hint_ket_word"));
        input_hint_ket_word->setGeometry(QRect(1220, 20, 301, 51));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "校园和景区的搜索与推荐", Q_NULLPTR));
        go_back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        search_by_key_word->setText(QApplication::translate("Dialog", "\346\237\245\350\257\242", Q_NULLPTR));
        search_by_label->setText(QApplication::translate("Dialog", "\346\237\245\350\257\242", Q_NULLPTR));
        input_hint_label->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\350\276\223\345\205\245\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\347\261\273\345\210\253\357\274\232</span></p></body></html>", Q_NULLPTR));
        recommend_hint->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\344\273\245\344\270\213\346\230\257\344\270\272\346\202\250\346\216\250\350\215\220\347\232\204\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255:</span></p></body></html>", Q_NULLPTR));
        search_by_name->setText(QApplication::translate("Dialog", "\346\237\245\350\257\242", Q_NULLPTR));
        input_hint_name->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\350\276\223\345\205\245\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\220\215\347\247\260\357\274\232</span></p></body></html>", Q_NULLPTR));
        input_hint_ket_word->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:11pt;\">\350\276\223\345\205\245\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\345\205\263\351\224\256\345\255\227\357\274\232</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace area_recommend_search_Place {
    class Dialog: public area_recommend_search_Ui_Dialog {};
}

QT_END_NAMESPACE

class ScenicAreaRecommendSearchDialog : public QDialog
{
    Q_OBJECT

public:
    ScenicAreaRecommendSearchDialog(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onGoBackClicked();
    void onSearchByKeyWordClicked();
    void onSearchByLabelClicked();
    void onSearchByNameClicked();

private:
    area_recommend_search_Place::Dialog ui;

    void loadScenicAreaRecommendations();
    int get_toursite_place_num();
    QString get_toursite_name(int index);
};

#endif // SCENIC_AREA_RECOMMEND_AND_SEARCH_H
