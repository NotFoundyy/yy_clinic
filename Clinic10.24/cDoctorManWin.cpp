#include "cDoctorManWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern docNum;
extern LIST * docList;

int doctorManWin_init(){
	//当前页
	int currentPage = 1;
	//总页数
	int countPage = 0;
	//数据总个数
	int count = 0;
	//起始下标
	int index = 0;
	LIST * node;
	DOC * doc;
	int n = 0;

	CWIN initwin = {21,2,50,20};

	CONTROL title = {LABEL,43,4,"医 生 管 理"};

	CONTROL usermain = {LABEL,22,9,"请输入用户账号："};
	CONTROL userdoctor = {EDIT,38,8,"", 15,1,10,3,1};
	CONTROL query = {BUTTON,58,8,"查 询", 5, 1};
	CONTROL m1= {BUTTON,33,13,"", 5, 1};
	CONTROL m2 = {BUTTON,33,15,"", 5, 1};
	CONTROL m3 = {BUTTON,33,17,"", 5, 1};
	CONTROL esc = {BUTTON,22,20,"返 回", 5, 1};
	CONTROL up = {BUTTON,55,20,"上一页", 6, 1};
	CONTROL down = {BUTTON,64,20,"下一页", 6, 1};


	addControl(&initwin,&title);
	addControl(&initwin,&usermain);
	addControl(&initwin,&userdoctor);
	addControl(&initwin,&query);
	addControl(&initwin,&m1);
	addControl(&initwin,&m2);
	addControl(&initwin,&m3);
	addControl(&initwin,&esc);
	addControl(&initwin,&up);
	addControl(&initwin,&down);

	paintWindow(&initwin);

	getTime(55,6);
	paintTable(23,11,7,1,4,6);
	gotoxy(25,12);
	printf("医生ID");
	gotoxy(34,12);
	printf("姓名");
	gotoxy(42,12);
	printf("职位");
	gotoxy(49,12);
	printf("所属科室");
	gotoxy(57,12);
	printf("所属医院");
	gotoxy(66,12);
	printf("简介");

	gotoxy(22,6);
	for(int x = 0;x < docNum;x++){
		switch(arr[x].role){
		case 1: 
			//管理员
			cout<<"欢迎您，管理员"<<arr[x].username<<endl;
			break;
		case 2:
			//医生
			cout<<"欢迎您，医生"<<arr[x].username<<endl;
			break;
		case 3:
			//用户
			cout<<"欢迎您，用户"<<arr[x].username<<endl;
			break;
		}
		break;
	}
	count = List_getSize(docList);
		if(count % 3 == 0){
			countPage = count/3;
		}else{
			countPage = count/3 + 1;
		}
		for( x = index;x < index + 3;x++){
			if(x < count){
				node = getByPos(docList,x);
				doc = (DOC *)node->pdata;		
				gotoxy(26,14+2*n);
				printf("%s",doc->docID);
				gotoxy(35,14+2*n);
				printf("%s",doc->docName);
				gotoxy(41,14+2*n);
				printf("%s",doc->docRole);
				gotoxy(50,14+2*n);
				printf("%s",doc->docClass);
				gotoxy(58,14+2*n);
				printf("%s",doc->docHospital);
				gotoxy(67,14+2*n);
				printf("%s",doc->docAsk);
				n++;
			}else{
				break;
			}
		}
		gotoxy(46,20);
		printf("%d/%d",currentPage,countPage);
		winRun(&initwin);

	//按钮逻辑
	if(initwin.flag == 8){
		if(currentPage > 1){
			currentPage--;
		}
	}else if(initwin.flag == 9){
			if(currentPage < countPage){
				currentPage++;
			}
	}else if(initwin.flag == 3){
		int res = docQuery(initwin.arr[2].context);
		if(res == 10){
			return 11;
		}else if(res ==11){
			return 12;
		}
	}else if(initwin.flag == 4 || initwin.flag == 5 || initwin.flag == 6){
		CWIN docwin = {30,6,30,12};
		CONTROL TITLE = {LABEL,44,8,"信息修改"};
		CONTROL ID = {LABEL,32,10,"医生ID："};
		CONTROL ROLE = {LABEL,32,13,"医生职位："};
		CONTROL YES = {BUTTON,40,16,"确定",4,1};
		CONTROL NO = {BUTTON,48,16,"取消",4,1};
		CONTROL role = {BUTTON,42,12,"",10,1};

		addControl(&docwin,&TITLE);
		addControl(&docwin,&ID);
		addControl(&docwin,&ROLE);
		addControl(&docwin,&YES);
		addControl(&docwin,&NO);
		addControl(&docwin,&role);
		paintWindow(&docwin);
		gotoxy(44,10);
		cout<<doc->docID;
		gotoxy(44,13);
		cout<<doc->docRole;
		winRun(&docwin);
	}else if(initwin.flag == 7){
		return 4;
	}
	index = (currentPage - 1) * 3;

	return 11;
}