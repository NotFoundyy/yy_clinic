#include "cNewDoctorWin.h"

int NewDoctorWin_init(){
	CWIN newDoctorWin = {21,2,47,23};
	
	CONTROL title = {LABEL,42,3,"�� �� ҽ ��"};

	CONTROL id = {LABEL,30,6,"ҽ��ID"};
	CONTROL name = {LABEL,30,9,"ҽ������"};
	CONTROL hos = {LABEL,30,12,"����ҽԺ"};
	CONTROL cla = {LABEL,30,15,"��������"};
	CONTROL role = {LABEL,30,18,"ҽ��ְλ"};
	CONTROL ask = {LABEL,30,21,"��  ��"};

	CONTROL okBtn = {BUTTON,30,23,"ȷ ��",5,1};
	CONTROL escBtn = {BUTTON,54,23,"�� ��",5,1};

	CONTROL idEdit = {EDIT,40,5,"",20,1,10,3,1};
	CONTROL nameEdit = {EDIT,40,8,"",20,1,10,3,1};
	CONTROL hosEdit = {EDIT,40,11,"",20,1,10,3,1};
	CONTROL claEdit = {EDIT,40,14,"",20,1,10,3,1};
	CONTROL roleEdit = {EDIT,40,17,"",20,1,10,3,1};
	CONTROL askEdit = {EDIT,40,20,"",20,1,10,3,1};

	addControl(&newDoctorWin,&title);
	addControl(&newDoctorWin,&id);
	addControl(&newDoctorWin,&name);
	addControl(&newDoctorWin,&hos);
	addControl(&newDoctorWin,&cla);
	addControl(&newDoctorWin,&role);
	addControl(&newDoctorWin,&ask);
	addControl(&newDoctorWin,&okBtn);
	addControl(&newDoctorWin,&escBtn);
	addControl(&newDoctorWin,&idEdit);
	addControl(&newDoctorWin,&nameEdit);
	addControl(&newDoctorWin,&hosEdit);
	addControl(&newDoctorWin,&claEdit);
	addControl(&newDoctorWin,&roleEdit);
	addControl(&newDoctorWin,&askEdit);

	paintWindow(&newDoctorWin);
	gotoxy(22,4);
	cout<<"��ӭ����ҽ��"<<newDoctorWin.arr[1].context<<endl;
	getTime(53,4);
	winRun(&newDoctorWin);

	return 0;
}