#ifndef RC4_H
#define RC4_H

#include <Windows.h>
#include <WinNT.h>
typedef unsigned char* LPBYTE;
typedef const unsigned char* LPCBYTE;
#include <string>

// 密码加密密钥
const unsigned char EncryptKey[16] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '1', '2', '3', '4'};

using namespace std;

// RC4加密算法
class CRC4
{
public:
    CRC4(void);
    ~CRC4(void);

    BOOL Init(LPCBYTE lpbzKey, DWORD dwKeyBytes);
    BOOL Update(LPBYTE lpbzSrc, LPBYTE lpbzDst, INT64 nSrcBytes);

protected:
    int m_nI;
    int m_nJ;
    BYTE m_bzS[256];
};

inline std::string Encode(string &str) {
    string strMsgEn;
    size_t nLen = str.length();
    // 加密
    CRC4 objCR4;
    objCR4.Init((LPCBYTE) EncryptKey, sizeof(EncryptKey));
    BYTE *pbDest = new BYTE[nLen + 1];
    memset(pbDest, 0, str.length() + 1);
    if (TRUE == objCR4.Update((LPBYTE) str.c_str(), pbDest, nLen)) {
        strMsgEn = (char *) pbDest;
        return strMsgEn;
    }
    return ""; // 防止编译器警告
}

inline string Decode(string &strMsgEn) {
    string strMsgDe;
    size_t nLen = strMsgEn.length();
    // 解密
    CRC4 objCR4;
    BYTE *pbDest2 = new BYTE[nLen + 1];
    memset(pbDest2, 0, nLen + 1);
    objCR4.Init((LPCBYTE) EncryptKey, sizeof(EncryptKey)); // 每次加密解密前都需要初始化
    if (TRUE == objCR4.Update((LPBYTE) strMsgEn.c_str(), pbDest2, nLen)) {
        strMsgDe = (char *) pbDest2;
        return strMsgDe;
    }
    return ""; // 防止编译器警告
}

#endif // RC4_H
