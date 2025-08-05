#ifndef CUSERXG_H
#define CUSERXG_H

#include"CWindow.h"

class CUserXg: public CWindow
{
public:
	CUserXg(int winX,int winY,int winWidth,int winHeight);
	~CUserXg();
	int doAction();
	void paintWindow();
private:

	CControl * idlab;
	CControl *  oldmimalab;
	CControl * newmimalab;
	CControl * renewmimalab;

	CControl * idedit;
	CControl * oldmimaedit;
	CControl * newmimaedit;
	CControl * renewmimaedit;

	CControl * okbut;
	CControl * cancelbut;

	CControl * tip;
	

};

#endif