#include "login.h"
#include "formdialog.h"
#include"scenic_area_select.h"
LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
{
    setupUi(this);
    connect(pushButton, &QPushButton::clicked, this, &LoginDialog::handleLogin);
}

void LoginDialog::handleLogin()
{
    QString username = lineEdit->text();
    QString password = lineEdit_2->text();

    // 处理用户名和密码
    int res = this->model.login_user(username.toStdString(), password.toStdString());
    switch (res) {

        case 2:
            QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
            break;
        case 0:
            QMessageBox::warning(this, "Failed", "文件初始化失败！");
            break;
    case 1:
        // 跳转到主页面
        QMessageBox::information(this, "登录成功", "尊敬的 " + username + " ，欢迎回来！");
        accept();  // 关闭登录对话框
        scenic_area_select_Dialog sasd;
        sasd.exec();
        break;
    }

    if (res != 1) {
        // 重置输入字段
        lineEdit->clear();
        lineEdit_2->clear();
        // 将焦点设置回用户名输入框
        lineEdit->setFocus();
    }
}
