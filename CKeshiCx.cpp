#include"CKeshiCx.h"
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern char nownser[20];//记录登录用户
extern int remain;
extern map<string ,CKeshi *> keshiMap;
extern map<string ,CKeshi *> dykeshiMap;

CKeshiCx::CKeshiCx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(40,14,15,3,"",TABLE,4,3);
	this->roleidlab=new CLabel(25,10,0,0,"请输入科室ID",LABEL);
	this->ksidlab=new CLabel(43,14,0,0,"科室ID",LABEL);
	this->ksnamelab=new CLabel(57,14,0,0,"科室姓名",LABEL);
	this->kssmlab=new CLabel(72,14,0,0,"科室说明",LABEL);

	this->roleidedit=new CEdit(40,10,33,2,"",EDIT,11,3,1);
	this->cxbut =new CButton(75,10,8,2,"查  询",BUTTON);//6
	this->xzksbut=new CButton(85,10,12,2,"新增 科室",BUTTON);//7

	this->cancelbut=new CButton(35,27,10,2,"返  回",BUTTON);//8
	this->fylab=new CLabel(80,27,0,0,"按← →翻页",LABEL);

	this->addCon(table);

	this->addCon(roleidlab);
	this->addCon(ksidlab);
	this->addCon(ksnamelab);
	this->addCon(kssmlab);

	this->addCon(roleidedit);
	this->addCon(cxbut);
	this->addCon(xzksbut);
	this->addCon(cancelbut);
	this->addCon(fylab);

	this->flag=0;

}
CKeshiCx::~CKeshiCx()
{
	delete this->table;
	delete this->roleidlab;
	delete this->ksidlab;
	delete this->ksnamelab;
	delete this->kssmlab;
	delete this->roleidedit;
	delete this->cxbut;
	delete this->xzksbut;
	delete this->cancelbut;
	delete this->fylab;
}

int CKeshiCx::doAction()
{
	map<string ,CKeshi *>::iterator it;
	CWindow * kserror =new CKserror(42,15,40,10);
	switch(this->flag)
	{
	case 6:	
	it=keshiMap.begin();
	it=keshiMap.find(this->roleidedit->getContext());
	if(it!=keshiMap.end())//找到添加到容器 无法找到打开新的类
	{
		dykeshiMap[it->second->getID()]=it->second;
	}
	else 
	{
		kserror->paintWindow();
		kserror->winRun();
		kserror->doAction();
	}
	break;
	case 8:
		userPage=1;
		this->roleidedit->setContext(0,'\0');
		return 3;
	}
	this->roleidedit->setContext(0,'\0');
	return 8;
}
void CKeshiCx::paintWindow()
{
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();

	CTool::gotoxy(50,4);
	cout<<"欢迎来到门诊预约系统 "<<endl;
	CTool::gotoxy(30,7);
	cout<<"欢迎 "<<nownser<<endl;
	CTool::gotoxy(79,7);
	cout<<"日期： "<<CTool::getTime()<<endl;

	if(dykeshiMap.size()==0)//添加的科室为空 显示容器内的科室
	{
		CTable::showKeshidata(36,14,15,3,keshiMap);
	}
	else
	{
		CTable::showKeshidata(36,14,15,3,dykeshiMap);
		dykeshiMap.erase(dykeshiMap.begin(),dykeshiMap.end());
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


void CKeshiCx::winRun()
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