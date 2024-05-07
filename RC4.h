#pragma once
#include <Windows.h>
#include <WinNT.h>
typedef unsigned char*			LPBYTE;
typedef const unsigned char*	LPCBYTE;
#include <string>

using namespace std;
 //RC4加密算法
class CRC4
{
public:
	CRC4(void);
	~CRC4(void);
 
public:
	/*
	说明：设置RC4加密密钥(加密解密使用同一密钥)
	密钥长度为1-256字节
	密钥的长度 dwKeyBytes 与明文长度、密钥流的长度没有必然关系
	通常密钥的长度取16字节（128比特）
	参数：
	lpbzKey			密钥
	dwBytes			密钥长度
	返回：只要NULL != lpbzKey就返回TRUE
	*/
	BOOL Init(LPCBYTE lpbzKey, DWORD dwKeyBytes);
 
	/*
	说明：
	加密过程：输入待加密明文 lpbzSrc ，输出密文lpbzDst ；
	解密过程：输入待解密密文 lpbzSrc ，输出解密明文lpbzDst 。
	输入和输出长度都是 nSrcBytes 字节
	lpbzDst 可以等于 lpbzSrc
	返回：只要NULL != lpbzSrc && NULL != lpbzDst && 0 != nSrcBytes 就返回TRUE。
	*/
	BOOL Update(LPBYTE lpbzSrc, LPBYTE lpbzDst, INT64 nSrcBytes);
 
protected:
	int		m_nI;
	int		m_nJ;
	BYTE	m_bzS[256];
};
 

 CRC4::CRC4(void)
	: m_nI(0)
	, m_nJ(0)
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
 
		BYTE k[256] = { 0 };
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


