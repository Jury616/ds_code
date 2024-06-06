#include "RC4.h"
#include <string>
#include <windows.h>

CRC4::CRC4(void)
    : m_nI(0), m_nJ(0)
{
    RtlZeroMemory(m_bzS, 256);
}

CRC4::~CRC4(void)
{
}

BOOL CRC4::Init(LPCBYTE lpbzKey, DWORD dwKeyBytes)
{
    BOOL bSuccess = FALSE;
    if (NULL != lpbzKey && 0 < dwKeyBytes && 256 >= dwKeyBytes)
    {
        bSuccess = TRUE;

        BYTE k[256] = {0};
        if (256 == dwKeyBytes)
        {
            RtlCopyMemory(k, lpbzKey, dwKeyBytes);
        }
        else
        {
            for (DWORD i = 0; 256 > i; ++i)
            {
                m_bzS[i] = (BYTE)i;
                k[i] = lpbzKey[i % dwKeyBytes];
            }
        }

        int j = 0;
        BYTE temp = 0;
        for (int i = 0; 256 > i; ++i)
        {
            j = (j + m_bzS[i] + k[i]) % 256;
            temp = m_bzS[i];
            m_bzS[i] = m_bzS[j];
            m_bzS[j] = temp;
        }

        m_nI = m_nJ = 0;
    }
    return bSuccess;
}

BOOL CRC4::Update(LPBYTE lpbzSrc, LPBYTE lpbzDst, INT64 nSrcBytes)
{
    BOOL bSuccess = FALSE;
    if (NULL != lpbzSrc && NULL != lpbzDst && 0 < nSrcBytes)
    {
        bSuccess = TRUE;

        BYTE temp = 0;
        for (INT64 x = 0; x < nSrcBytes; ++x)
        {
            m_nI = (m_nI + 1) % 256;
            m_nJ = (m_nJ + m_bzS[m_nI]) % 256;
            temp = m_bzS[m_nI];
            m_bzS[m_nI] = m_bzS[m_nJ];
            m_bzS[m_nJ] = temp;
            int t = (m_bzS[m_nI] + m_bzS[m_nJ]) % 256;
            lpbzDst[x] = lpbzSrc[x] ^ m_bzS[t];
        }
    }
    return bSuccess;
}
