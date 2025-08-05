#ifndef CDATA_H
#define CDATA_H

//1��ǩ 2��ť 3�༭��
#define LABEL 1
#define BUTTON 2
#define EDIT 3

//���д��ڵĿؼ��ṹ��
typedef struct control{
	int type;				//�ؼ�����
	int x;					  //�ؼ�X����
	int y;					  //�ؼ�Y����
	char context[30];//�ؼ��ַ����飨�ı���
	int width;			  //�ؼ����
	int height;			  //�ؼ��߶�
	int maxLen;			//�༭���ַ�����
	int inputType;		//�༭����������
	int status;				//�༭����ʾ����
}CONTROL;

typedef struct user{
	char username[20];
	char password[20];
	int role;//����Ա1 ҽ��2 �û�3
}USER;

typedef struct acc{
	char accName[20];
	int role;
}ACC;

typedef struct list{
	void * pdata;
	struct list * pnext;
}LIST;

#endif