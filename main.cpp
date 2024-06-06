#include"first.h"
#include"datastr_wyq/datastr_wyq/DatabaseIF.h"
#include"datastr_wyq/datastr_wyq/shc/Database.h"
#include <QMainWindow>
#include <QApplication>
#include"login.h"
#include"registerdialog.h"
#include"diarydialog.h"
#include <iostream>
#include"scenic_area_select.h"
#include "datastr_wyq/datastr_wyq/shc/util/utils.h"
#include"place_route.h"
/*
2024 shc
This is a test programme.
这个文件提供了模块1的使用方式, 仅作参考.
*/

Database database;

int scenicAreaNumber;

int main(int argc, char *argv[]) {

    database.load_database("D:/qt/project/datastructure/ui_wyq/datastr_wyq/datastr_wyq/shc/Database/");


    //    test();
    QApplication app(argc, argv);

    Ui_Form form;
    int clicked = form.exec();  // This will block until the dialog is closed
        if (clicked == QDialog::Accepted)
        {
           if(form.result==2){

               LoginDialog login;
               login.exec();
           }
           if(form.result==1){

               RegisterDialog registerDialog;
               registerDialog.exec();
           }
        }
/*
    scenic_area_select_Dialog d;
    d.show();
*/

    return app.exec();
}
