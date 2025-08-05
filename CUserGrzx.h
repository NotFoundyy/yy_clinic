#ifndef CUSERGRZX_H
#define CUSERGRZX_H

#include"CWindow.h"

class CUserGrzx:public CWindow
{
public:
	CUserGrzx(int winX,int winY,int winWidth,int winHeight);
	~CUserGrzx();
	int doAction();
private:
	CControl * rolebut1;
	CControl * rolebut2;
	CControl * rolebut3;
};

#endif