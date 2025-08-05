#include "cLoginChoseWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int LoginChoseWin_init(){
	int res = 0;
	CWIN loginwin = {21,2,47,16};
	
	CONTROL title = {LABEL,40,4,"�� �� �� ¼"};

	CONTROL account = {LABEL,30,8,"��    �ţ�"};
	CONTROL password = {LABEL,30,11,"��    �룺"};
	CONTROL role = {LABEL,30,14,"��    ɫ��"};

	CONTROL okBtn = {BUTTON,30,16,"�� ¼",5,1};
	CONTROL escBtn = {BUTTON,54,16,"ȡ ��",5,1};
	CONTROL roleBtn = {BUTTON,40,13,"�� ѡ �� ��",11,1};
	CONTROL adminBtn = {BUTTON,40,15,"����Ա",11,1};
	CONTROL doctorBtn = {BUTTON,40,17,"ҽ��",11,1};
	CONTROL userBtn = {BUTTON,40,19,"��ͨ�û�",11,1};

	CONTROL accEdit = {EDIT,40,7,"",20,1,10,3,1};
	CONTROL passEdit = {EDIT,40,10,"",20,1,10,3,0};

	addControl(&loginwin,&title);
	addControl(&loginwin,&account);
	addControl(&loginwin,&password);
	addControl(&loginwin,&role);
	addControl(&loginwin,&accEdit);
	addControl(&loginwin,&passEdit);
	addControl(&loginwin,&roleBtn);
	addControl(&loginwin,&adminBtn);
	addControl(&loginwin,&doctorBtn);
	addControl(&loginwin,&userBtn);
	addControl(&loginwin,&okBtn);
	addControl(&loginwin,&escBtn);

	paintWindow(&loginwin);
	SmallWinRun(&loginwin);

	if(loginwin.flag == 7){
		//����Ա
		return 7;
	}else if(loginwin.flag == 8){
		//ҽ��
		return 5;
	}else if(loginwin.flag == 9){
		//�û�
		return 6;
	}
	return 0;
}

SmallWinRun(CWIN *win){
	int i, ikey;
	for (i = 6;i < 10;i++){
		if (win->arr[i].type == EDIT || win->arr[i].type == BUTTON){
			break;
		}
	}
	gotoxy(win->arr[i].x+2, win->arr[i].y+1);

	while(1){
		ikey = getKey();

		switch(ikey){
		case KEY_UP:
			i--;
			if(i < 0){
				i = win->count - 1;
			}
			while(win->arr[i].type == LABEL){
				i--;
				if(i < 0){
					i = win->count - 1;
				}
			}
			gotoxy(win->arr[i].x + 2 + strlen(win->arr[i].context), win->arr[i].y + 1); 
			break;
		case KEY_DOWN:
			i++;
			if(i > 9){
				i = 7;
			}
			while(win->arr[i].type == LABEL){
				if(i <10){
					i++;
				}else{
					i = 7;
				}
			}
			gotoxy(win->arr[i].x + 2 + strlen(win->arr[i].context), win->arr[i].y + 1);
			break;
		case KEY_ESC:
			break;
		case KEY_ENTER:	
			if(win->arr[i].type == BUTTON){
				win->flag = i;
				return i;
			}else if(win->arr[i].type == EDIT){
				i++;
				if(i > 9){
					i = 7;
				}
				while(win->arr[i].type == LABEL){
					if(i < 10){
						i++;
					}else{
						i = 7;
					}
				}
			}
			gotoxy(win->arr[i].x + 2 + strlen(win->arr[i].context), win->arr[i].y + 1); 
			break;
		default:
			if(win->arr[i].type == EDIT){
				inputControl(win->arr[i].context,win->arr[i].maxLen,win->arr[i].inputType,win->arr[i].status,ikey);
			}
			break;
		}
	}
}