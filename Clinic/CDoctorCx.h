#ifndef CDOCTORCX_H
#define CDOCTORCX_H

#include"CWindow.h"
#include"CDoctorXl.h"
#include"CDoctorXg.h"

class CDoctorCx: public CWindow
{
public:
	CDoctorCx(int winX,int winY,int winWidth,int winHeight);
	~CDoctorCx();
	int doAction();
	void paintWindow();
	void winRun();
private:

	CControl * table;

	CControl * roleidlab;
	CControl * ysidlab;
	CControl * ysnamelab;
	CControl * zhiweilab;
	CControl * keshilab;
	CControl * yiyuanlab;
	CControl * jianjielab;

	CControl * roleidedit;
	CControl * cxbut;
	CControl * cancelbut;

	CControl *  zyfylab;
	CControl *  sxfylab;

	CControl * rolebtu1;
	CControl * rolebtu2;
	CControl * rolebtu3;

};

#endif