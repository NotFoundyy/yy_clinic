#include "cInitWin.h"

int InitWin_init(){

	CWIN initwin = {21,2,30,16};

	CONTROL title = {LABEL,25,4,"门 诊 预 约 管 理 系 统"};

	CONTROL login = {BUTTON,31,7,"登	 录", 10, 1};
	CONTROL userRegister = {BUTTON,31,11,"注	 册", 10, 1};
	CONTROL esc = {BUTTON,31,15,"退	 出", 10, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&login);
	addControl(&initwin,&userRegister);
	addControl(&initwin,&esc);

	paintWindow(&initwin);

	winRun(&initwin);

	switch(initwin.flag){
	case 1:		return 2;		break;
	case 2:		return 1;		break;
	case 3:		
	CWIN escwin = {25,4,20,10};

	CONTROL title = {LABEL,28,5,"确 认 退 出？"};

	CONTROL yes = {BUTTON,31,7,"确	认", 10, 1};
	CONTROL no = {BUTTON,31,11,"取	消", 10, 1};

	addControl(&escwin,&title);
	addControl(&escwin,&yes);
	addControl(&escwin,&no);

	paintWindow(&escwin);
	winRun(&escwin);
	
	if(escwin.flag == 1){
		exit(0);
	}else{
		return 0;
	}
			break;
	}
	
	return 0;
}