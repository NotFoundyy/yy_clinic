#ifndef CDOCTOREIN_H
#define CDOCTOREIN_H

#include"CWindow.h"

class CDoctorwin:public CWindow
{
public:
	CDoctorwin(int winX,int winY,int winWidth,int winHeight);
	~CDoctorwin();
	int doAction();
private:

	CControl * rolebut;
	CControl * querybut; 
	CControl * cancelbut;
};

#endif