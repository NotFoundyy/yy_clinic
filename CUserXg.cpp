#include"CUserXg.h"

extern CUser * denglu;
extern map<string ,CUser *> userMap;//存储用户信息
CUserXg::CUserXg(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->idlab=new CLabel(40,10,0,0,"手机号码：",LABEL);
	this->oldmimalab=new CLabel(40,14,0,0,"原密码：",LABEL);
	this->newmimalab=new CLabel(40,18,0,0,"新密码：",LABEL);
	this->renewmimalab=new CLabel(40,22,0,0,"确认密码：",LABEL);
	this->idedit=new CLabel(52,10,33,2,"",LABEL);

	this->oldmimaedit=new CEdit(52,14,33,2,"",EDIT,6,3,2);
	this->newmimaedit=new CEdit(52,18,33,2,"",EDIT,6,3,2);
	this->renewmimaedit=new CEdit(52,22,33,2,"",EDIT,6,3,2);


	this->okbut=new CButton(45,27,10,2,"确  定",BUTTON);//8
	this->cancelbut=new CButton(70,27,10,2,"返  回",BUTTON);

	this->tip =new CLabel(55,25,0,0,"",LABEL);


	this->addCon(idlab);
	this->addCon(oldmimalab);
	this->addCon(newmimalab);
	this->addCon(renewmimalab);
	this->addCon(idedit);
	this->addCon(oldmimaedit);
	this->addCon(newmimaedit);
	this->addCon(renewmimaedit);
	this->addCon(okbut);
	this->addCon(cancelbut);
	this->addCon(tip);


}
CUserXg::~CUserXg()
{
	delete this->idlab;
	delete this->oldmimalab;
	delete this->newmimalab;
	delete this->renewmimalab;
	delete this->idedit;
	delete this->oldmimaedit;
	delete this->newmimaedit;
	delete this->renewmimaedit;
	delete this->okbut;
	delete this->cancelbut;
	delete this->tip;
}
int CUserXg::doAction()
{
	map<string ,CUser *>::iterator it;
	it=userMap.find(denglu->getID());
	switch(this->flag)
	{
	case 8:
		if((strcmp(denglu->getMima(),this->oldmimaedit->getContext())==0)&&
			(strcmp(this->newmimaedit->getContext(),this->renewmimaedit->getContext())==0)&&
			(strcmp(this->oldmimaedit->getContext(),this->newmimaedit->getContext())==1))
		{//存储信息
			it->second->setMima(this->newmimaedit->getContext());
			CData::WriteUserFile();
			this->tip->setContext(0,'\0');
			this->oldmimaedit->setContext(0,'\0');
			this->newmimaedit->setContext(0,'\0');
			this->renewmimaedit->setContext(0,'\0');
			CTool::gotoxy(50,25);
			cout<<"修改成功"<<endl;
			getch();
			return 2;
		}
		else if(strlen(this->newmimaedit->getContext())==0)
		{
			this->tip->setContext("密码不能为空");	
		}
		else if(strcmp(this->oldmimaedit->getContext(),this->newmimaedit->getContext())==0)
		{
			this->tip->setContext("新密码和旧密码不能重复");	
		}
		else if(strcmp(denglu->getMima(),this->oldmimaedit->getContext())==1)
		{
			this->tip->setContext("旧密码错误");	
		}
		this->oldmimaedit->setContext(0,'\0');
		this->newmimaedit->setContext(0,'\0');
		this->renewmimaedit->setContext(0,'\0');		
		return 12;
	case 9:
			this->tip->setContext(0,'\0');
			this->oldmimaedit->setContext(0,'\0');
			this->newmimaedit->setContext(0,'\0');
			this->renewmimaedit->setContext(0,'\0');
		return 10;
	}
	return 12;
}
void CUserXg::paintWindow()
{
	this->idedit->setContext(denglu->getID());
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
