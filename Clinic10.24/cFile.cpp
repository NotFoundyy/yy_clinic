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

void writeAccFile(LIST * head, FILE * fp){
	int x = 0;
	int count = List_getSize(head);
	for(x = 0;x < count;x++){
		LIST * node = getByPos(head,x);
		ACC * acc = (ACC *)node->pdata;
		fprintf(fp, "%s %s \n",acc->accName,acc->role);
		fflush(fp);
	}
	fclose(fp);
}

LIST * readAccFile(FILE * fp){
	ACC resAcc;
	int res = 0;
	LIST * accList = NULL;

	accList = List_init();

	while((res = fscanf(fp,"%s %s",&resAcc.accName,&resAcc.role)) > 0){
		List_pushback(accList,&resAcc,sizeof(ACC));
	}
	fclose(fp);
	
	return accList;
}

void writeDocFile(LIST * head, FILE * fp){
	int x = 0;
	int count = List_getSize(head);
	for(x = 0;x < count;x++){
		LIST * node = getByPos(head,x);
		DOC * doc = (DOC *)node->pdata;
		fprintf(fp, "%s %s \n",doc->docID,doc->docName,doc->docRole,doc->docClass,doc->docHospital,doc->docAsk);
		fflush(fp);
	}
	fclose(fp);
}

LIST * readDocFile(FILE * fp){
	DOC resDoc;
	int res = 0;
	LIST * docList = NULL;

	docList = List_init();

	while((res = fscanf(fp,"%s %s %s %s %s %s",&resDoc.docID,&resDoc.docName,&resDoc.docRole,&resDoc.docClass,&resDoc.docHospital,&resDoc.docAsk)) > 0){
		List_pushback(docList,&resDoc,sizeof(DOC));
	}
	fclose(fp);
	
	return docList;
}

void writeClaFile(LIST * head, FILE * fp){
	int x = 0;
	int count = List_getSize(head);
	for(x = 0;x < count;x++){
		LIST * node = getByPos(head,x);
		CLA * cla = (CLA *)node->pdata;
		fprintf(fp, "%s %s \n",cla->claID,cla->claID,cla->claAsk);
		fflush(fp);
	}
	fclose(fp);
}

LIST * readClaFile(FILE * fp){
	CLA resCla;
	int res = 0;
	LIST * claList = NULL;

	claList = List_init();

	while((res = fscanf(fp,"%s %s %s",&resCla.claID,&resCla.claName,&resCla.claAsk)) > 0){
		List_pushback(claList,&resCla,sizeof(CLA));
	}
	fclose(fp);
	
	return claList;
}