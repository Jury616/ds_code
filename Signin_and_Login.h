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
// ��������û�������Ϊ����
#define MAX_USER_SIZE 100


// �ӿ���
class interface_login_module {
public:
    virtual bool load_users(std::string relative_address) = 0;

    virtual int login_user(std::string username, std::string password) = 0;

    virtual int add_user(std::string username, std::string pw1, std::string pw2) = 0;

    virtual bool save_users(std::string relative_address) = 0;
};

class Model : public interface_login_module {//�洢����ģ��
public:
    Model() {
        UserCount = 0;
        for (int i = 0; i < MAX_USER_SIZE; i++) {
            users[i] = User("", "");
        }
    }
    int UserCount = 0;//�û�����
    std::string User_info_address = "D:\\abc\\userinfo.txt";//�û���Ϣ�洢�ļ���ַ
    class User {
    public:
        std::string username;
        std::string password;

        User(std::string username, std::string password) {//���캯��
            this->username = username;
            this->password = password;
        }

        User() {//Ĭ�Ϲ��캯��
            this->username = "";
            this->password = "";
        }
    };

    User users[MAX_USER_SIZE];//�û�����

    bool load_users(std::string relative_address) override {//���ļ��ж�ȡ�û���Ϣ
        ifstream ifile(relative_address, ios::in);
        if (!ifile.is_open()) {
            return false;
        }
        string usernameEn, passwordEn, username, password;
        while (ifile >> usernameEn >> passwordEn) {//������ܴ洢
            username = Decode(usernameEn);
            password = Decode(passwordEn);
            users[UserCount]=User(username, password);
            UserCount++;
        }
        return true;
    }

    int login_user(std::string username, std::string password) override {//��¼
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

    int add_user(std::string username, std::string pw1, std::string pw2) override {//ע��
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
        /*���϶���Ҫ���ص�����ע��Ľ��棬ͨ��UIʵ��,coutȫ�����ɵ���*/
        users[UserCount++] = User(username, pw1);
        save_users("D:\\abc\\userinfo.txt");
        return 1;//��ת����¼����
    }

    bool save_users(std::string relative_address) override {//������д���ļ�
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

