#include"CKserror.h"

CKserror::CKserror(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->rolebut1=new CLabel(45,16,0,0,"��ʾ",LABEL);
	this->rolebut2=new CLabel(49,18,0,0,"������Ϣ�����ڣ�����������",LABEL);
	this->rolebut3=new CButton(62,22,15,2,"ȷ  ��",BUTTON);
	

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