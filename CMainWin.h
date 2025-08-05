#ifndef CMAINWIN_H
#define CMAINWIN_H
#include"CWindow.h"

class CMainwin:public CWindow
{
public:
	CMainwin(int winX,int winY,int winWidth,int winHeight);;
	~CMainwin();
	int doAction();
private:
	CControl * title; 
	CControl * id; 
	CControl * signinbut; 
	CControl * loginbut;
	CControl * cancelbut;
};

#endif