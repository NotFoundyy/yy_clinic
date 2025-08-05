#include"CDoctorNew.h"
extern map<string ,CDoctor *> doctorMap;
extern char nownser[20];
CDoctorNew::CDoctorNew(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->ysidlab=new CLabel(38,8,0,0,"医生ID：",LABEL);
	this->ysnamelab=new CLabel(38,11,0,0,"医生姓名：",LABEL);
	this->ssyylab=new CLabel(38,14,0,0,"所属医院：",LABEL);
	this->sskslab=new CLabel(38,17,0,0,"所属科室：",LABEL);
	this->yszwlab=new CLabel(38,20,0,0,"医生职位：",LABEL);
	this->ysjjlab=new CLabel(38,23,0,0,"简   介：",LABEL);
	this-> ysidedit=new CLabel(50,8,0,0,"",LABEL);

	this-> ysnameedit=new CEdit(50,11,33,2,"",EDIT,10,4,1);
	this-> ssyyedit=new CLabel(50,14,0,0,"省立医院",LABEL);
	this-> ssksedit=new CButton(50,17,33,2,"		↓",BUTTON);//9
	this-> yszwedit=new CButton(50,20,33,2,"		↓",BUTTON);//10
	this-> ysjjedit=new CEdit(50,23,33,3,"",EDIT,15,4,1);

	this->okbut=new CButton(37,27,10,2,"确  定",BUTTON); //12
	this->cancelbut=new CButton(75,27,10,2,"返  回",BUTTON);

	this->tip =new CLabel(55,25,0,0,"",LABEL);

	this->addCon(ysidlab);
	this->addCon(ysnamelab);
	this->addCon(ssyylab);
	this->addCon(sskslab);
	this->addCon(yszwlab);
	this->addCon(ysjjlab);
	this->addCon(ysidedit);
	this->addCon(ysnameedit);
	this->addCon(ssyyedit);
	this->addCon(ssksedit);
	this->addCon(yszwedit);
	this->addCon(ysjjedit);
	this->addCon(okbut);
	this->addCon(cancelbut);
	this->addCon(tip);
}
CDoctorNew::~CDoctorNew()
{
	delete this->ysidlab;
	delete this->ysnamelab;
	delete this->ssyylab;
	delete this->sskslab;
	delete this->yszwlab;
	delete this->ysjjlab;
	delete this->ysidedit;
	delete this->ysnameedit;
	delete this->ssyyedit;
	delete this->ssksedit;
	delete this->yszwedit;
	delete this->ysjjedit;
	delete this->okbut;
	delete this->cancelbut;
	delete this->tip;
}
int CDoctorNew::doAction()
{
	CWindow * doctorzw=new CDoctorZw(47,21,-1,-1);
	CWindow * doctorksxl=new CDoctorKsxl(47,21,-1,-1);
	int x=0;
	switch(this->flag)
	{
	case 9:
		doctorksxl->paintWindow();
		doctorksxl->winRun();
		x=doctorksxl->doAction();
		if(x==0)//根据返回值判断选择的什么科室
			this-> ssksedit->setContext("眼  科");
		else if(x==1)
			this-> ssksedit->setContext("鼻  科");
		else if(x==2)
			this-> ssksedit->setContext("儿  科");
		return 9;
	case 10:
		doctorzw->paintWindow();
		doctorzw->winRun();
		x=doctorzw->doAction();
		if(x==0)//根据返回值判断职位
			this-> yszwedit->setContext("专家");
		else if(x==1)
			this-> yszwedit->setContext("主任医师");
		else if(x==2)
			this-> yszwedit->setContext("副主任医师");
		else if(x==3)
			this-> yszwedit->setContext("主治医师");
		return 9;
	case 12:
		if(strlen(this->ysnameedit->getContext())>=2&&strlen(this->ysjjedit->getContext())!=0)
		{
			doctorMap[this->ysidedit->getContext()]=new CDoctor(this->ysidedit->getContext(),this->ysnameedit->getContext(),"123456",
				this->yszwedit->getContext(),this->ssksedit->getContext(),"省立医院",this->ysjjedit->getContext(),2);
			CData::WriteDoctorFile();
			this->ysnameedit->setContext(0,'\0');
			this-> ssksedit->setContext(0,'\0');
			this-> yszwedit->setContext(0,'\0');
			this-> ysjjedit->setContext(0,'\0');
			return 7;
		}
		else if(strlen(this->ysjjedit->getContext())==0)
			this->tip->setContext("简介不能为空");
		this->ysnameedit->setContext(0,'\0');
		this-> ssksedit->setContext(0,'\0');
		this-> yszwedit->setContext(0,'\0');
		this-> ysjjedit->setContext(0,'\0');
			return 9;
	case 13:
		this->ysnameedit->setContext(0,'\0');
		this-> ssksedit->setContext(0,'\0');
		this-> yszwedit->setContext(0,'\0');
		this-> ysjjedit->setContext(0,'\0');
		return 7;
	}
	return 9;
}
void CDoctorNew::paintWindow()
{
	int i;
	char buf[20];
	int num=doctorMap.size()+1001;
	sprintf(buf,"d%d",num);
	this->ysidedit->setContext(buf);
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();
		CTool::gotoxy(50,4);
		cout<<"欢迎来到门诊预约系统 "<<endl;
		CTool::gotoxy(30,7);
		cout<<"欢迎 "<<nownser<<endl;
		CTool::gotoxy(79,7);
		cout<<"日期： "<<CTool::getTime()<<endl;
}