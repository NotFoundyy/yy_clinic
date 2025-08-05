#include "cDoctorLoginWin.h"

int DoctorLoginWin_init(){
	int res = 0;
	CWIN loginwin = {21,2,47,16};
	
	CONTROL title = {LABEL,40,4,"�� �� �� ¼"};

	CONTROL account = {LABEL,30,8,"��    �ţ�"};
	CONTROL password = {LABEL,30,11,"��    �룺"};
	CONTROL role = {LABEL,30,14,"��    ɫ��"};

	CONTROL okBtn = {BUTTON,30,16,"�� ¼",5,1};
	CONTROL escBtn = {BUTTON,54,16,"ȡ ��",5,1};
	CONTROL roleBtn = {BUTTON,40,13,"ҽ	��",11,1};

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

	gotoxy(35,6);
	cout<<"��ӭ����ҽ��"<<loginwin.arr[4].context<<endl;

	paintWindow(&loginwin);
	winRun(&loginwin);

	if(loginwin.flag == 7){
		//��¼ҵ��
		res = LoginCheck(loginwin.arr[4].context,loginwin.arr[5].context);
		if(res == 1){
			//����Ա
			return 4;
		}else if(res == 2){
			//ҽ��
			return 5;
		}else if(res == 3){
			//��ͨ�û�
			return 6;
		}else if(res == 4){
			//error
			return 2;
		}
	}else if(loginwin.flag == 8){
		//ȡ��
		return 0;
	}
	return 0;
}