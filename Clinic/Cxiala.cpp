#include"Cxiala.h"


CXiala::CXiala(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->roleButton1=new CButton(47,19,33,2,"管 理 员",BUTTON);
	this->roleButton2=new CButton(47,21,33,2,"医  生",BUTTON);
	this->roleButton3=new CButton(47,23,33,2,"普 通  用 户",BUTTON);

	this->addCon(roleButton1);
	this->addCon(roleButton2);
	this->addCon(roleButton3);

	
}
CXiala::~CXiala()
{
	delete this->roleButton1;
	delete this->roleButton2;
	delete this->roleButton3;
}
int CXiala::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 2;
	}	
	return 2;
}
