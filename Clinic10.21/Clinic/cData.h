#ifndef CDATA_H
#define CDATA_H

//1标签 2按钮 3编辑框
#define LABEL 1
#define BUTTON 2
#define EDIT 3

//所有窗口的控件结构体
typedef struct control{
	int type;				//控件类型
	int x;					  //控件X坐标
	int y;					  //控件Y坐标
	char context[30];//控件字符数组（文本）
	int width;			  //控件宽度
	int height;			  //控件高度
	int maxLen;			//编辑框字符上限
	int inputType;		//编辑框输入类型
	int status;				//编辑框显示类型
}CONTROL;

typedef struct user{
	char username[20];
	char password[20];
	int role;//管理员1 医生2 用户3
}USER;

typedef struct acc{
	char accName[20];
	char role[20];
}ACC;

typedef struct list{
	void * pdata;
	struct list * pnext;
}LIST;

typedef struct doc{
	char docID[20];
	char docName[20];
	char docRole[20];
	char docClass[20];
	char docHospital[20];
	char docAsk[20];
}DOC;

typedef struct cla{
	char claID[20];
	char claName[20];
	char claAsk[20];
}CLA;

#endif