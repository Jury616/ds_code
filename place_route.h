#ifndef PLACE_ROUTE_H
#define PLACE_ROUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QString>
#include <string>
#include "datastr_wyq/datastr_wyq/DatabaseIF.h"
#include "datastr_wyq/datastr_wyq/shc/Database.h"
#include "datastr_wyq\datastr_wyq./PlaceRoute.h"  // Include the PlaceRoute header file

extern Database database;
extern int scenicAreaNumber;

QT_BEGIN_NAMESPACE

class place_route_Ui_dialog
{
public:
    QLineEdit *transportion_input;
    QLineEdit *sequence_input;
    QLineEdit *stategy_input;
    QLineEdit *source_input;
    QTextBrowser *rule_show;
    QTextBrowser *route_show;
    QTextBrowser *sequence_number;
    QPushButton *submit;
    QLineEdit *multiple_sequence_input;
    QTextBrowser *strategy_mode;
    QTextBrowser *transportation;
    QTextBrowser *sequence_number_multiple;
    QPushButton *go_back;
    QTextBrowser *source_number;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1537, 1174);
        transportion_input = new QLineEdit(Dialog);
        transportion_input->setObjectName(QStringLiteral("transportion_input"));
        transportion_input->setGeometry(QRect(440, 470, 271, 51));
        sequence_input = new QLineEdit(Dialog);
        sequence_input->setObjectName(QStringLiteral("sequence_input"));
        sequence_input->setGeometry(QRect(440, 320, 271, 51));
        stategy_input = new QLineEdit(Dialog);
        stategy_input->setObjectName(QStringLiteral("stategy_input"));
        stategy_input->setGeometry(QRect(120, 470, 241, 51));
        source_input = new QLineEdit(Dialog);
        source_input->setObjectName(QStringLiteral("source_input"));
        source_input->setGeometry(QRect(120, 320, 241, 51));
        rule_show = new QTextBrowser(Dialog);
        rule_show->setObjectName(QStringLiteral("rule_show"));
        rule_show->setGeometry(QRect(280, 20, 1191, 151));
        route_show = new QTextBrowser(Dialog);
        route_show->setObjectName(QStringLiteral("route_show"));
        route_show->setGeometry(QRect(40, 550, 1441, 621));
        sequence_number = new QTextBrowser(Dialog);
        sequence_number->setObjectName(QStringLiteral("sequence_number"));
        sequence_number->setGeometry(QRect(440, 240, 271, 61));
        submit = new QPushButton(Dialog);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(760, 400, 321, 101));
        QFont font;
        font.setPointSize(20);
        submit->setFont(font);
        multiple_sequence_input = new QLineEdit(Dialog);
        multiple_sequence_input->setObjectName(QStringLiteral("multiple_sequence_input"));
        multiple_sequence_input->setGeometry(QRect(760, 320, 691, 51));
        strategy_mode = new QTextBrowser(Dialog);
        strategy_mode->setObjectName(QStringLiteral("strategy_mode"));
        strategy_mode->setGeometry(QRect(120, 390, 241, 61));
        transportation = new QTextBrowser(Dialog);
        transportation->setObjectName(QStringLiteral("transportation"));
        transportation->setGeometry(QRect(440, 390, 271, 61));
        sequence_number_multiple = new QTextBrowser(Dialog);
        sequence_number_multiple->setObjectName(QStringLiteral("sequence_number_multiple"));
        sequence_number_multiple->setGeometry(QRect(760, 240, 691, 61));
        go_back = new QPushButton(Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(10, 20, 231, 131));
        QFont font1;
        font1.setPointSize(25);
        go_back->setFont(font1);
        source_number = new QTextBrowser(Dialog);
        source_number->setObjectName(QStringLiteral("source_number"));
        source_number->setGeometry(QRect(120, 240, 241, 61));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "路线规划", Q_NULLPTR));
        rule_show->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:12pt;\">1.\350\257\267\345\205\210\345\241\253\345\206\231\345\207\272\345\217\221\345\234\272\346\211\200\345\272\217\345\210\227\345\217\267\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:12pt;\">2.\351\200\211\346\213\251\350\267\235\347\246\273\346\234\200\347\237\255\347\255\226\347\225\245\357\274\214\347\255\226\347\225\245\346\250\241\345\274"
                        "\217\345\241\253\342\200\2340\342\200\235\357\274\233\351\200\211\346\213\251\346\227\266\351\227\264\346\234\200\347\237\255\347\255\226\347\225\245\357\274\214\347\255\226\347\225\245\346\250\241\345\274\217\345\241\253\342\200\2341\342\200\235\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:12pt;\">3.\344\272\244\351\200\232\346\226\271\345\274\217\357\274\232\346\255\245\350\241\214\357\274\214\345\241\253\342\200\2340\342\200\235\357\274\233\350\207\252\350\241\214\350\275\246\357\274\214\345\241\253\342\200\2341\342\200\235\357\274\233\347\224\265\347\223\266\350\275\246\357\274\214\345\241\253\342\200\2342\342\200\235\343\200\202\346\263\250\346\204\217\357\274\232\346\240\241\345\233\255\345\206\205\345\217\252\350\203\275\351\200\211\346\213\251\346\255\245\350\241\214\345\222\214\350\207\252\350\241\214\350\275\246\357\274\233\346\231\257\345\214"
                        "\272\345\206\205\345\217\252\350\203\275\351\200\211\346\213\251\346\255\245\350\241\214\345\222\214\347\224\265\347\223\266\350\275\246\343\200\202</span></p></body></html>", Q_NULLPTR));
        sequence_number->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\345\215\225\347\202\271\345\272\217\345\210\227\345\217\267</span></p></body></html>", Q_NULLPTR));
        submit->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244", Q_NULLPTR));
        strategy_mode->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\347\255\226\347\225\245\346\250\241\345\274\217(0/1)</span></p></body></html>", Q_NULLPTR));
        transportation->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\344\272\244\351\200\232\346\226\271\345\274\217(0/1/2)</span></p></body></html>", Q_NULLPTR));
        sequence_number_multiple->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\345\244\232\347\202\271\345\272\217\345\210\227\345\217\267\357\274\214\345\220\204\344\270\252\345\272\217\345\210\227\345\217\267\344\271\213\351\227\264\347\224\250\347\251\272\346\240\274\351\232\224\345\274\200</span></p></body></html>", Q_NULLPTR));
        go_back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        source_number->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:16pt;\">\345\207\272\345\217\221\345\234\272\346\211\200\345\272\217\345\210\227\345\217\267</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace route_space {
    class Dialog: public place_route_Ui_dialog {};
} // namespace route_space

