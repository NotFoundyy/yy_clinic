#ifndef CDOCTORJZJL_H
#define CDOCTORJZJL_H

#include"CWindow.h"

class CDoctorJzjl: public CWindow
{
public:
	CDoctorJzjl(int winX,int winY,int winWidth,int winHeight);
	~CDoctorJzjl();
	int doAction();
	void paintWindow();
private:

	CControl * IDlab;
	CControl * yymslab;
	CControl * jzmslab;

	CControl * IDedit;
	CControl * yymsedit;
	CControl * jzmsedit;

	CControl * okbut;
	CControl * cancelbut;

	CControl * tip;
};

#endif