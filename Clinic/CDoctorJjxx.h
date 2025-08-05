#ifndef CDOCTORJJXX_H
#define CDOCTORJJXX_H

#include"CWindow.h"

class CDoctorJjxx: public CWindow
{
public:
	CDoctorJjxx(int winX,int winY,int winWidth,int winHeight);
	~CDoctorJjxx();
	int doAction();
	void paintWindow();
	void winRun();
private:

	CControl * table;
	CControl * bianhaolab;
	CControl * jzIDlab;
	CControl * zhuangtailab;


	CControl *  zyfylab;
	CControl *  sxfylab;

	CControl * cancelbut;

	CControl *rolebut1;
	CControl *rolebut2;
	CControl *rolebut3;
};

#endif