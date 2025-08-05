#include "cFile.h"

FILE* file_open(char * filepath){
	FILE * fp = NULL;

	fp = fopen(filepath,"r+");
	if(fp == NULL){
		fp = fopen(filepath,"w+");
	}
	printf("文件打开成功！\n");
	return fp;
}

void writeFile(LIST * head, FILE * fp){
	int x = 0;
	int count = List_getSize(head);
	for(x = 0;x < count;x++){
		LIST * node = getByPos(head,x);
		ACC * acc = (ACC *)node->pdata;
		fprintf(fp, "%s %d \n",acc->accName,acc->role);
		fflush(fp);
	}
	fclose(fp);
}

LIST * readFile(FILE * fp){
	ACC resAcc;
	int res = 0;
	LIST * accList = NULL;

	accList = List_init();

	while((res = fscanf(fp,"%s %d",&resAcc.accName,&resAcc.role)) > 0){
		List_pushback(accList,&resAcc,sizeof(ACC));
	}
	fclose(fp);
	
	return accList;
}
