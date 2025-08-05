#pragma warning(disable:4786)
#include"CTool.h"
#include"CControl.h"
#include"CData.h"
#include"CButton.h"
#include"CEdit.h"
#include"CLabel.h"
#include "CUser.h"
#include"CAdmin.h"
#include"CDoctor.h"
#include "CKeshi.h"
#include"CJiuzhen.h"
#include"CWindow.h"
#include"CMainWin.h"
#include"CLoginwin.h"
#include"CSigninwin.h"
#include"CDoctorWin.h"
#include"CAdminWin.h"
#include"CUserwin.h"
#include"CUserCx.h"
#include"CDoctorCx.h"
#include"CKeshiCx.h"
#include"CDoctorNew.h"
#include"CUserxx.h"
#include"CUserGrzx.h"
#include"CUserXg.h"
#include"CUserYymain.h"
#include"CUserYy.h"
#include"CUserQh.h"
#include"CUserJzxx.h"
#include"CDoctorJjxx.h"
#include"CDoctorJzjl.h"

#include<map>
#include<iostream>
using namespace std;


int escflag=1;//�˳�����
int remain=0;//�Ƿ񷵻�������

map<string ,CUser *> userMap;//�洢�û���Ϣ
map<string ,CDoctor *> doctorMap;//�洢ҽ����Ϣ
map<string ,CAdmin *> adminMap;//�洢����Ա��Ϣ
map<string ,CKeshi *> keshiMap;//�洢������Ϣ
list<CJiuzhen *> jiuzhenList;//��ž�����Ϣ
list<CJiuzhen *>quhaoList;//���ȡ����Ϣ
list<CJiuzhen *>dyquhaoList;//���ȡ����Ϣ
map<string ,list<CDoctor *> > keshi_ysMap;//���Ҷ�Ӧҽ��

map<string ,CUser *> dyusserMap;//��Ų����û���Ϣ
map<string ,CDoctor *> dydoctorMap;//��Ų���ҽ����Ϣ
map<string ,CAdmin *> dyadminMap;//��Ŵ�ӡ����Ա��Ϣ
map<string ,CKeshi *> dykeshiMap;//��ſ�����Ϣ
list<CJiuzhen *>dyjiuzhenList;//��Ų�ѯ�ľ�����Ϣ

list<CJiuzhen *>::iterator jiuzhenit;//ѡ�еľ����û���Ϣ
list<CJiuzhen *>::iterator jzit; //ѡ��ԤԼ��Ϣ
map<string ,CDoctor *>::iterator xgit;//��¼�޸�ҽ����Ϣλ��

char nownser[20]="";//��¼��¼�û�
CUser * denglu=new CUser("","","","",0);//��¼��¼�û���Ϣ


int userPage=1;//��ǰҳ
int pageCount=0;//��ҳ
int printnum=0;//��ӡ�ĸ���

int index =0;
int main()
{
	CTool::getTime();
	CWindow * winarr[20];

	CWindow * mainWin=new CMainwin(20,1,80,30);
	CWindow * signinWin=new CSigninwin(20,1,80,30);
	CWindow * loginWin =new CLoginwin(20,1,80,30);
	CWindow * adminWin=new CAdminwin(20,1,80,30);
	CWindow * doctorWin=new CDoctorwin(20,1,80,30);
	CWindow * userWin=new CUserwin(20,1,80,30);
	CWindow * userFind=new CUserCx(20,1,80,30);
	CWindow * doctorFind =new CDoctorCx(20,1,80,30);
	CWindow * keshiFind =new CKeshiCx(20,1,80,30);
	CWindow * doctorNew =new CDoctorNew(20,1,80,30);
	CWindow *  userInformationPerfection=new CUserXx(20,1,80,30);
	CWindow * userPersonalCenter=new CUserGrzx(20,1,80,30);
	CWindow * userInformationModification=new CUserXg(20,1,80,30);
	CWindow * userReservationWin=new CUserYymain(20,1,80,30);
	CWindow * userReservation=new CUserYy(20,1,80,30);
	CWindow * userNumberAcquisition=new CUserQh(20,1,95,30);
	CWindow * userMedicalInformation=new CUserJzxx(20,1,95,30);
	CWindow * doctorMedicalInformation=new CDoctorJjxx(20,1,80,30);
	CWindow * doctorMedicalRecord=new CDoctorJzjl(20,1,80,30);

	winarr[0]=mainWin;//������
	winarr[1]=signinWin;//ע��
	winarr[2]=loginWin;//��¼
	winarr[3]=adminWin;//����Ա������
	winarr[4]=doctorWin;//ҽ��������
	winarr[5]=userWin;//�û�������
	winarr[6]=userFind;//����Ա�û���ѯ
	winarr[7]=doctorFind;//����Աҽ����ѯ
	winarr[8]=keshiFind;//����Ա���Ҳ�ѯ
	winarr[9]=doctorNew;//����Ա����ҽ��
	winarr[10]=userPersonalCenter;//�û���������
	winarr[11]=userInformationPerfection;//�û���Ϣ����
	winarr[12]=userInformationModification;//�û���Ϣ�޸�
	winarr[13]=userReservationWin;//�û�ԤԼ������
	winarr[14]=userReservation;//�û�ԤԼ
	winarr[15]=userNumberAcquisition;//�û�ȡ��
	winarr[16]=userMedicalInformation;//�û�������Ϣ
	winarr[17]=doctorMedicalInformation;//ҽ��������Ϣ
	winarr[18]=doctorMedicalRecord;//�û���¼
	
	doctorMap["d1001"]=new CDoctor("d1001","����","123456","����","�ۿ�","ʡ��ҽԺ","����",2);//ҽ��
	doctorMap["d1002"]=new CDoctor("d1002","����","123456","����ҽʦ","�ǿ�","ʡ��ҽԺ","����",2);
	doctorMap["d1003"]=new CDoctor("d1003","����","123456","������ҽʦ","����","ʡ��ҽԺ","����",2);

	adminMap["1111"]=new CAdmin("1111","123456789012345678","����Ա","123456",1);//����Ա

	userMap["12345678901"]=new CUser("12345678901","123456789012345678","����","123456",3);
	userMap["11111111111"]=new CUser("11111111111","123456789012345678","����","123456",3);


	keshiMap["1"]=new CKeshi("1","�ǿ�","����");//����
	keshiMap["2"]=new CKeshi("2","����","��ͯ");
	keshiMap["3"]=new CKeshi("3","�ۿ�","�۾�");

	quhaoList.push_back(new CJiuzhen(2,"2024-10-28","2024-10-31","","ҽԺ","�ۿ�","����","δ����","12345678901","�۾�ʹ","�����ֻ�"));//ȡ��

	jiuzhenList.push_back(new CJiuzhen(1,"2024-10-28","2024-10-31","09:00~10:00","ҽԺ","�ۿ�","����","�ȴ�����","12222222222","�۾�ʹ","�����ֻ�"));//ԤԼ

	
	CData::WriteUserFile();
	CData::WriteDoctorFile();
	CData::WriteKeshiFile();
	CData::WriteJiuzhenFile();
	CData::WriteAdminFile();
	

	while(escflag)
	{
		remain=0;
		winarr[index]->paintWindow();
		winarr[index]->winRun();
		if(remain==1)
			continue;
		index=winarr[index]->doAction();
		system("cls");
	}
	system("cls");
	cout<<"�������"<<endl;
	
	return 0;
}