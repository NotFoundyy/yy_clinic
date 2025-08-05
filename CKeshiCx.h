#ifndef CKESHICX_H
#define CKESHICX_H

#include"CWindow.h"
#include "CKeshi.h"
#include"CKserror.h"

class CKeshiCx: public CWindow
{
public:
	CKeshiCx(int winX,int winY,int winWidth,int winHeight);
	~CKeshiCx();
	int doAction();
	void paintWindow();
	void winRun();
private:

	CControl * table;
	CControl * roleidlab;

	CControl * ksidlab;
	CControl * ksnamelab;
	CControl * kssmlab;


	CControl * roleidedit;
	CControl * cxbut;
	CControl * xzksbut;
	CControl * cancelbut;

	CControl *  fylab;

	int flag;
};

#endif