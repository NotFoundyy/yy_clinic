#include"CDoctorCx.h"

extern map<string ,CDoctor *> doctorMap;
extern map<string ,CDoctor *> dydoctorMap;
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern char nownser[20];//记录登录用户
extern int remain;
extern printnum;
extern map<string ,CDoctor *>::iterator xgit;
CDoctorCx::CDoctorCx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(30,14,11,3,"",TABLE,4,6);
	this->roleidlab=new CLabel(30,10,0,0,"请输入医生ID",LABEL);
	this->ysidlab=new CLabel(32,14,0,0,"医生ID",LABEL);
	this->ysnamelab=new CLabel(42,14,0,0,"医生姓名",LABEL);
	this->zhiweilab=new CLabel(54,14,0,0,"职位",LABEL);
	this->keshilab=new CLabel(63,14,0,0,"所属科室",LABEL);
	this->yiyuanlab=new CLabel(74,14,0,0,"所属医院",LABEL);
	this->jianjielab=new CLabel(87,14,0,0,"简介",LABEL);

	this->roleidedit=new CEdit(47,10,33,2,"",EDIT,11,3,1);
	this->cxbut =new CButton(85,10,10,2,"查  询",BUTTON);//9

	this->cancelbut=new CButton(35,27,10,2,"返  回",BUTTON);//10
	this->zyfylab=new CLabel(80,27,0,0,"按← →翻页",LABEL);
	this->sxfylab=new CLabel(80,28,0,0,"按↑ ↓选择数据",LABEL);

	this->rolebtu1=new CButton(25,17,-1,-1,"☆",BUTTON);//13
	this->rolebtu2=new CButton(25,20,-1,-1,"☆",BUTTON);
	this->rolebtu3=new CButton(25,23,-1,-1,"☆",BUTTON);


	this->addCon(table);

	this->addCon(roleidlab);
	this->addCon(ysidlab);
	this->addCon(ysnamelab);
	this->addCon(zhiweilab);
	this->addCon(keshilab);
	this->addCon(yiyuanlab);
	this->addCon(jianjielab);

	this->addCon(roleidedit);
	this->addCon(cxbut);
	this->addCon(cancelbut);
	this->addCon(zyfylab);
	this->addCon(sxfylab);

	this->addCon(rolebtu1);
	this->addCon(rolebtu2);
	this->addCon(rolebtu3);

}
CDoctorCx::~CDoctorCx()
{
	delete this->table;
	delete this->roleidlab;
	delete this->ysidlab;
	delete this->ysnamelab;
	delete this->zhiweilab;
	delete this->keshilab;
	delete this->yiyuanlab;
	delete this->jianjielab;
	delete this->roleidedit;
	delete this->cxbut;
	delete this->cancelbut;
	delete this->zyfylab;
	delete this->sxfylab;
	delete this->rolebtu1;
	delete this->rolebtu2;
	delete this->rolebtu3;
}

int CDoctorCx::doAction()
{
	map<string ,CDoctor *>::iterator it;
	CWindow * xiala=new CDoctorXl(42,12,40,14);
	CWindow * doctorxg=new CDoctorXg(30,12,60,20);
	int x,i=0;
	if(dydoctorMap.size()==0)
		xgit=doctorMap.begin();
	else
		xgit=dydoctorMap.begin();
	switch(this->flag)
	{
	case 9:
	it=doctorMap.begin();
	it=doctorMap.find(this->roleidedit->getContext());
	dydoctorMap.erase(dydoctorMap.begin(),dydoctorMap.end());
	if(it!=doctorMap.end())//精准查询
	{
		dydoctorMap[it->second->getID()]=it->second;
		this->roleidedit->setContext(0,'\0');
	}
	else//查询不到 添加医生
	{	
		xiala->paintWindow();
		xiala->winRun();
		x=xiala->doAction();
		if(x==1)
		{
			this->roleidedit->setContext(0,'\0');
			return 7;
		}else if(x==2)
		{
			this->roleidedit->setContext(0,'\0');
			return 9;
		}	
	}
	return 7; 
	case 10:
		userPage=1;
		this->roleidedit->setContext(0,'\0');
		dydoctorMap.erase(dydoctorMap.begin(),dydoctorMap.end());
		return 3;
		
	case 13: //将迭代器指到要更改信息的位置

		advance(xgit,((userPage-1)*3));
		break;		
	case 14:
		advance(xgit,((userPage-1)*3+1));
		break;
	case 15:
		advance(xgit,((userPage-1)*3+2));
		//for( i=0;i<(userPage-1)*3+2;i++)
		//	xgit++;
		break;
	}
	a://修改过一次之后就退出
		doctorxg->paintWindow();
		doctorxg->winRun();
		x=doctorxg->doAction();
		if(x==1)
			goto a;
	this->roleidedit->setContext(0,'\0');
	return 7;
}


