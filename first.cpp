#include "first.h"
#include <QPushButton>
#include <QDialog>

void Ui_Form::on_button_clicked()  // Define the slot function here
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        if (button->objectName() == QStringLiteral("pushButton"))
        {
            result = 1;
            //注册
        }
        else if (button->objectName() == QStringLiteral("pushButton_2"))
        {
            result = 2;
            //登录
        }
        accept();  // Close the dialog and return from exec()
    }
}




