#ifndef CKSERROR_H
#define CKSERROR_H

#include"CWindow.h"
class CKserror:public CWindow
{
public:
	CKserror(int winX,int winY,int winWidth,int winHeight);
	~CKserror();
	int doAction();
private:
	CControl * rolebut1;
	CControl * rolebut2;
	CControl * rolebut3;
};

#endif