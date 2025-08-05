#include "cLoginWin.h"

int LoginWin_init(){
	int res = 0;
	CWIN loginwin = {21,2,47,16};
	
	CONTROL title = {LABEL,40,4,"用 户 登 录"};

	CONTROL account = {LABEL,30,8,"账    号："};
	CONTROL password = {LABEL,30,11,"密    码："};
	CONTROL role = {LABEL,30,14,"角    色："};

	CONTROL okBtn = {BUTTON,30,16,"登 录",5,1};
	CONTROL escBtn = {BUTTON,54,16,"取 消",5,1};
	CONTROL roleBtn = {BUTTON,40,13,"请 选 择 ▼",11,1};

	CONTROL accEdit = {EDIT,40,7,"",20,1,10,3,1};
	CONTROL passEdit = {EDIT,40,10,"",20,1,10,3,0};

	addControl(&loginwin,&title);
	addControl(&loginwin,&account);
	addControl(&loginwin,&password);
	addControl(&loginwin,&role);
	addControl(&loginwin,&accEdit);
	addControl(&loginwin,&passEdit);
	addControl(&loginwin,&roleBtn);
	addControl(&loginwin,&okBtn);
	addControl(&loginwin,&escBtn);

	CWIN errorwin = {30,6,30,10};
	CONTROL error1 = {LABEL,40,11,"请选择角色！"};

	paintWindow(&loginwin);
	winRun(&loginwin);

	if(loginwin.flag == 7){
		//登录业务
		addControl(&errorwin,&error1);
		paintWindow(&errorwin);
		Sleep(2500);
		return 2;
	}else if(loginwin.flag == 6){
		//下拉框
		return 3;
	}else if(loginwin.flag == 8){
		//取消
		return 0;
	}
	return 0;
}