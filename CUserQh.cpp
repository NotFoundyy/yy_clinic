#include"CUserQh.h"
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>dyjiuzhenList;
extern list<CJiuzhen *>quhaoList;
extern list<CJiuzhen *>dyquhaoList;
extern list<CJiuzhen *>::iterator jzit;
static int rindex=0;
extern CUser * denglu;
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern printnum;
extern remain;
CUserQh::CUserQh(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(23,14,13,3,"",TABLE,4,7);
	this->shurulab=new CLabel(30,10,0,0,"�����������",LABEL);
	this->timeedit1=new CButton(45,10,20,2,"",BUTTON);//2
	this->timeedit2=new CButton(72,10,20,2,"",BUTTON);
	this->zhilab=new CLabel(67,10,0,0,"��",LABEL);
	this->yybhlab=new CLabel(25,14,0,0,"ԤԼ���",LABEL);
	this->yysjlab=new CLabel(38,14,0,0,"ԤԼʱ��",LABEL);
	this->yyjzsjlab=new CLabel(48,14,0,0,"ԤԼ����ʱ��",LABEL);
	this->yyyylab=new CLabel(63,14,0,0,"ԤԼҽԺ",LABEL);
	this->yykslab=new CLabel(76,14,0,0,"ԤԼ����",LABEL);
	this->yyyslab=new CLabel(89,14,0,0,"ԤԼҽ��",LABEL);
	this->jzztlab=new CLabel(102,14,0,0,"����״̬",LABEL);
	this->zyfylab=new CLabel(80,27,0,0,"���� ����ҳ",LABEL);
	this->sxfylab=new CLabel(80,28,0,0,"���� ��ѡ������",LABEL);
	
	this->cxbut =new CButton(95,10,10,2,"��  ѯ",BUTTON);//14
	this->cancelbut=new CButton(32,27,10,2,"��  ��",BUTTON);//15

	this->rolebtu1=new CButton(22,18,-1,-1,"1",BUTTON);//16
	this->rolebtu2=new CButton(22,21,-1,-1,"1",BUTTON);
	this->rolebtu3=new CButton(22,24,-1,-1,"1",BUTTON);
	
	this->addCon(table);
	this->addCon(shurulab);
	this->addCon(timeedit1);
	this->addCon(timeedit2);
	this->addCon(zhilab);
	this->addCon(yybhlab);
	this->addCon(yysjlab);
	this->addCon(yyjzsjlab);
	this->addCon(yyyylab);
	this->addCon(yykslab);
	this->addCon(yyyslab);
	this->addCon(jzztlab);
	this->addCon(zyfylab);
	this->addCon(sxfylab);
	this->addCon(cxbut);
	this->addCon(cancelbut);

	this->addCon(rolebtu1);
	this->addCon(rolebtu2);
	this->addCon(rolebtu3);
}
CUserQh::~CUserQh()
{
	delete this->table;
	delete this->shurulab;
	delete this->timeedit1;
	delete this->timeedit2;
	delete this->zhilab;
	delete this->yybhlab;
	delete this->yysjlab;
	delete this->yyyylab;
	delete this->yykslab;
	delete this->yyyslab;
	delete this->jzztlab;
	delete this->zyfylab;
	delete this->sxfylab;
	delete this->cxbut;
	delete this->cancelbut;
	delete this->rolebtu1;
	delete this->rolebtu2;
	delete this->rolebtu3;


	
}
int CUserQh::doAction()
{
	if(this->flag==14)
	{
		list<char *> timelist;
		list<char *>::iterator timeit;
		list<CJiuzhen *> ::iterator it;
		timelist=CTool::getChaxun(this->timeedit1->getContext(),this->timeedit2->getContext());
		dyquhaoList.erase(dyquhaoList.begin(),dyquhaoList.end());
		for(it=quhaoList.begin();it!=quhaoList.end();it++)//����ѯʱ���ڵ���Ϣ��ӵ�������
		{
			for(timeit=timelist.begin();timeit!=timelist.end();timeit++)
			{				
				if(strcmp((*it)->getJztime(),(*timeit))==0)
				{
					dyquhaoList.push_back(*it);					
				}
			}
		}
		return 15;
	}
	else if(this->flag==15)
	{
		this->timeedit1->setContext(" ");
		this->timeedit2->setContext(" ");
		dyquhaoList.erase(dyquhaoList.begin(),dyquhaoList.end());
		return 5;
	}
	else if(this->flag==2)
	{
		CButton *arr[10]={0};
		int esc=1,count=0;
		for(int i=0;i<7;i++)
		{
			arr[i]=new CButton(45,12+i*2,18,2,CTool::getTime(i),BUTTON);//���ƽ�����7��İ�ť
			arr[i]->show();
			count++;
		}
		CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
		while(esc)
		{
			int ikey=CTool::getKey();
			switch(ikey)
			{
			case KEY_UP:
				rindex--;
				if(rindex<0)
					rindex=count-1;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_DOWN:
				rindex++;
				if(rindex>=count)
					rindex=0;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_ESC:
				return 16;
			case KEY_ENTER:
					esc=0;
					break;

			}
		}
		this->timeedit1->setContext(arr[rindex]->getContext());
		return 15;
	}
	else if(this->flag==3)//��ѡ�����ں��濪ʼ����
	{
		CButton *arr[10]={0};
		int esc=1,count=0,x=rindex,xunhuan=7-rindex;
		for(int i=0;i<xunhuan;i++)
		{
			
			arr[i]=new CButton(72,12+i*2,18,2,CTool::getTime(x),BUTTON);
			arr[i]->show();
			count++;
			x++;
		}
		rindex=0;
		CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
		
		while(esc)//ѡ��ť
		{
			int ikey=CTool::getKey();
			switch(ikey)
			{
			case KEY_UP:
				rindex--;
				if(rindex<0)
					rindex=count-1;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_DOWN:
				rindex++;
				if(rindex>=count)
					rindex=0;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_ESC:
				return 16;
			case KEY_ENTER:
					esc=0;
					break;
			}
		}
		this->timeedit2->setContext(arr[rindex]->getContext());
		return 15;
	}
	else if(this->flag==16)//��������ָ������
	{
		jzit=dyquhaoList.begin();
		for(int i=0;i<(userPage-1)*3;i++)
			jzit++;
	}
	else if(this->flag==17)
	{
		jzit=dyquhaoList.begin();
		for(int i=0;i<(userPage-1)*3+1;i++)
			jzit++;
	}
	else if(this->flag==18)
	{
		jzit=dyquhaoList.begin();
		for(int i=0;i<(userPage-1)*3+2;i++)
			jzit++;
	}
	CWindow *xg=new CUserQhxg(40,12,50,15);
	xg->paintWindow();
	xg->winRun();
	xg->doAction();
	return 15;
}
	
void CUserQh::paintWindow()
{
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<16;i++)
		this->arr[i]->show();

	CTool::gotoxy(50,4);
	cout<<"��ӭ��������ԤԼϵͳ "<<endl;
	CTool::gotoxy(30,7);
	cout<<"��ӭ "<<denglu->getName()<<endl;
	CTool::gotoxy(79,7);
	cout<<"���ڣ� "<<CTool::getTime()<<endl;

	CTable::showQuhaodata(36,14,13,3);
	

	if(fanyetip==1)//��ӡ��ҳ��ʾ
	{
		CTool::gotoxy(55,27);
		cout<<"�Ѿ��ǵ�һҳ��"<<endl;
	}
	else if(fanyetip==2)
	{
		CTool::gotoxy(55,27);
		cout<<"�Ѿ���ĩβҳ��"<<endl;
	}

	fanyetip=0;
}

void CUserQh::winRun()
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
				rindex=15+printnum;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
			{
				rindex--;
				if(rindex<0)
					rindex=15+printnum;				
			}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			break;
		case KEY_DOWN:
			rindex++;
			if(rindex>=16+printnum)
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