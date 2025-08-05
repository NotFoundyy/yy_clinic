#ifndef CADMINWIN_H
#define CADMINWIN_H

#include"CWindow.h"

class CAdminwin:public CWindow
{
public:
	CAdminwin(int winX,int winY,int winWidth,int winHeight);
	~CAdminwin();
	int doAction();
private:
	
	CControl * yhglbut;
	CControl * ysglbut; 
	CControl * ksglbut;
	CControl * sjtjbut; 
	CControl * cancelbut;

};

#endif