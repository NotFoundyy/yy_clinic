#include"CUserGrzx.h"

CUserGrzx::CUserGrzx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->rolebut1=new CButton(35,12,20,2,"信 息  完 善",BUTTON);
	this->rolebut2=new CButton(65,12,20,2,"修 改  密 码",BUTTON);
	this->rolebut3=new CButton(35,20,20,2,"返  回",BUTTON);

	this->addCon(rolebut1);
	this->addCon(rolebut2);
	this->addCon(rolebut3);	
}
CUserGrzx::~CUserGrzx()
{
	delete this->rolebut1;
	delete this->rolebut2;
	delete this->rolebut3;
}
int CUserGrzx::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 11;
	case 1:
		return 12;
	case 2:
		return 5;
	}	
	return 10;
}