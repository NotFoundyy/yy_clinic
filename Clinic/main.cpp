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


int escflag=1;//退出程序
int remain=0;//是否返回主界面

map<string ,CUser *> userMap;//存储用户信息
map<string ,CDoctor *> doctorMap;//存储医生信息
map<string ,CAdmin *> adminMap;//存储管理员信息
map<string ,CKeshi *> keshiMap;//存储科室信息
list<CJiuzhen *> jiuzhenList;//存放就诊信息
list<CJiuzhen *>quhaoList;//存放取号信息
list<CJiuzhen *>dyquhaoList;//存放取号信息
map<string ,list<CDoctor *> > keshi_ysMap;//科室对应医生

map<string ,CUser *> dyusserMap;//存放查找用户信息
map<string ,CDoctor *> dydoctorMap;//存放查找医生信息
map<string ,CAdmin *> dyadminMap;//存放打印管理员信息
map<string ,CKeshi *> dykeshiMap;//存放科室信息
list<CJiuzhen *>dyjiuzhenList;//存放查询的就诊信息

list<CJiuzhen *>::iterator jiuzhenit;//选中的就诊用户信息
list<CJiuzhen *>::iterator jzit; //选中预约信息
map<string ,CDoctor *>::iterator xgit;//记录修改医生信息位置

char nownser[20]="";//记录登录用户
CUser * denglu=new CUser("","","","",0);//记录登录用户信息


int userPage=1;//当前页
int pageCount=0;//总页
int printnum=0;//打印的个数

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

	winarr[0]=mainWin;//主界面
	winarr[1]=signinWin;//注册
	winarr[2]=loginWin;//登录
	winarr[3]=adminWin;//管理员主界面
	winarr[4]=doctorWin;//医生主界面
	winarr[5]=userWin;//用户主界面
	winarr[6]=userFind;//管理员用户查询
	winarr[7]=doctorFind;//管理员医生查询
	winarr[8]=keshiFind;//管理员科室查询
	winarr[9]=doctorNew;//管理员增加医生
	winarr[10]=userPersonalCenter;//用户个人中心
	winarr[11]=userInformationPerfection;//用户信息完善
	winarr[12]=userInformationModification;//用户信息修改
	winarr[13]=userReservationWin;//用户预约主界面
	winarr[14]=userReservation;//用户预约
	winarr[15]=userNumberAcquisition;//用户取号
	winarr[16]=userMedicalInformation;//用户就诊信息
	winarr[17]=doctorMedicalInformation;//医生就诊信息
	winarr[18]=doctorMedicalRecord;//用户记录
	
	doctorMap["d1001"]=new CDoctor("d1001","张三","123456","主任","眼科","省立医院","优秀",2);//医生
	doctorMap["d1002"]=new CDoctor("d1002","李四","123456","主治医师","鼻科","省立医院","优秀",2);
	doctorMap["d1003"]=new CDoctor("d1003","王五","123456","副主治医师","儿科","省立医院","优秀",2);

	adminMap["1111"]=new CAdmin("1111","123456789012345678","管理员","123456",1);//管理员

	userMap["12345678901"]=new CUser("12345678901","123456789012345678","李四","123456",3);
	userMap["11111111111"]=new CUser("11111111111","123456789012345678","王五","123456",3);


	keshiMap["1"]=new CKeshi("1","鼻科","鼻子");//科室
	keshiMap["2"]=new CKeshi("2","儿科","儿童");
	keshiMap["3"]=new CKeshi("3","眼科","眼睛");

	quhaoList.push_back(new CJiuzhen(2,"2024-10-28","2024-10-31","","医院","眼科","张三","未就诊","12345678901","眼睛痛","少玩手机"));//取号

	jiuzhenList.push_back(new CJiuzhen(1,"2024-10-28","2024-10-31","09:00~10:00","医院","眼科","张三","等待就诊","12222222222","眼睛痛","少玩手机"));//预约

	
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
	cout<<"程序结束"<<endl;
	
	return 0;
}