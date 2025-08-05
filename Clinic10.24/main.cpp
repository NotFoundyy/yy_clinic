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

//用户结构体数组
USER arr[10] = {
	{"admin","123456",1},
	{"1001","abc123",2},
	{"1002","abc123",2},
	{"yy","021323",3},
};
//医生结构体数组
DOC doc[10] = {
	{"1001","张三","主任","外科","一院","牛"},
	{"1002","张四","副主任","内科","一院","屌"},
	{"1003","张五","医师","骨科","三院","6"},
	{"1004","张六","实习","脑科","二院","无"},
};
//科室结构体数组
CLA cla[10] = {
	{"1001","外科","牛"},
	{"1002","内科","屌"},
	{"1003","骨科","6"},
	{"1004","脑科","无"},
};

int userNum = 4;
int docNum = 4;
int claNum = 4;
int res = 0;

LIST * accList;
LIST * docList;
LIST * claList;

//函数指针数组
int (*functionArr[20])() = {
	InitWin_init,//初始0
	RegisterWin_init, //注册1
	LoginWin_init, //登录2
	LoginChoseWin_init,//下拉框3
	AdminWin_init, //管理员4
	DoctorWin_init, //医生5
	UserWin_init, //用户6
	AdminLoginWin_init,//管理员登录7
	DoctorLoginWin_init,//医生登录8
	UserLoginWin_init,//用户登录9
	userQueryWin_init,//用户查询10
	doctorManWin_init,//医生管理11
	NewDoctorWin_init,//新增医生12
	classQueryWin_init,//科室查询13
	UserCenterWin_init,//个人中心14
	UserImproveWin_init,//信息完善15
	ChangePwdWin_init,//修改密码16
	UserOrderWin_init,//用户预约17
	clinic_init,//就诊信息18
//	NULL, //忘记密码
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
