#include"CUserxx.h"

extern CUser * denglu;
extern map<string ,CUser *> userMap;//存储用户信息
extern char nownser[20];
CUserXx::CUserXx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->idlab=new CLabel(40,10,0,0,"手机号码：",LABEL);
	this->namelab=new CLabel(40,15,0,0,"姓	名：",LABEL);
	this->idnumlab=new CLabel(40,20,0,0,"身份证号：",LABEL);
	this->idedit=new CLabel(52,10,0,0,"",LABEL);
	this->tip =new CLabel(55,23,0,0,"",LABEL);


	this->nameedit=new CEdit(52,15,33,2,"",EDIT,11,4,1);
	this->idnumedit=new CEdit(52,20,33,2,"",EDIT,18,3,1);


	this->okbut=new CButton(45,27,10,2,"确  定",BUTTON);//6
	this->cancelbut=new CButton(70,27,10,2,"返  回",BUTTON);


	this->addCon(idlab);
	this->addCon(namelab);
	this->addCon(idnumlab);
	this->addCon(idedit);
	this->addCon(nameedit);
	this->addCon(idnumedit);
	this->addCon(okbut);
	this->addCon(cancelbut);
	this->addCon(tip);

}
CUserXx::~CUserXx()
{
	delete this->idlab;
	delete this->namelab;
	delete this->idnumlab;
	delete this->idedit;
	delete this->nameedit;
	delete this->idnumedit;
	delete this->okbut;
	delete this->cancelbut;
	delete this->tip;
}
int CUserXx::doAction()
{
	map<string ,CUser *>::iterator it;
	it=userMap.find(denglu->getID());
	switch(this->flag)
	{
	case 6:
		if(strlen(this->nameedit->getContext())==0||strlen(this->nameedit->getContext())<2)
			this->tip->setContext("姓名不能为空");
		else if(strlen(this->idnumedit->getContext())!=18)
			this->tip->setContext("身份证格式不正确");
		else
		{//修改信息
			it->second->setIDnum(this->idnumedit->getContext());
			it->second->setName(this->nameedit->getContext());
			denglu->setName(this->nameedit->getContext());
			strcpy(nownser,this->nameedit->getContext());
			CData::WriteUserFile();
			break;
		}
		this->nameedit->setContext(0,'\0');
		this->idnumedit->setContext(0,'\0');
		return 11;
	case 7:
		break;
	}
		this->tip->setContext(0,'\0');
		this->nameedit->setContext(0,'\0');
		this->idnumedit->setContext(0,'\0');
	return 10;
}
void CUserXx::paintWindow()
{
	this->idedit->setContext(denglu->getID());
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();
	CTool::gotoxy(50,4);
	cout<<"欢迎来到门诊预约系统 "<<endl;
	CTool::gotoxy(30,7);
	cout<<"欢迎 "<<denglu->getName()<<endl;
	CTool::gotoxy(79,7);
	cout<<"日期： "<<CTool::getTime()<<endl;
}