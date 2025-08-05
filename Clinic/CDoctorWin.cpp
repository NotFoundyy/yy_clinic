#include"CDoctorWin.h"
extern char nownser[20];

CDoctorwin::CDoctorwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{


	this->rolebut=new CButton(35,12,20,2,"个 人 中 心",BUTTON);
	this->querybut=new CButton(65,12,20,2,"就 诊 信 息 查 询",BUTTON);
	this->cancelbut=new CButton(35,19,20,2,"退  出",BUTTON);


	this->addCon(rolebut);
	this->addCon(querybut);
	this->addCon(cancelbut);




}
CDoctorwin::~CDoctorwin()
{
	delete this->rolebut;
	delete this->querybut;
	delete this->cancelbut;
}
int CDoctorwin::doAction()
{
	switch(this->flag)
	{
	case 1:
		return 17;
		case 2:
			return 0;
	}
	return 4;
}