#include "cTool.h"
#include "cLoginWin.h"
#include "cRegisterWin.h"
#include "cInitWin.h"
#include "cLoginChoseWin.h"
#include "cAdminWin.h"
#include "cDoctorWin.h"
#include "cUserWin.h"
#include "cAdminLoginWin.h"

//#include "cMenuWin.h"
#include "cList.h"
#include "cFile.h"

//��ɫ�ṹ������
USER arr[5] = {
	{"admin","123456",1},
	{"doctor","abc123",2},
	{"yy","021323",3},
};
int userNum = 3;
int res = 0;

//����ָ������
int (*functionArr[10])() = {
	InitWin_init,//��ʼ
	RegisterWin_init, //ע��
	LoginWin_init, //��¼
	LoginChoseWin_init,//������
	AdminWin_init, //����Ա
	DoctorWin_init, //ҽ��
	UserWin_init, //�û�
	AdminLoginWin_init,//����Ա��¼
//	NULL, //��������
};

int main(){
	while(1){
		system("cls");
		res = functionArr[res]();
	}
	return 0;
}