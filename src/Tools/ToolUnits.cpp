/*
 * ToolUnits.cpp
 *
 *  Created on: 2022��7��26��
 *      Author: maochaoqun
 */

#include "ToolUnits.h"
#include "stdlib.h"
#include "direct.h"
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <direct.h>
#include <unistd.h>

int ToolUnits::SaveData(char *szFileName, unsigned char *iBuf,
		unsigned int iLen) {
	FILE *fp;
	fp = fopen(szFileName, "wb");
	if (!fp) {
		return -1;
	}
	if (fwrite(iBuf, 1, iLen, fp) != iLen) {
		fclose(fp);
		return -1;
	}
	fclose(fp);
	return 0;
}

int ToolUnits::GetDataSize(char *szFileName) {
	FILE *fp;
	fp = fopen(szFileName, ("rb"));
	if (!fp) {
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fclose(fp);
	return size;
}

int ToolUnits::ReadData(char *szFileName, unsigned char *oBuf, int iLen) {
	FILE *fp;
	fp = fopen(szFileName, "rb");
	if (!fp) {
		return -1;
	}
	fread(oBuf, 1, iLen, fp);
	fclose(fp);
	return 0;
}

int ToolUnits::GetCurrentPath(char *exeFullPath, int pathLen) {
	if (!getcwd(exeFullPath, pathLen)) {
		std::cout << "Get path fail!" << std::endl;
		return -1;
	}
	return 0;
}





/* 0��63����ת��Ϊ�ɼ��ַ���� */
char g_b64EncTable[65] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char g_b64DecTable[256] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f,

    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
    0x3c, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
    0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff,

    0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30,
    0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/*
********************************************************************************
* ��  ��: �����ݿ����base64����
* ��  ��:
*  pInput - ���룬����ǰ���ݿ�
*  nLength -  ���룬�������ݿ飨pInput������
*  pOutput - �����base64��������ݿ飬��СΪ�������ݵ�4/3����
*      ������ݿ�pInput ���������ݿ�pOutput ��ʼ��ַ������ͬ
*  nOutBufSize- ����,��ű�������ݣ�pOutput���Ļ�������С
* ��  ��:
*     0:���ڴ�ű�������ݵĻ���������������ʧ�ܡ�
*     ����0����������ݳ��ȣ�ֵΪ(inputLen+2)/3*4
********************************************************************************
*/
int ToolUnits::B64Encode(unsigned char *pInput, int nLength, char *pOutput, int nOutBufSize)
{
    int nModulus = nLength%3;
    int nOutLen = (nLength+2)/3*4; /* �����������4�������� */
    int nDatalen = nLength-nModulus;
    register int i, j;
    register int x, y, z;

    /* ��������СУ�� */
    if(nOutBufSize < nOutLen)
    {
        return 0;
    }

    for (i=0, j=0; i<nDatalen; i+=3,j+=4)
    {
        x = pInput[i];
        y = pInput[i+1];
        z = pInput[i+2];
        pOutput[j] = g_b64EncTable[x>>2];
        pOutput[j+1] = g_b64EncTable[((x&3)<<4)|(y>>4)];
        pOutput[j+2] = g_b64EncTable[((y&15)<<2)|(z>>6)];
        pOutput[j+3] = g_b64EncTable[z&63];
    }

    i = nDatalen;
    j = (nDatalen/3)*4;
    if (nModulus == 1)
    {
        x = pInput[i];
        pOutput[j] = g_b64EncTable[x>>2];
        pOutput[j+1] = g_b64EncTable[(x&3)<<4];
        pOutput[j+2] = '=';
        pOutput[j+3] = '=';
    }
    else if (nModulus == 2)
    {
        x = pInput[i];
        y = pInput[i+1];
        pOutput[j] = g_b64EncTable[x>>2];
        pOutput[j+1] = g_b64EncTable[((x&3)<<4)|(y>>4)];
        pOutput[j+2] = g_b64EncTable[(y&15)<<2];
        pOutput[j+3] = '=';
    }
    return nOutLen;
}

/*
********************************************************************************
* ��  ��: �������base64�������ݿ����base64����
* ��  ��:
*  pInput - ���룬base64�������ݿ�
*  nLength -  ���룬base64�������ݿ鳤��
*  pOutput - �����base64���������ݿ�
*      ������ݿ�pInput���������ݿ�pOutput��ʼ��ַ������ͬ
* ��  ��:
*  0: ��Ч���ݣ�����ʧ��
*       ����0��base64��������ݳ���
********************************************************************************
*/
int ToolUnits::B64Decode(const char *pInput, int nLength, unsigned char* pOutput)
{
    register int i,j;
    register int x, y, z, k;
    int nOutLen;
    int nPadBytes;
    int nDataLen;

    if(nLength%4 != 0)
    {
        return 0;
    }

    /* ����'='�ĸ����жϱ���ǰ���ݵĳ��� */
    if(pInput[nLength-2] == '=')
    {
        nPadBytes = 2;
    }
    else if(pInput[nLength-1] == '=')
    {
        nPadBytes = 1;
    }
    else
    {
        nPadBytes = 0;
    }

    nOutLen = nLength/4*3 - nPadBytes;
    nDataLen = (nLength-nPadBytes)/4*3;

    /* ��ʼ���� */
    for(i=0, j=0; i<nDataLen; i+=3, j+=4)
    {
        x = g_b64DecTable[pInput[j]];
        y = g_b64DecTable[pInput[j+1]];
        z = g_b64DecTable[pInput[j+2]];
        k = g_b64DecTable[pInput[j+3]];
        if (x==0xff || y==0xff || z==0xff || k==0xff)
        {
            return 0;
        }
        pOutput[i] = (x<<2)|(y>>4);
        pOutput[i+1] = ((y&15)<<4)|(z>>2);
        pOutput[i+2] = ((z&3)<<6)|k;
    }

    i = nDataLen;
    if (nPadBytes == 1)
    {
        x = g_b64DecTable[pInput[j]];
        y = g_b64DecTable[pInput[j+1]];
        z = g_b64DecTable[pInput[j+2]];

        pOutput[i] = (x<<2)|(y>>4);
        pOutput[i+1] = ((y&15)<<4)|(z>>2);
    }
    else if (nPadBytes == 2)
    {
        x = g_b64DecTable[pInput[j]];
        y = g_b64DecTable[pInput[j+1]];

        pOutput[i] = (x<<2)|(y>>4);
    }
    return nOutLen;
}


