#ifndef CUSERYY_H
#define CUSERYY_H

#include"CWindow.h"
#include"CTool.h"

class CUserYy:public CWindow
{
public:
	CUserYy(int winX,int winY,int winWidth,int winHeight);
	~CUserYy();
	int doAction();
private:
	CControl * xzyylab;
	CControl * xzkslab;
	CControl * xzyslab;
	CControl * xzsjlab;
	CControl * mslab;

	CControl * xzyyedit;
	CControl * xzksedit;
	CControl * xzysedit;
	CControl * xzsjedit1;
	CControl * xzsjedit2;
	CControl * msedit;

	int quhao;
	
	CControl * okButton;
	CControl * cancelButton;
	
};

#endif