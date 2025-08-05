#include "cEdit.h"

void showEdit(CONTROL edit){
	paintBorder(edit.x,edit.y,edit.width,edit.height);
	printf("%s",edit.context);
}

/************************************************************************************
函数名称：inputControl
函数作用：编辑框输入控制函数
函数返回值：无
函数参数：	char buf[20]：保存输入数据
					int maxLen：控制输入字符长度
					int inputType：输入数据类型 0无控制 1只能数字 2只能字母 3字母+数字
					int status：显示类型 1明文 0密文
					int ikey: 接受在窗口驱动函数中编辑框摁下的按键
************************************************************************************/
void inputControl(char buf[20],int maxLen,int inputType,int status,int ikey){
	// 设置本地化
    setlocale(LC_CTYPE, "zh_CN.UTF-8");
	//获取字符串长度，用来验证可以输入多少字符
	int count = strlen(buf);	
	if(count < maxLen){
		if(inputType == 0){//无控制
			//输入的保存到buf中
			buf[count++] = ikey;
			if(status == 1){//明文
				putch(ikey);
				cin.getline(buf, 20);
			}else{//密文
				putch('*');
			}
		}else if(inputType == 1){//只能数字
			if(ikey >= '0' && ikey <= '9'){
				//输入的保存到buf中
				buf[count++] = ikey;
				if(status == 1){//明文
					putch(ikey);
				}else{//密文
					putch('*');
				}
			}
		}else if(inputType == 2){//只能字母
			if((ikey >= 'a' && ikey <= 'z') || (ikey >= 'A' && ikey <= 'Z')){
				//输入的保存到buf中
				buf[count++] = ikey;
				if(status == 1){//明文
					putch(ikey);
				}else{//密文
					putch('*');
				}
			}
		}else if(inputType == 3){//字母+数字+中文
			if((ikey >= '0' && ikey <= '9') || (ikey >= 'a' && ikey <= 'z') || (ikey >= 'A' && ikey <= 'Z')){
				//输入的保存到buf中
				buf[count++] = ikey;
				if(status == 1){//明文
					putch(ikey);
					//cin.getline(buf, 20);
				}else{//密文
					putch('*');
				}
			}
		}
	}
	//可以删除
	if(ikey == '\b' && count > 0){
		//删除输入字符
		buf[--count] = '\0';
		//删除控制台显示
		printf("\b \b");
	}
}