#ifndef CXIALA_H
#define CXIALA_H

#include"CWindow.h"

class CXiala:public CWindow
{
public:
	CXiala(int winX,int winY,int winWidth,int winHeight);
	~CXiala();
	int doAction();
private:
	CControl * roleButton1;
	CControl * roleButton2;
	CControl * roleButton3;
};

#endif