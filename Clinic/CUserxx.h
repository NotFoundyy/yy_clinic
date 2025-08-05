#ifndef CUSERXX_H
#define CUSERXX_H

#include"CWindow.h"

class CUserXx: public CWindow
{
public:
	CUserXx(int winX,int winY,int winWidth,int winHeight);
	~CUserXx();
	int doAction();
	void paintWindow();
private:

	CControl * idlab;
	CControl *  namelab;
	CControl * idnumlab;

	CControl * idedit;
	CControl * nameedit;
	CControl * idnumedit;

	CControl * okbut;
	CControl * cancelbut;

	CControl * tip;
	

};

#endif