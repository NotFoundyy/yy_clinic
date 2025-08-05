#ifndef CUSERYYMAIN_H
#define CUSERYYMAIN_H

#include"CWindow.h"

class CUserYymain:public CWindow
{
public:
	CUserYymain(int winX,int winY,int winWidth,int winHeight);
	~CUserYymain();
	int doAction();
private:
	CControl * roleButton1;
	CControl * roleButton2;
	CControl * roleButton3;
	CControl * roleButton4;
};

#endif