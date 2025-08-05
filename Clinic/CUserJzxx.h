#ifndef CUSERJZXX_H
#define CUSERJZXX_H

#include"CWindow.h"

class CUserJzxx: public CWindow
{
public:
	CUserJzxx(int winX,int winY,int winWidth,int winHeight);
	~CUserJzxx();
	int doAction();
	void winRun();
	void paintWindow();
private:

	CControl * table;
	CControl * shurulab;
	CControl * zhilab;
	CControl * bianhaolab;
	CControl * jzsjlab;
	CControl * jzyylab;
	CControl * jzkslab;
	CControl * yslab;
	CControl * jzztlab;

	CControl *  zyfylab;
	CControl *  sxfylab;

	CControl * timeedit1;
	CControl * timeedit2;

	CControl * cxbut;
	CControl * cancelbut;

	CControl * rolebtu1;
	CControl * rolebtu2;
	CControl * rolebtu3;
};

#endif