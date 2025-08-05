#ifndef CLOGINWIN_H
#define CLOGINWIN_H

#include"CWindow.h"

class CLoginwin:public CWindow
{
public:
	CLoginwin(int winX,int winY,int winWidth,int winHeight);
	~CLoginwin();
	int doAction();
	int loginCheck();
private:
	CControl * title;
	CControl * accountlab;
	CControl * passwordlab;
	CControl * rolelab;
	CControl * accountledit;
	CControl * passwordedit;
	CControl * rolebut;
	CControl * loginbut; 
	CControl * cancelbut;
	CControl * tip;

};

#endif