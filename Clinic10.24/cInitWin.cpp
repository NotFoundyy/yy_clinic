#include "cInitWin.h"

int InitWin_init(){

	CWIN initwin = {21,2,30,16};

	CONTROL title = {LABEL,25,4,"�� �� Ԥ Լ �� �� ϵ ͳ"};

	CONTROL login = {BUTTON,31,7,"��	 ¼", 10, 1};
	CONTROL userRegister = {BUTTON,31,11,"ע	 ��", 10, 1};
	CONTROL esc = {BUTTON,31,15,"��	 ��", 10, 1};

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

	CONTROL title = {LABEL,28,5,"ȷ �� �� ����"};

	CONTROL yes = {BUTTON,31,7,"ȷ	��", 10, 1};
	CONTROL no = {BUTTON,31,11,"ȡ	��", 10, 1};

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