QT_END_NAMESPACE

class PlaceRouteDialog : public QDialog
{
    Q_OBJECT

public:
    PlaceRouteDialog(QWidget *parent = nullptr, Database_IF *base = &database)
            : QDialog(parent), placeNavigator(base) // 在初始化列表中显式初始化 placeNavigator
        {
            ui.setupUi(this);
            connect(ui.submit, &QPushButton::clicked, this, &PlaceRouteDialog::onSubmitClicked);
            connect(ui.go_back, &QPushButton::clicked, this, &PlaceRouteDialog::onGoBackClicked);
        }

private slots:
    void onSubmitClicked()
    {
        QString sourceText = ui.source_input->text();
        QString sequenceText = ui.sequence_input->text();
        QString multipleSequenceText = ui.multiple_sequence_input->text();
        QString strategyText = ui.sequence_input->text();
        QString transportionText = ui.sequence_input->text();

        if (!sourceText.isEmpty() && !sequenceText.isEmpty() && !strategyText.isEmpty() && !transportionText.isEmpty()) {
            int source = sourceText.toInt();
            int sequence = sequenceText.toInt();
            int strategy = strategyText.toInt();
            int transportion = transportionText.toInt();
            placeNavigator.init_toursite( scenicAreaNumber);
            placeNavigator.set_current_place( source);
            placeNavigator.set_strategy_mode( strategy );
            placeNavigator.set_transport_mode( transportion );
            placeNavigator.reset_adjacency_matrix();
            struct path route = placeNavigator.get_route(sequence);
            displayRoute(route);
        } else if (!sourceText.isEmpty() && !multipleSequenceText.isEmpty()) {
            QStringList sequenceList = multipleSequenceText.split(' ');
            int source = sourceText.toInt();
            int cnt = sequenceList.size();
            int strategy = strategyText.toInt();
            int transportion = transportionText.toInt();
            placeNavigator.init_toursite( scenicAreaNumber);
            placeNavigator.set_current_place( source);
            placeNavigator.set_strategy_mode( strategy );
            placeNavigator.set_transport_mode( transportion );
            placeNavigator.reset_adjacency_matrix();
            int* destinations = new int[cnt];
            for (int i = 0; i < cnt; ++i) {
                destinations[i] = sequenceList[i].toInt();
            }
            struct path route = placeNavigator.get_route_mul(destinations, cnt);
             QString routeDetails;
            for (int i=0; i <= cnt ; i ++) {
                placeNavigator.set_current_place( route.places[i]->get_index());
                struct path route1 = placeNavigator.get_route(route.places[i+1]->get_index());
                if ( i < cnt){
                    for (int j = 0; j < route1.num_places -1; ++j) {
                        Place* place = route1.places[j];
                                            routeDetails += QString("场所序号: %1\n场所名称: %2\n场所介绍: %3\n场所类别: %4\n场所获赞数: %5\n场所评论数: %6\n\n")
                                                            .arg(place->get_index())
                                                            .arg(QString::fromStdString(*place->get_name()))
                                                            .arg(QString::fromStdString(*place->get_introduction()))
                                                            .arg(QString::fromStdString(*place->get_label()))
                                                            .arg(place->get_like_num())
                                                            .arg(place->get_comments_num());
                    }
                }
                else{
                    for (int j = 0; j < route1.num_places ; ++j) {
                        Place* place = route1.places[j];
                                            routeDetails += QString("场所序号: %1\n场所名称: %2\n场所介绍: %3\n场所类别: %4\n场所获赞数: %5\n场所评论数: %6\n\n")
                                                            .arg(place->get_index())
                                                            .arg(QString::fromStdString(*place->get_name()))
                                                            .arg(QString::fromStdString(*place->get_introduction()))
                                                            .arg(QString::fromStdString(*place->get_label()))
                                                            .arg(place->get_like_num())
                                                            .arg(place->get_comments_num());
                    }
                }
                ui.route_show->setText(routeDetails);
            }
            delete[] destinations;
        } else {
            ui.route_show->setText("输入错误，请检查输入框内容。");
        }
    }

    void onGoBackClicked()
    {
        accept();
    }

private:
    route_space::Dialog ui;
    implement_place_navigation placeNavigator;

    void displayRoute(const struct path& route)
    {
        QString routeDetails;
        for (int i = 0; i < route.num_places; ++i) {
            Place* place = route.places[i];
            routeDetails += QString("场所序号: %1\n场所名称: %2\n场所介绍: %3\n场所类别: %4\n场所获赞数: %5\n场所评论数: %6\n\n")
                            .arg(place->get_index())
                            .arg(QString::fromStdString(*place->get_name()))
                            .arg(QString::fromStdString(*place->get_introduction()))
                            .arg(QString::fromStdString(*place->get_label()))
                            .arg(place->get_like_num())
                            .arg(place->get_comments_num());
        }
        ui.route_show->setText(routeDetails);
    }
};

#endif // PLACE_ROUTE_H
