/*
 * ToolUnits.h
 *
 *  Created on: 2022Äê7ÔÂ26ÈÕ
 *      Author: maochaoqun
 */

#ifndef TOOLS_TOOLUNITS_H_
#define TOOLS_TOOLUNITS_H_

class ToolUnits {
public:
	static int SaveData(char *szFileName,unsigned char *iBuf,unsigned int iLen);
	static int GetDataSize(char *szFileName);
	static int ReadData(char *szFileName,unsigned char *oBuf,int iLen);
	static int GetCurrentPath(char* exeFullPath,int pathLen);
	static int B64Encode(unsigned char *pInput, int nLength, char *pOutput, int nOutBufSize);
	static int B64Decode(const char *pInput, int nLength, unsigned char* pOutput);
};

#endif /* TOOLS_TOOLUNITS_H_ */
