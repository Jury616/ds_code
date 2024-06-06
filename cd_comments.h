/********************************************************************************
** Form generated from reading UI file 'cd_comments.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CD_COMMENTS_H
#define CD_COMMENTS_H

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

QT_BEGIN_NAMESPACE

class Comments_Ui_Dialog
{
public:
    QPushButton *go_back;
    QTextBrowser *comments_show;
    QTextBrowser *hint;

    void setupUi(QDialog *Comments_Dialog)
    {
        Comments_Dialog->setObjectName(QStringLiteral("Comments_Dialog"));
        Comments_Dialog->resize(1537, 1174);
        go_back = new QPushButton(Comments_Dialog);
        go_back->setObjectName(QStringLiteral("go_back"));
        go_back->setGeometry(QRect(1230, 20, 241, 81));
        QFont font;
        font.setPointSize(23);
        go_back->setFont(font);
        comments_show = new QTextBrowser(Comments_Dialog);
        comments_show->setObjectName(QStringLiteral("comments_show"));
        comments_show->setGeometry(QRect(40, 140, 1431, 1001));
        hint = new QTextBrowser(Comments_Dialog);
        hint->setObjectName(QStringLiteral("hint"));
        hint->setGeometry(QRect(40, 30, 571, 71));

        retranslateUi(Comments_Dialog);

        QMetaObject::connectSlotsByName(Comments_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Comments_Dialog)
    {
        Comments_Dialog->setWindowTitle(QApplication::translate("Comments_Dialog", "查看评论", Q_NULLPTR));
        go_back->setText(QApplication::translate("Comments_Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        hint->setHtml(QApplication::translate("Comments_Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:18pt;\">\344\273\245\344\270\213\346\230\257\345\257\271\345\272\224\346\231\257\345\214\272\346\210\226\346\240\241\345\233\255\347\232\204\350\257\204\350\256\272\357\274\232</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Comments_Dialog: public Comments_Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE


class Comments_Dialog : public QDialog
{
    Q_OBJECT

public:
    Comments_Dialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        ui.setupUi(this);
        connect(ui.go_back, &QPushButton::clicked, this, &Comments_Dialog::onGoBackClicked);
        loadComments();
        showHint();
    }

private slots:
    void onGoBackClicked()
    {
        accept();
    }

private:
    Ui::Comments_Dialog ui;

    void loadComments()
    {
        // Get the number of comments for the scenic area
                int numComments = database.get_toursite_comment_num(scenicAreaNumber);
                QString comments;

                // Load each comment and append to the comments string
                for (int i = 0; i < numComments; ++i) {
                    QString comment = QString::fromStdString(*database.get_toursite_comment(scenicAreaNumber, i));
                    comments.append(comment + "\n\n");
                }

                // Set the comments text in the comments_show text browser
                ui.comments_show->setText(comments);
    }

    void showHint()
    {
        // Show hint text in hint text browser
        QString hintText = "以下是您所查找的评论：";
        ui.hint->setText(hintText);
    }
};

#endif // CD_COMMENTS_H
