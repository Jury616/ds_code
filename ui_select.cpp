#include "ui_select.h"
#include <QApplication>
#include <QMainWindow>

class MainWindow : public QMainWindow, public Ui::MainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUi(this);
    }
};



