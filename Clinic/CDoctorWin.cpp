#include"CDoctorWin.h"
extern char nownser[20];

CDoctorwin::CDoctorwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{


	this->rolebut=new CButton(35,12,20,2,"�� �� �� ��",BUTTON);
	this->querybut=new CButton(65,12,20,2,"�� �� �� Ϣ �� ѯ",BUTTON);
	this->cancelbut=new CButton(35,19,20,2,"��  ��",BUTTON);


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