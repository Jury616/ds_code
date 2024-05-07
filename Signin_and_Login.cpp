#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RC4.h"
#include "compression.h"
using namespace std;

// 密码加密密钥
const unsigned char EncryptKey[16] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '1', '2', '3', '4'};


std::string Encode(string &str) {
    string strMsgEn;
    size_t nLen = str.length();
    CRC4 objCR4;
    //加密
    objCR4.Init((LPCBYTE) EncryptKey, sizeof(EncryptKey));
    BYTE *pbDest = new BYTE[nLen + 1];
    memset(pbDest, 0, str.length() + 1);
    if (TRUE == objCR4.Update((LPBYTE) str.c_str(), pbDest, nLen)) {
        strMsgEn = (char *) pbDest;
        return strMsgEn;
    }
}

string Decode(string &strMsgEn) {
    string strMsgDe;
    size_t nLen = strMsgEn.length();
    CRC4 objCR4;
    //解密
    BYTE *pbDest2 = new BYTE[nLen + 1];
    memset(pbDest2, 0, nLen + 1);
    objCR4.Init((LPCBYTE) EncryptKey, sizeof(EncryptKey));//每次加密解密前都需要初始化
    if (TRUE == objCR4.Update((LPBYTE) strMsgEn.c_str(), pbDest2, nLen)) {
        strMsgDe = (char *) pbDest2;
        return strMsgDe;
    }
}

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

    virtual void login_user(std::string username, std::string password) = 0;

    virtual void add_user(std::string username, std::string pw1, std::string pw2) = 0;

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
            cout << "初始化文件打开失败！" << endl;
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

    void login_user(std::string username, std::string password) override {//登录
        if (!load_users(User_info_address)) return;
        bool found = false;
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username && users[i].password == password) {
                cout << "\t\t\t【系统提示】登录成功！" << endl;    //登录成功，换成弹窗
                found = true;
                return;
            }
        if(!found){
                cout << "\t\t\t【系统提示】用户名或密码错误！" << endl;    //登录失败，换成弹窗
            }
    }

    void add_user(std::string username, std::string pw1, std::string pw2) override {//注册
        if (!load_users(User_info_address)) return;
        if (UserCount >= MAX_USER_SIZE) {
            cout << "超过用户上限，无法注册！";
            return;
        }
        if (username.empty() || pw1.empty() || pw2.empty()) {
            cout << "用户名或密码不能为空！";
            return;
        }
        if (username.length() > MAX_USER_NAME_SIZE || username.length() < MIN_USER_NAME_SIZE) {
            cout << "用户名长度不符合要求！";
            return;
        }
        if (pw1.length() > MAX_PASSWORD_SIZE || pw1.length() < MIN_PASSWORD_SIZE) {
            cout << "密码长度不符合要求！";
            return;
        }
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username) {
                std::cout << "\t\t\t【系统提示】用户已存在!" << endl;
                return;
            }
        if (pw1 != pw2) {
            std::cout << "\t\t\t【系统提示】密码不一致!" << endl;
            return;
        }
        /*以上都需要返回到重新注册的界面，通过UI实现,cout全部换成弹窗*/
        users[UserCount++] = User(username, pw1);
        cout << "\t\t\t【系统提示】注册成功！" << endl;
        save_users("D:\\abc\\userinfo.txt");
        return;//跳转到登录界面
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


//测试
/*
int main() {
    Model model;
    int chose = -1;
    cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    cout << "\t\t\t┃       1.注    册     2.登    录       ┃\t\n";
    cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    cout << "\t\t\t【系统提示】请输入你的选择：";
    cin >> chose;
    if (chose > 2 || chose < -1) {
        cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
        cin >> chose;
    }
    string username, pw1, pw2,password;
    switch (chose) {
        case 1:
            cout << "\t\t\t【系统提示】请输入你的用户名和密码：";
            cin >> username >> pw1;
            cout << "\t\t\t【系统提示】请再输入一遍密码：";
            cin >> pw2;
            model.add_user(username, pw1, pw2);
            break;
        case 2:
            cout << "\t\t\t【系统提示】请输入你的用户名和密码：";
            cin >> username >> password;
            model.login_user(username,password);
            break;
    }
    // 以上都应该通过UI来实现
    system("pause");
    return 0;
}*/


int main() {
    map <char,int> dic;
    vector<pair<char,int> > vec;
    priority_queue<pNode ,vector<pNode>,cmp1 > deq;
    getdic2(dic,"key");
    getvec2(dic,vec);
    getnopriority_queue(vec,deq);
    pNode root = makhfmtr(deq);
    gethfmList2(root);
    dicToFile("key.txt",dic);
    smallerToFile("D:\\abc\\test.txt","D:\\abc\\compressed.txt");
    dic.clear();
    vec.clear();
    priority_queue<pNode ,vector<pNode>,cmp2 > deq2;
    dicFromFile("key.txt",dic);
    getvec(dic,vec);
    getnopriority_queue(vec,deq2);
    Node* head = makhfmtr(deq);
    jiemiToFile("D:\\abc\\compressed.txt","D:\\abc\\decompressed.txt",head);
    return 0;
}
