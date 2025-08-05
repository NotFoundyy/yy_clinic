#ifndef CDOCTORXL_H
#define CDOCTORXL_H

#include"CWindow.h"
#include"CTool.h"

class CDoctorXl:public CWindow
{
public:
	CDoctorXl(int winX,int winY,int winWidth,int winHeight);
	~CDoctorXl();
	int doAction();
private:
	CControl * rolebut1;
	CControl * rolebut2;
	CControl * tip;
};

#endif