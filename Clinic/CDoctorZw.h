#ifndef CDOCTORZW_H
#define CDOCTORZW_H

#include"CWindow.h"
#include"CTool.h"

class CDoctorZw:public CWindow
{
public:
	CDoctorZw(int winX,int winY,int winWidth,int winHeight);
	~CDoctorZw();
	int doAction();
private:
	CControl * rolebut1;
	CControl * rolebut2;
	CControl * rolebut3;
	CControl * rolebut4;
};

#endif