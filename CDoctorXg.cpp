#include"CDoctorXg.h"

extern map<string ,CDoctor *>::iterator xgit;
CDoctorXg::CDoctorXg(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->tip=new CLabel(35,12,0,0,"��ʾ���޸�ְλ",LABEL);
	this->idlab=new CLabel(40,16,0,0,"ҽ��ID",LABEL);
	this->zwlab=new CLabel(40,20,33,2,"ְλ",LABEL);
	this->idedit=new CLabel(55,16,0,0,"",LABEL);

	this->zwbut=new CButton(50,20,33,2,"",BUTTON);//4

	this->okbut=new CButton(38,27,10,2,"ȷ��",BUTTON);
	this->cancelbut=new CButton(68,27,10,2,"ȡ��",BUTTON);

	this->addCon(tip);
	this->addCon(idlab);
	this->addCon(zwlab);
	this->addCon(idedit);
	this->addCon(zwbut);
	this->addCon(okbut);
	this->addCon(cancelbut);

	

	
}
CDoctorXg::~CDoctorXg()
{
	delete this->tip;
	delete this->idlab;
	delete this->zwlab;
	delete this->idedit;
	delete this->zwbut;
	delete this->okbut;
	delete this->cancelbut;
}
int CDoctorXg::doAction()
{
	int x,i=2;
	CWindow * doctorzw=new CDoctorZw(47,21,-1,-1);

	switch(this->flag)
	{
	case 4:
			doctorzw->paintWindow();
			doctorzw->winRun();
			x=doctorzw->doAction();
			if(x==0)//���ݷ���ֵ�ж�ְλ
				this-> zwbut->setContext("ר��");
			else if(x==1)
				this-> zwbut->setContext("����ҽʦ");
			else if(x==2)
				this-> zwbut->setContext("������ҽʦ");
			else if(x==3)
				this-> zwbut->setContext("����ҽʦ");
		return 1;	
	case 5:
		xgit->second->setZhiwei(this-> zwbut->getContext());
		return 2;
	}	
	return 0;
}

void CDoctorXg::paintWindow()
{
	this->idedit->setContext(xgit->second->getID());
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();

}
