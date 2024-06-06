#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "register.h"
#include"Signin_and_Login.h"
class RegisterDialog : public QDialog, public Ui::RDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);

private slots:
    void handleRegister();

private:
    Model model;
};

#endif // REGISTERDIALOG_H
