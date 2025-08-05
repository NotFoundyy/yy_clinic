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
//#include "cMenuWin.h"
#include "cList.h"
#include "cFile.h"

//��ɫ�ṹ������
USER arr[5] = {
	{"admin","123456",1},
	{"1001","abc123",2},
	{"yy","021323",3},
};
int userNum = 3;
int res = 10;

LIST * accList;

//����ָ������
int (*functionArr[20])() = {
	InitWin_init,//��ʼ
	RegisterWin_init, //ע��
	LoginWin_init, //��¼
	LoginChoseWin_init,//������
	AdminWin_init, //����Ա
	DoctorWin_init, //ҽ��
	UserWin_init, //�û�
	AdminLoginWin_init,//����Ա��¼
	DoctorLoginWin_init,//ҽ����¼
	UserLoginWin_init,//�û���¼
	userQueryWin_init,//�û���ѯ
//	NULL, //��������
};

int main(){

	acc m1 = {"admin",1};
	acc m2 = {"1001",2};
	acc m3 = {"1002",2};
	acc m4 = {"1003",2};
	acc m5 = {"yy",3};
	acc m6 = {"15751390763",3};

	FILE * fp =NULL;
	fp = file_open("./data/user.txt");
	accList = readFile(fp);

	while(1){
		system("cls");
		res = functionArr[res]();
	}
	return 0;
}