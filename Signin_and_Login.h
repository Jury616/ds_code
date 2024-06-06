#ifndef SIGNIN_AND_LOGIN_H
#define SIGNIN_AND_LOGIN_H
#include <iostream>
#include <fstream>
#include <vector>
#include "RC4.h"
#include<QMessageBox>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
using namespace std;



#define MAX_PASSWORD_SIZE 12
#define MIN_PASSWORD_SIZE 6
#define MAX_USER_NAME_SIZE 12
#define MIN_USER_NAME_SIZE 1
// 定义最大用户容量作为常量
#define MAX_USER_SIZE 100


// 接口类
class interface_login_module {
public:
    virtual bool load_users(std::string relative_address) = 0;

    virtual int login_user(std::string username, std::string password) = 0;

    virtual int add_user(std::string username, std::string pw1, std::string pw2) = 0;

    virtual bool save_users(std::string relative_address) = 0;
};

class Model : public interface_login_module {//存储数据模型
public:
    Model() {
        UserCount = 0;
        for (int i = 0; i < MAX_USER_SIZE; i++) {
            users[i] = User("", "");
        }
    }
    int UserCount = 0;//用户数量
    std::string User_info_address = "D:\\abc\\userinfo.txt";//用户信息存储文件地址
    class User {
    public:
        std::string username;
        std::string password;

        User(std::string username, std::string password) {//构造函数
            this->username = username;
            this->password = password;
        }

        User() {//默认构造函数
            this->username = "";
            this->password = "";
        }
    };

    User users[MAX_USER_SIZE];//用户数组

    bool load_users(std::string relative_address) override {//从文件中读取用户信息
        ifstream ifile(relative_address, ios::in);
        if (!ifile.is_open()) {
            return false;
        }
        string usernameEn, passwordEn, username, password;
        while (ifile >> usernameEn >> passwordEn) {//逐个解密存储
            username = Decode(usernameEn);
            password = Decode(passwordEn);
            users[UserCount]=User(username, password);
            UserCount++;
        }
        return true;
    }

    int login_user(std::string username, std::string password) override {//登录
        if (!load_users(User_info_address))
            return 0;
        bool found = false;
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username && users[i].password == password) {
                found = true;
                return 1;
            }
        if(!found){
                return 2;
            }
    }

    int add_user(std::string username, std::string pw1, std::string pw2) override {//注册
        if (!load_users(User_info_address))
            return 2;
        if (UserCount >= MAX_USER_SIZE) {

            return 3;
        }
        if (username.empty() || pw1.empty() || pw2.empty()) {

            return 4;
        }
        if (username.length() > MAX_USER_NAME_SIZE || username.length() < MIN_USER_NAME_SIZE) {

            return 5;
        }
        if (pw1.length() > MAX_PASSWORD_SIZE || pw1.length() < MIN_PASSWORD_SIZE) {

            return 6;
        }
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username) {

                return 7;
            }
        if (pw1 != pw2) {

            return 8;
        }
        /*以上都需要返回到重新注册的界面，通过UI实现,cout全部换成弹窗*/
        users[UserCount++] = User(username, pw1);
        save_users("D:\\abc\\userinfo.txt");
        return 1;//跳转到登录界面
    }

    bool save_users(std::string relative_address) override {//将数据写入文件
        ofstream ofile(relative_address);
        if (!ofile.is_open())
            return false;
        for (int i = 0; i < UserCount; i++) {
            std::string username = users[i].username;
            std::string password = users[i].password;
            ofile << Encode(username) << endl << Encode(password) << endl;
        }
        return true;
    }
};

#endif

