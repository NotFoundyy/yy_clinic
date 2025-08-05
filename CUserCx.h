#ifndef CUSERCX_H
#define CUSERCX_H

#include"CWindow.h"

class CUserCx: public CWindow
{
public:
	CUserCx(int winX,int winY,int winWidth,int winHeight);
	~CUserCx();
	int doAction();
	void paintWindow();
	void winRun();
private:

	CControl * table;
	CControl * roleidlab;
	CControl * zhanghaolab;
	CControl * sfxxlab;
	CControl * roleidedit;
	CControl * cxbut;
	CControl * cancelbut;
	CControl *  fylab;

};

#endif