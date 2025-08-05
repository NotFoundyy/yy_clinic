#ifndef CDOCTORXG_H
#define CDOCTORXG_H

#include"CWindow.h"
#include"CDoctorZw.h"
#include"CTool.h"

class CDoctorXg:public CWindow
{
public:
	CDoctorXg(int winX,int winY,int winWidth,int winHeight);
	~CDoctorXg();
	int doAction();
	void paintWindow();
private:
	CControl * tip;
	CControl * idlab;
	CControl * zwlab;
	CControl * idedit;
	CControl * zwbut;
	CControl * okbut;
	CControl * cancelbut;
	
};

#endif