#include"CUserxx.h"

extern CUser * denglu;
extern map<string ,CUser *> userMap;//�洢�û���Ϣ
extern char nownser[20];
CUserXx::CUserXx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->idlab=new CLabel(40,10,0,0,"�ֻ����룺",LABEL);
	this->namelab=new CLabel(40,15,0,0,"��	����",LABEL);
	this->idnumlab=new CLabel(40,20,0,0,"���֤�ţ�",LABEL);
	this->idedit=new CLabel(52,10,0,0,"",LABEL);
	this->tip =new CLabel(55,23,0,0,"",LABEL);


	this->nameedit=new CEdit(52,15,33,2,"",EDIT,11,4,1);
	this->idnumedit=new CEdit(52,20,33,2,"",EDIT,18,3,1);


	this->okbut=new CButton(45,27,10,2,"ȷ  ��",BUTTON);//6
	this->cancelbut=new CButton(70,27,10,2,"��  ��",BUTTON);


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
			this->tip->setContext("��������Ϊ��");
		else if(strlen(this->idnumedit->getContext())!=18)
			this->tip->setContext("���֤��ʽ����ȷ");
		else
		{//�޸���Ϣ
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
	cout<<"��ӭ��������ԤԼϵͳ "<<endl;
	CTool::gotoxy(30,7);
	cout<<"��ӭ "<<denglu->getName()<<endl;
	CTool::gotoxy(79,7);
	cout<<"���ڣ� "<<CTool::getTime()<<endl;
}