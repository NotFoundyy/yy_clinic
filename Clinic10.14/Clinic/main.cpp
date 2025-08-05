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

//角色结构体数组
USER arr[5] = {
	{"admin","123456",1},
	{"1001","abc123",2},
	{"yy","021323",3},
};
int userNum = 3;
int res = 10;

LIST * accList;

//函数指针数组
int (*functionArr[20])() = {
	InitWin_init,//初始
	RegisterWin_init, //注册
	LoginWin_init, //登录
	LoginChoseWin_init,//下拉框
	AdminWin_init, //管理员
	DoctorWin_init, //医生
	UserWin_init, //用户
	AdminLoginWin_init,//管理员登录
	DoctorLoginWin_init,//医生登录
	UserLoginWin_init,//用户登录
	userQueryWin_init,//用户查询
//	NULL, //忘记密码
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