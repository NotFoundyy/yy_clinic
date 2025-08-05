#ifndef CUSERQH_H
#define CUSERQH_H

#include"CWindow.h"
#include"CUserQhxg.h"

class CUserQh: public CWindow
{
public:
	CUserQh(int winX,int winY,int winWidth,int winHeight);
	~CUserQh();
	int doAction();
	void paintWindow();
	void winRun();
private:

	CControl * table;
	CControl * shurulab;
	CControl * zhilab;
	CControl * yybhlab;
	CControl * yysjlab;
	CControl * yyjzsjlab;
	CControl * yyyylab;
	CControl * yykslab;
	CControl * yyyslab;
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