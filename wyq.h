#include "ui_select.h"
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

class MainWindow : public QMainWindow, public Ui::MainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUi(this);
        connect(search_and_recommend, &QPushButton::clicked, this, &MainWindow::onSearchAndRecommendClicked);
        connect(cd_place_list, &QPushButton::clicked, this, &MainWindow::onCdPlaceListClicked);
        connect(cd_comments, &QPushButton::clicked, this, &MainWindow::onCdCommentsClicked);
        connect(cd_diary, &QPushButton::clicked, this, &MainWindow::onCdDiaryClicked);
        connect(go_back, &QPushButton::clicked, this, &MainWindow::onGoBackClicked);
        connect(cd_food, &QPushButton::clicked, this, &MainWindow::onCdFoodClicked);
        connect(submit, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);
    }

private slots:
    void onSearchAndRecommendClicked() {
        QMessageBox::information(this, "搜索推荐", "搜索推荐按钮被点击");
    }

    void onCdPlaceListClicked() {
        QMessageBox::information(this, "场地列表", "场地列表按钮被点击");
    }

    void onCdCommentsClicked() {
        QMessageBox::information(this, "评论", "评论按钮被点击");
    }

    void onCdDiaryClicked() {
        QMessageBox::information(this, "日记", "日记按钮被点击");
    }

    void onGoBackClicked() {
        QMessageBox::information(this, "返回", "返回按钮被点击");
    }

    void onCdFoodClicked() {
        QMessageBox::information(this, "餐饮", "餐饮按钮被点击");
    }

    void onSubmitClicked() {
        QString seqNumber = sequence_number->text();
        QMessageBox::information(this, "提交", "序列号: " + seqNumber);
    }
};




