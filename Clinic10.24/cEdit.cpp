#include "cEdit.h"

void showEdit(CONTROL edit){
	paintBorder(edit.x,edit.y,edit.width,edit.height);
	printf("%s",edit.context);
}

/************************************************************************************
�������ƣ�inputControl
�������ã��༭��������ƺ���
��������ֵ����
����������	char buf[20]��������������
					int maxLen�����������ַ�����
					int inputType�������������� 0�޿��� 1ֻ������ 2ֻ����ĸ 3��ĸ+����
					int status����ʾ���� 1���� 0����
					int ikey: �����ڴ������������б༭�����µİ���
************************************************************************************/
void inputControl(char buf[20],int maxLen,int inputType,int status,int ikey){
	// ���ñ��ػ�
    setlocale(LC_CTYPE, "zh_CN.UTF-8");
	//��ȡ�ַ������ȣ�������֤������������ַ�
	int count = strlen(buf);	
	if(count < maxLen){
		if(inputType == 0){//�޿���
			//����ı��浽buf��
			buf[count++] = ikey;
			if(status == 1){//����
				putch(ikey);
				cin.getline(buf, 20);
			}else{//����
				putch('*');
			}
		}else if(inputType == 1){//ֻ������
			if(ikey >= '0' && ikey <= '9'){
				//����ı��浽buf��
				buf[count++] = ikey;
				if(status == 1){//����
					putch(ikey);
				}else{//����
					putch('*');
				}
			}
		}else if(inputType == 2){//ֻ����ĸ
			if((ikey >= 'a' && ikey <= 'z') || (ikey >= 'A' && ikey <= 'Z')){
				//����ı��浽buf��
				buf[count++] = ikey;
				if(status == 1){//����
					putch(ikey);
				}else{//����
					putch('*');
				}
			}
		}else if(inputType == 3){//��ĸ+����+����
			if((ikey >= '0' && ikey <= '9') || (ikey >= 'a' && ikey <= 'z') || (ikey >= 'A' && ikey <= 'Z')){
				//����ı��浽buf��
				buf[count++] = ikey;
				if(status == 1){//����
					putch(ikey);
					//cin.getline(buf, 20);
				}else{//����
					putch('*');
				}
			}
		}
	}
	//����ɾ��
	if(ikey == '\b' && count > 0){
		//ɾ�������ַ�
		buf[--count] = '\0';
		//ɾ������̨��ʾ
		printf("\b \b");
	}
}