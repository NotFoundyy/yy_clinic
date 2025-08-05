#ifndef CDOCTORKSXL_H
#define CDOCTORKSXL_H

#include"CWindow.h"
#include"CTool.h"

class CDoctorKsxl:public CWindow
{
public:
	CDoctorKsxl(int winX,int winY,int winWidth,int winHeight);
	~CDoctorKsxl();
	int doAction();
private:
	CControl * rolebut1;
	CControl * rolebut2;
	CControl * rolebut3;
};

#endif