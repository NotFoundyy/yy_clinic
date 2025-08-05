#include"CKserror.h"

CKserror::CKserror(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->rolebut1=new CLabel(45,16,0,0,"提示",LABEL);
	this->rolebut2=new CLabel(49,18,0,0,"科室信息不存在，请重新输入",LABEL);
	this->rolebut3=new CButton(62,22,15,2,"确  定",BUTTON);
	

	this->addCon(rolebut1);
	this->addCon(rolebut2);
	this->addCon(rolebut3);

	
}
CKserror::~CKserror()
{
	delete this->rolebut1;
	delete this->rolebut2;
	delete this->rolebut3;
}
int CKserror::doAction()
{
	return 0;
}