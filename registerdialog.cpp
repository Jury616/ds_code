#include "registerdialog.h"
#include"scenic_area_select.h"
RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    connect(pushButton, &QPushButton::clicked, this, &RegisterDialog::handleRegister);
}

void RegisterDialog::handleRegister()
{
    QString username = textEdit->toPlainText();
    QString password = textEdit_2->toPlainText();
    QString confirmPassword = lineEdit->text();
    int res=this->model.add_user(username.toStdString(),password.toStdString(),confirmPassword.toStdString());
   switch(res){
  case 2:
       QMessageBox::warning(NULL, "Failed", "文件初始化失败！");
       break;
   case 3:
       QMessageBox::warning(NULL, "无法注册", "超过用户上限！");
       break;
   case 4:
         QMessageBox::warning(NULL, "注册失败", "用户名或密码不能为空！");
       break;
   case 5:
                   QMessageBox::warning(NULL, "注册失败", "用户名长度不符合要求！");
       break;
   case 6:
                   QMessageBox::warning(NULL, "注册失败", "密码长度不符合要求！");
       break;
   case 7:
                    QMessageBox::warning(NULL, "注册失败", "用户已存在！");
       break;
   case 8:
                   QMessageBox::warning(NULL, "注册失败", "两次密码不一致");
       break;
   case 1:
                   QMessageBox::information(this, "注册成功", "注册成功，欢迎使用！");
                   scenic_area_select_Dialog sasd;
                   sasd.exec();
                   accept();
          break;
   }
      if(res!=1){
        // 清空输入框
        textEdit_2->clear();
        lineEdit->clear();
        textEdit_2->setFocus();
    }
}
