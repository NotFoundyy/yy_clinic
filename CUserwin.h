#ifndef CUSERWIN_H
#define CUSERWIN_H

#include"CWindow.h"

class CUserwin:public CWindow
{
public:
	CUserwin(int winX,int winY,int winWidth,int winHeight);
	~CUserwin();
	int doAction();
private:
	CControl * grzxbut;
	CControl * yyglbut; 
	CControl * qhbut;
	CControl * jzxxbut; 
	CControl * cancelbut;
};

#endif