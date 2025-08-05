#include "cWindow.h"

addControl(CWIN *win, CONTROL *con){
	int x = 0;
	while(win->arr[x].type != 0){
		x++;
	}
	win->arr[x] = *con;
	win->count++;
}

void paintWindow(CWIN *win){
	int i;
	paintBorder(win->winX,win->winY,win->winWidth,win->winHeight);

	for(i = 0;i < win->count;i++){
		switch(win->arr[i].type){
		case LABEL : showLabel(win->arr[i]); break;
		case BUTTON : showButton(win->arr[i]); break;
		case EDIT : showEdit(win->arr[i]); break;
		}
	}
}

winRun(CWIN *win){
	int i, ikey;
	for (i = 0;i < win->count;i++){
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
			if(i >= win->count){
				i = 0;
			}
			while(win->arr[i].type == LABEL){
				if(i < win->count - 1){
					i++;
				}else{
					i = 0;
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
				if(i >= win->count){
					i = 0;
				}
				while(win->arr[i].type == LABEL){
					if(i < win->count - 1){
						i++;
					}else{
						i = 0;
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