void CDoctorCx::paintWindow()//重写打印
{
		int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<=12;i++)
		this->arr[i]->show();
	
	CTool::gotoxy(50,4);
	cout<<"欢迎来到门诊预约系统 "<<endl;
	CTool::gotoxy(30,7);
	cout<<"欢迎 "<<nownser<<endl;
	CTool::gotoxy(79,7);
	cout<<"日期： "<< CTool::getTime()<<endl;

	if(dydoctorMap.size()==0)//打印数据
	{
		CTable::showDocterdata(28,14,11,3,doctorMap);
	}
	else
	{
		CTable::showDocterdata(28,14,11,3,dydoctorMap);
				
	}	

	if(fanyetip==1)//打印翻页提示
	{
		CTool::gotoxy(55,27);
		cout<<"已经是第一页了"<<endl;
	}
	else if(fanyetip==2)
	{
		CTool::gotoxy(55,27);
		cout<<"已经是末尾页了"<<endl;
	}

	fanyetip=0;
}


void CDoctorCx::winRun()
{
	int rindex=0;
	CEdit * edit=NULL;
	for(int i=0;i<=this->count;i++)
		if(this->arr[i]->getType()==EDIT||this->arr[i]->getType()==BUTTON)
		{
			rindex =i;
			break;
		}
	if(this->arr[rindex]->getType()==EDIT)
		CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
	else if(this->arr[rindex]->getType()==BUTTON)
		CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
	while(1)
	{
		int ikey=CTool::getKey();
		switch(ikey)
		{
		case KEY_UP:
			rindex--;
			if(rindex<0)
				rindex=12+printnum;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
			{
				rindex--;
				if(rindex<0)
					rindex=12+printnum;				
			}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
			{
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
				
			}
			break;
		case KEY_DOWN:
			rindex++;
			if(rindex>12+printnum)
				rindex=0;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
				{
					if(rindex<this->count-1)
						rindex++;
					else 
						rindex=0;
				}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
			{
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			}
			break;
		case KEY_ESC:
			this->escMain();
			return;
		case KEY_ENTER:
			if(this->arr[rindex]->getType()==BUTTON)
			{
				this->flag=rindex;
				return;
			}
			if(this->arr[rindex]->getType()==EDIT)
			{
				rindex++;
				if(rindex>=this->count)
				rindex=0;
				while(this->arr[rindex]->getType()==LABEL)
				{
					if(rindex<this->count-1)
						rindex++;
					else 
						rindex=0;
				}
				if(this->arr[rindex]->getType()==EDIT)
					CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
				else if(this->arr[rindex]->getType()==BUTTON)
					CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			}
			break;
			case KEY_LEFT:	
					if(userPage<=1)
					{
						fanyetip=1;			
					}
					else 
					{
						userPage--;
						fanyetip=0;
					}
				remain=1;
				return ;
			case KEY_RIGHT:
					if(userPage>=pageCount)
					{
						fanyetip=2;		
					}
					else
					{
						userPage++;
						fanyetip=0;
					}
				remain=1;
				return ;
		default:
			if(this->arr[rindex]->getType()==EDIT)
			{
				edit =(CEdit *)(this->arr[rindex]);
				edit->inputControl(ikey);
			}
			break;
		}
	}
}
