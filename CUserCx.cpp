#pragma warning(disable:4786)
#include"CUserCx.h"
extern char nownser[20];
extern int remain;
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern map<string ,CUser *> userMap;
extern map<string ,CUser *> dyusserMap;
extern CUser * denglu;

CUserCx::CUserCx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(36,14,25,3,"",TABLE,4,2);
	this->roleidlab=new CLabel(30,10,0,0,"请输入用户账号",LABEL);
	this->zhanghaolab=new CLabel(45,14,0,0,"账号",LABEL);
	this->sfxxlab=new CLabel(68,14,0,0,"身份信息",LABEL);

	this->roleidedit=new CEdit(47,10,33,2,"",EDIT,11,3,1);
	this->cxbut =new CButton(85,10,10,2,"查  询",BUTTON);//5

	this->cancelbut=new CButton(35,27,10,2,"返  回",BUTTON);//6
	this->fylab=new CLabel(80,27,0,0,"按← →翻页",LABEL);

	this->addCon(table);
	this->addCon(roleidlab);
	this->addCon(zhanghaolab);
	this->addCon(sfxxlab);

	this->addCon(roleidedit);
	this->addCon(cxbut);
	this->addCon(cancelbut);
	this->addCon(fylab);

}
CUserCx::~CUserCx()
{
	delete this->table;
	delete this->roleidlab;
	delete this->zhanghaolab;
	delete this->sfxxlab;
	delete this->roleidedit;
	delete this->cxbut;
	delete this->cancelbut;
	delete this->fylab;
}
int CUserCx::doAction()
{

	map<string ,CUser *>::iterator it;
	switch(this->flag)
	{
	case 5:	
	it=userMap.begin();
	it=userMap.find(this->roleidedit->getContext());
	dyusserMap.erase(dyusserMap.begin(),dyusserMap.end());//清空打印容器
	if(it!=userMap.end())//精准查询
	{
		dyusserMap[it->second->getID()]=it->second;
	}
	else
	{			
		for (it=userMap.begin();it!=userMap.end();it++) 
		{
			if (strstr(it->second->getID(),this->roleidedit->getContext()) != NULL)//模糊查询
			{
				dyusserMap[it->second->getID()]=it->second;
			}
		}
	}
	break;
	case 6:
		userPage=1;
		this->roleidedit->setContext(0,'\0');
		return 3;
	}
	this->roleidedit->setContext(0,'\0');
	return 6;
}
void CUserCx::paintWindow()
{
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

	if(dyusserMap.size()==0)//添加后的容器为空 打印原始容器
	{
		CTable::showUserdata(36,14,25,3,userMap);
	}
	else
	{
		CTable::showUserdata(36,14,25,3,dyusserMap);
		dyusserMap.erase(dyusserMap.begin(),dyusserMap.end());
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


void CUserCx::winRun()
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
				rindex=this->count-1;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
			{
				rindex--;
				if(rindex<0)
					rindex=this->count-1;				
			}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			break;
		case KEY_DOWN:
			rindex++;
			if(rindex>=this->count)
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
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
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