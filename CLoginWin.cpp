#pragma warning(disable:4786)
#include"CLoginwin.h"
#include"Cxiala.h"

extern map<string ,CUser *> userMap;//存储用户信息
extern map<string ,CDoctor *> doctorMap;//存储医生信息
extern map<string ,CAdmin *> adminMap;//存储管理员信息

extern char nownser[20];
extern CUser * denglu;

CLoginwin::CLoginwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->title= new CLabel(55,3,0,0,"登录界面",LABEL);
	this->accountlab=new CLabel(35,7,0,0,"账  号",LABEL);
	this->passwordlab=new CLabel(35,12,0,0,"密   码",LABEL);
	this->rolelab=new CLabel(35,17,0,0,"角  色",LABEL);

	this->accountledit=new CEdit(47,7,33,2,"",EDIT,11,3,1);
	this->passwordedit=new CEdit(47,12,33,2,"",EDIT,10,3,0);
	
	this->rolebut=new CButton(47,17,33,2,"普 通  用 户↓",BUTTON);//6
	this->loginbut= new CButton(35,26,10,2,"登  录",BUTTON);//7
	this->cancelbut=new CButton(74,26,10,2,"返  回",BUTTON);

	this->tip=new CLabel(55,20,0,0,"",LABEL);



	this->addCon(title);
	this->addCon(accountlab);
	this->addCon(passwordlab);
	this->addCon(rolelab);
	this->addCon(accountledit);
	this->addCon(passwordedit);
	this->addCon(rolebut);
	this->addCon(loginbut);
	this->addCon(cancelbut);
	this->addCon(tip);
}
CLoginwin::~CLoginwin()
{
	delete this->title;
	delete this->accountlab;
	delete this->passwordlab;
	delete this->rolelab;
	delete this->accountledit;
	delete this->passwordedit;
	delete this->rolebut;
	delete this->loginbut;
	delete this->cancelbut;
	delete this->tip;
}
int CLoginwin::doAction()
{
	CWindow * xiala=new CXiala(47,21,0,0);
	int x;
	switch(this->flag)
	{
	case 6:
		xiala->paintWindow();
		xiala->winRun();
		x=xiala->doAction();
		if(x==0)//根据返回值判断选定身份
			this->rolebut->setContext("管 理 员↓");
		else if(x==1)
			this->rolebut->setContext("医  生↓");
		else if(x==2)
			this->rolebut->setContext("普 通  用 户↓");
		this->tip->setContext(0,'\0');
		this->passwordedit->setContext(0,'\0');
		
			return 2;
	case 7:
		return loginCheck();
	case 8://初始化
		this->rolebut->setContext("普 通  用 户↓");
		this->tip->setContext(0,'\0');
		this->accountledit->setContext(0,'\0');
		this->passwordedit->setContext(0,'\0');
		return 0;
	}
	return 2;

}
int CLoginwin::loginCheck()
{
	int i=0,errornum=0,flag=2;
	map<string,CUser *>::iterator userit;
	map<string,CDoctor *>::iterator doctorit;
	map<string,CAdmin *>::iterator adminit;

	if(strlen(this->accountledit->getContext())!=0&&strlen(this->passwordedit->getContext())!=0
		&&strcmp(this->rolebut->getContext(),"管 理 员↓")==0)
	{		
		for(adminit=adminMap.begin();adminit!=adminMap.end();adminit++)//遍历判断账号和密码是否对应
		{	
			if(strcmp(adminit->second->getID(),this->accountledit->getContext())==0)
			{
				if(strcmp(adminit->second->getMima(),this->passwordedit->getContext())==0)
				{	
					if(adminit->second->getRole()==1)//管理员
					{
						flag= 3;						
					}
					strcpy(nownser,adminit->second->getName());
				}
				else
					this->tip->setContext("账号或密码错误");
			}
			else 
				this->tip->setContext("账号或密码错误");
		}//管理员if
	}
	else if(strlen(this->accountledit->getContext())!=0&&strlen(this->passwordedit->getContext())!=0
	&&strcmp(this->rolebut->getContext(),"医  生↓")==0)
	{
		for(doctorit=doctorMap.begin();doctorit!=doctorMap.end();doctorit++)//遍历判断账号和密码是否对应
		{	
			if(strcmp(doctorit->second->getID(),this->accountledit->getContext())==0)
			{
				if(strcmp(doctorit->second->getMima(),this->passwordedit->getContext())==0)
				{	
					if(doctorit->second->getRole()==2)//医生
					{
						flag= 4;
					}
					strcpy(nownser,doctorit->second->getName());
				}
				else
					this->tip->setContext("账号或密码错误");
			}
			else 
				this->tip->setContext("账号或密码错误");
		}
	}//医生if
	else if(strlen(this->accountledit->getContext())!=0&&strlen(this->passwordedit->getContext())!=0
	&&strcmp(this->rolebut->getContext(),"普 通  用 户↓")==0)
	{
		for(userit=userMap.begin();userit!=userMap.end();userit++)//遍历判断账号和密码是否对应
		{	
			if(strcmp(userit->second->getID(),this->accountledit->getContext())==0)
			{
				if(strcmp(userit->second->getMima(),this->passwordedit->getContext())==0)
				{	
					if(userit->second->getRole()==3)//普通用户
					{
						flag= 5;
					}
					strcpy(nownser,userit->second->getName());//将数据存起来
					denglu->setID(userit->second->getID());
					denglu->setIDnum(userit->second->getIDnum());
					denglu->setName(userit->second->getName());
					denglu->setMima(userit->second->getMima());
					denglu->setRole(userit->second->getRole());
				}
				else 
				this->tip->setContext("账号或密码错误");
			}
			else 
				this->tip->setContext("账号或密码错误");
		}
	}//普通用户if
	else
	{
		this->tip->setContext("账号或密码不能为空");
		flag=2;
	}
	if(flag==3||flag==4||flag==5)
		this->tip->setContext(0,'\0');//登录成功 清除错误信息
	this->accountledit->setContext(0,'\0');
	this->passwordedit->setContext(0,'\0');
	return flag;
}