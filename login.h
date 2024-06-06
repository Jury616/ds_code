#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QString>
#include "Signin_and_Login.h"

QT_BEGIN_NAMESPACE
class LUi_Dialog
{
public:
    QPushButton* pushButton;
    QLineEdit* lineEdit;
    QLineEdit* lineEdit_2;
    QLabel* label;
    QLabel* label_2;
    QLabel* label_3;
    void setupUi(QDialog* Dialog)
    {
        Dialog->setObjectName(QStringLiteral("登录"));
        Dialog->resize(640, 550);
        Dialog->setMaximumSize(QSize(960, 960));


        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 420, 131, 41));

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 370, 141, 41));

        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(360, 370, 151, 41));
        lineEdit_2->setEchoMode(QLineEdit::Password);  // 隐藏密码输入

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 180, 511, 131));
        QFont font;
        font.setPointSize(14);
        font.setKerning(false);
        label->setFont(font);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 330, 101, 31));

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 330, 101, 31));

        pushButton->raise();
        lineEdit_2->raise();
        lineEdit->raise();
        label_2->raise();
        label_3->raise();
        label->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    }
 // setupUi

    void retranslateUi(QDialog* Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "登录", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "登录", Q_NULLPTR));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label->setText(QApplication::translate("Dialog", "请输入用户名和密码", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "用户名", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "密码", Q_NULLPTR));
    } // retranslateUi
};

namespace LUi {
    class LDialog : public LUi_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

class LoginDialog : public QDialog, public LUi::LDialog {
    Q_OBJECT

public:
    LoginDialog(QWidget* parent = nullptr);

private slots:
    void handleLogin();

private:
    Model model;
};

#endif // LOGIN_H
