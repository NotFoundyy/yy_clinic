#include"CUserQhxg.h"
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>::iterator jzit;
extern list<CJiuzhen *>quhaoList;
CUserQhxg::CUserQhxg(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->tip1lab=new CLabel(35,12,0,0,"��ʾ",LABEL);
	this->tip2lab=new CLabel(53,16,0,0,"��ǰ�����Ŷ�����   �ˣ�����",LABEL);

	this->qhbut=new CButton(44,22,12,2,"ȡ��",BUTTON);//2
	this->qxqhbut=new CButton(60,22,12,2,"ȡ��ԤԼ",BUTTON);//3
	this->cancelbut=new CButton(76,22,12,2,"ȡ��",BUTTON);

	this->addCon(tip1lab);
	this->addCon(tip2lab);
	this->addCon(qhbut);
	this->addCon(qxqhbut);
	this->addCon(cancelbut);
	

	
}
CUserQhxg::~CUserQhxg()
{
	delete this->tip1lab;
	delete this->tip2lab;
	delete this->qhbut;
	delete this->qxqhbut;
	delete this->cancelbut;
}
int CUserQhxg::doAction()
{
	switch(this->flag)
	{
	case 2://ȡ��
		jiuzhenList.push_front(*jzit);
		(*jzit)->setZhuangtai("�ȴ�����");
		quhaoList.erase(jzit);
		break;
	case 3:
		if(strcmp(CTool::getTime(),(*jzit)->getJztime())==0)//ʱ�䲻��24Сʱ������ȡ��ԤԼ
		{
			CTool::gotoxy(63,25);
			cout<<"ȡ��ʧ��"<<endl;
			getch();
		}
		else 
			(*jzit)->setZhuangtai("��ȡ��");
	}
	return 0;
}

void CUserQhxg::paintWindow()
{
	
	
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	
	for(int i=0;i<this->count;i++)
		this->arr[i]->show();
	CTool::gotoxy(71,17);
	cout<<jiuzhenList.size()<<endl;

}