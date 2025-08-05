#include "cTool.h"
#include "cLoginWin.h"
#include "cRegisterWin.h"
#include "cInitWin.h"
#include "cLoginChoseWin.h"
#include "cAdminWin.h"
#include "cDoctorWin.h"
#include "cUserWin.h"
#include "cAdminLoginWin.h"
#include "cDoctorLoginWin.h"
#include "cUserLoginWin.h"
#include "cUserQueryWin.h"
#include "cList.h"
#include "cFile.h"
#include "cDoctorManWin.h"
#include "cNewDoctorWin.h"
#include "cClassQueryWin.h"
#include "cUserCenterWin.h"
#include "cUserImproveWin.h"
#include "cChangePwdWin.h"
#include "cUserOrderWin.h"
#include "cClinic.h"

//�û��ṹ������
USER arr[10] = {
	{"admin","123456",1},
	{"1001","abc123",2},
	{"1002","abc123",2},
	{"yy","021323",3},
};
//ҽ���ṹ������
DOC doc[10] = {
	{"1001","����","����","���","һԺ","ţ"},
	{"1002","����","������","�ڿ�","һԺ","��"},
	{"1003","����","ҽʦ","�ǿ�","��Ժ","6"},
	{"1004","����","ʵϰ","�Կ�","��Ժ","��"},
};
//���ҽṹ������
CLA cla[10] = {
	{"1001","���","ţ"},
	{"1002","�ڿ�","��"},
	{"1003","�ǿ�","6"},
	{"1004","�Կ�","��"},
};

int userNum = 4;
int docNum = 4;
int claNum = 4;
int res = 0;

LIST * accList;
LIST * docList;
LIST * claList;

//����ָ������
int (*functionArr[20])() = {
	InitWin_init,//��ʼ0
	RegisterWin_init, //ע��1
	LoginWin_init, //��¼2
	LoginChoseWin_init,//������3
	AdminWin_init, //����Ա4
	DoctorWin_init, //ҽ��5
	UserWin_init, //�û�6
	AdminLoginWin_init,//����Ա��¼7
	DoctorLoginWin_init,//ҽ����¼8
	UserLoginWin_init,//�û���¼9
	userQueryWin_init,//�û���ѯ10
	doctorManWin_init,//ҽ������11
	NewDoctorWin_init,//����ҽ��12
	classQueryWin_init,//���Ҳ�ѯ13
	UserCenterWin_init,//��������14
	UserImproveWin_init,//��Ϣ����15
	ChangePwdWin_init,//�޸�����16
	UserOrderWin_init,//�û�ԤԼ17
	clinic_init,//������Ϣ18
//	NULL, //��������
};

int main(){
	FILE * accFp =NULL;
	accFp = file_open("./data/user.txt");
	accList = readAccFile(accFp);

	FILE * docFp =NULL;
	docFp = file_open("./data/doctor.txt");
	docList = readDocFile(docFp);

	FILE * claFp =NULL;
	claFp = file_open("./data/class.txt");
	claList = readClaFile(claFp);

	while(1){
		system("cls");
		res = functionArr[res]();
	}
	return 0;
}
