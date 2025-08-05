#ifndef CUSERQHXG_H
#define CUSERQHXG_H

#include"CWindow.h"
#include"CTool.h"

class CUserQhxg:public CWindow
{
public:
	CUserQhxg(int winX,int winY,int winWidth,int winHeight);
	~CUserQhxg();
	int doAction();
	void paintWindow();
private:
	CControl * tip1lab;
	CControl * tip2lab;
	CControl * qhbut;
	CControl * qxqhbut;
	CControl * cancelbut;
	
};

#endif