#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RC4.h"
#include "compression.h"
using namespace std;

// ���������Կ
const unsigned char EncryptKey[16] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '1', '2', '3', '4'};


std::string Encode(string &str) {
    string strMsgEn;
    size_t nLen = str.length();
    CRC4 objCR4;
    //����
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
    //����
    BYTE *pbDest2 = new BYTE[nLen + 1];
    memset(pbDest2, 0, nLen + 1);
    objCR4.Init((LPCBYTE) EncryptKey, sizeof(EncryptKey));//ÿ�μ��ܽ���ǰ����Ҫ��ʼ��
    if (TRUE == objCR4.Update((LPBYTE) strMsgEn.c_str(), pbDest2, nLen)) {
        strMsgDe = (char *) pbDest2;
        return strMsgDe;
    }
}

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

    virtual void login_user(std::string username, std::string password) = 0;

    virtual void add_user(std::string username, std::string pw1, std::string pw2) = 0;

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
            cout << "��ʼ���ļ���ʧ�ܣ�" << endl;
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

    void login_user(std::string username, std::string password) override {//��¼
        if (!load_users(User_info_address)) return;
        bool found = false;
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username && users[i].password == password) {
                cout << "\t\t\t��ϵͳ��ʾ����¼�ɹ���" << endl;    //��¼�ɹ������ɵ���
                found = true;
                return;
            }
        if(!found){
                cout << "\t\t\t��ϵͳ��ʾ���û������������" << endl;    //��¼ʧ�ܣ����ɵ���
            }
    }

    void add_user(std::string username, std::string pw1, std::string pw2) override {//ע��
        if (!load_users(User_info_address)) return;
        if (UserCount >= MAX_USER_SIZE) {
            cout << "�����û����ޣ��޷�ע�ᣡ";
            return;
        }
        if (username.empty() || pw1.empty() || pw2.empty()) {
            cout << "�û��������벻��Ϊ�գ�";
            return;
        }
        if (username.length() > MAX_USER_NAME_SIZE || username.length() < MIN_USER_NAME_SIZE) {
            cout << "�û������Ȳ�����Ҫ��";
            return;
        }
        if (pw1.length() > MAX_PASSWORD_SIZE || pw1.length() < MIN_PASSWORD_SIZE) {
            cout << "���볤�Ȳ�����Ҫ��";
            return;
        }
        for (int i = 0; i < UserCount; i++)
            if (users[i].username == username) {
                std::cout << "\t\t\t��ϵͳ��ʾ���û��Ѵ���!" << endl;
                return;
            }
        if (pw1 != pw2) {
            std::cout << "\t\t\t��ϵͳ��ʾ�����벻һ��!" << endl;
            return;
        }
        /*���϶���Ҫ���ص�����ע��Ľ��棬ͨ��UIʵ��,coutȫ�����ɵ���*/
        users[UserCount++] = User(username, pw1);
        cout << "\t\t\t��ϵͳ��ʾ��ע��ɹ���" << endl;
        save_users("D:\\abc\\userinfo.txt");
        return;//��ת����¼����
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


//����
/*
int main() {
    Model model;
    int chose = -1;
    cout << "\t\t\t��������������������������������������������������������������������������������\n";
    cout << "\t\t\t��       1.ע    ��     2.��    ¼       ��\t\n";
    cout << "\t\t\t��������������������������������������������������������������������������������\n";
    cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
    cin >> chose;
    if (chose > 2 || chose < -1) {
        cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
        cin >> chose;
    }
    string username, pw1, pw2,password;
    switch (chose) {
        case 1:
            cout << "\t\t\t��ϵͳ��ʾ������������û��������룺";
            cin >> username >> pw1;
            cout << "\t\t\t��ϵͳ��ʾ����������һ�����룺";
            cin >> pw2;
            model.add_user(username, pw1, pw2);
            break;
        case 2:
            cout << "\t\t\t��ϵͳ��ʾ������������û��������룺";
            cin >> username >> password;
            model.login_user(username,password);
            break;
    }
    // ���϶�Ӧ��ͨ��UI��ʵ��
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
