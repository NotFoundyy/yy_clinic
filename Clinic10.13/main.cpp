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

//角色结构体数组
USER arr[5] = {
	{"admin","123456",1},
	{"doctor","abc123",2},
	{"yy","021323",3},
};
int userNum = 3;
int res = 0;

//函数指针数组
int (*functionArr[10])() = {
	InitWin_init,//初始
	RegisterWin_init, //注册
	LoginWin_init, //登录
	LoginChoseWin_init,//下拉框
	AdminWin_init, //管理员
	DoctorWin_init, //医生
	UserWin_init, //用户
	AdminLoginWin_init,//管理员登录
//	NULL, //忘记密码
};

int main(){
	while(1){
		system("cls");
		res = functionArr[res]();
	}
	return 0;
}