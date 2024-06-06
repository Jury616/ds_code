#ifndef FORMDIALOG_H
#define FORMDIALOG_H

#include <QDialog>
#include "login.h"

class FormDialog : public QDialog, private LUi::LDialog
{
    Q_OBJECT

public:
    explicit FormDialog(QWidget *parent = nullptr);

    int result;

private slots:
    void on_pushButton_clicked(){
        LoginDialog* log=new LoginDialog (this);
        log->exec();
    }
    void on_pushButton_2_clicked(){
        LoginDialog* log=new LoginDialog (this);
        log->exec();
    }
};

#endif // FORMDIALOG_H
