#include "cInitWin.h"

int AdminWin_init(){

	CWIN initwin = {21,2,30,16};

	CONTROL title = {LABEL,25,4,"管 理 员 界 面"};

	CONTROL userM = {BUTTON,31,7,"登	 录", 10, 1};
	CONTROL doctorM = {BUTTON,31,11,"注	 册", 10, 1};
	CONTROL roomM = {BUTTON,31,15,"退	 出", 10, 1};
	CONTROL dataM = {BUTTON,31,15,"退	 出", 10, 1};
	CONTROL esc = {BUTTON,31,15,"退	 出", 10, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&roomM);
	addControl(&initwin,&dataM);
	addControl(&initwin,&esc);

	paintWindow(&initwin);

	winRun(&initwin);
	
	return 0;
}