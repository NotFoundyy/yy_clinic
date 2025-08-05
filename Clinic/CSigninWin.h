#ifndef CSIGNINWIN_H
#define CSIGNINWIN_H

#include"CWindow.h"

class CSigninwin: public CWindow
{
public:
	CSigninwin(int winX,int winY,int winWidth,int winHeight);
	~CSigninwin();
	int doAction();
	int Signincheck();
private:
	CControl * title;
	CControl * idnumlab;
	CControl * authcodelab;
	CControl * messagelab1;
	CControl * messagelab2;

	CControl * idnumedit;
	CControl * authcodeedit;

	CControl * authcodebut;
	CControl * okbut; 
	CControl * cancelbut ;
};

#endif