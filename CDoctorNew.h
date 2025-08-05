#ifndef CDOCTORNEW_H
#define CDOCTORNEW_H

#include"CWindow.h"
#include"CTool.h"
#include"CDoctorZw.h"
#include"CDoctorKsxl.h"

class CDoctorNew:public CWindow
{
public:
	CDoctorNew(int winX,int winY,int winWidth,int winHeight);
	~CDoctorNew();
	void paintWindow();
	int doAction();
private:
	CControl * ysidlab;
	CControl * ysnamelab;
	CControl * ssyylab;
	CControl * sskslab;
	CControl * yszwlab;
	CControl * ysjjlab;

	CControl * ysidedit;
	CControl * ysnameedit;
	CControl * ssyyedit;
	CControl * ssksedit;
	CControl * yszwedit;
	CControl * ysjjedit;

	CControl * okbut;
	CControl * cancelbut;

	CControl * tip;
};

#endif