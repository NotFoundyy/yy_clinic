#include "cFile.h"

/*FILE* file_open(char * filepath){
	FILE * fp = NULL;

	fp = fopen(filepath,"r+");
	if(fp == NULL){
		fp = fopen(filepath,"w+");
	}
	printf("文件打开成功！\n");
	return fp;
}

void writeMenuFile(LIST * head, FILE * fp){
	int x = 0;
	int count = List_getSize(head);
	for(x = 0;x < count;x++){
		LIST * node = getByPos(head,x);
		MENU * menu = (MENU *)node->pdata;
		fprintf(fp, "%d %s %d %d\n",menu->menuid,menu->menuName,menu->price,menu->num);
		fflush(fp);
	}
	fclose(fp);
}

LIST * readMenuFile(FILE * fp){
	MENU resMenu;
	int res = 0;
	LIST * menuList = NULL;

	menuList = List_init();

	while((res = fscanf(fp,"%d %s %d %d",&resMenu.menuid,resMenu.menuName,&resMenu.price,&resMenu.num)) > 0){
		List_pushback(menuList,&resMenu,sizeof(MENU));
	}
	fclose(fp);
	
	return menuList;
}*/