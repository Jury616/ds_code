#ifndef FIRST_H
#define FIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Form : public QDialog
{
    Q_OBJECT

public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    int result;

    Ui_Form(QWidget *parent = nullptr)
        : QDialog(parent), result(0)
    {
        setupUi(this);
    }

    void setupUi(QDialog *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("学生游学系统"));
        Form->resize(1024, 512);
        Form->setStyleSheet(QStringLiteral("background-image:url(./bacground.PNG)"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 80, 591, 181));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 350, 112, 34));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 350, 112, 34));

        retranslateUi(Form);

        // Connecting buttons to the same slot with the Form parameter
        QObject::connect(pushButton, &QPushButton::clicked, this, &Ui_Form::on_button_clicked);
        QObject::connect(pushButton_2, &QPushButton::clicked, this, &Ui_Form::on_button_clicked);

        QMetaObject::connectSlotsByName(Form);
    }

    void retranslateUi(QDialog *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "学生游学系统", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\346\270\270\345\255\246\346\227\245\350\256\260\347\263\273\347\273\237\357\274\201</span></p><p align=\"right\"><span style=\" font-size:14pt;\">Designed by\342\200\224\342\200\224\346\234\261\351\224\220\343\200\201\345\255\231\346\265\251\347\250\213\343\200\201\347\216\213\345\256\207\344\271\276</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "\347\231\273\345\275\225", Q_NULLPTR));
    }

public slots:
    void on_button_clicked();
};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FIRST_H
