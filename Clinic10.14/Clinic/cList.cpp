#include "cList.h"

LIST * List_init(){
	LIST * head = NULL;
	//动态开空间
	head = (LIST *)malloc(sizeof(LIST));
	if(head == NULL){
		printf("链表创建失败！");
		return NULL;
	}else{
		//内存初始化
		memset(head,'0',sizeof(LIST));
		head->pdata = NULL;
		head->pnext = NULL;
		printf("链表创建成功！\n");
	}
	return head;
}

void List_pushback(LIST * head,void* data,int length){
	//临时的指针指向该链表结点
	LIST * ptemp = head;
	LIST * pnew = (LIST *)malloc(sizeof(LIST));
	if(pnew == NULL){
		printf("创建新结点失败！\n");
		return;
	}
	memset(pnew,'0',sizeof(LIST));
	//结点中两个数据操作 
	//数据域操作，地址不能通过参数赋值来，需要自己开空间，数据通过拷贝内存得到
	pnew->pdata = malloc(length);
	if(pnew->pnext == NULL){
		printf("创建数据区失败！\n");
		return;
	}
	memcpy(pnew->pdata,data,length);
	//指针域操作，暂时设置为NULL
	pnew->pnext = NULL;
	while(ptemp->pnext != NULL){
		ptemp = ptemp->pnext;
	}
	ptemp->pnext = pnew;
}

//获取链表个数
int List_getSize(LIST * head){
	int count = 0;
	LIST * ptemp = head;
		while(ptemp->pnext != NULL){
			count++;
		ptemp = ptemp->pnext;
	}
		return count;
}

LIST * getByPos(LIST * head, int position){
	LIST * resNode = NULL;

	LIST * ptemp = head;
	int count = 0;
	int num = 0;
	count = List_getSize(head);

	if(position >= count || position < 0){
		printf("超过链表总长度！");
		return NULL;
	}else{
		while(ptemp->pnext != NULL){
			
			ptemp = ptemp->pnext;
			if(num == position){
				return ptemp;
			}
			num++;
		}
	}
	return resNode;
}

void List_insert(LIST * head, void * data,int length,int position){
	int count = 0;
	int num = 0;
	LIST * pre = head;
	LIST * ptemp = head->pnext;

	LIST * pnew = (LIST *)malloc(sizeof(LIST));
	if(pnew == NULL){
		printf("创建新结点失败！\n");
		return;
	}
	memset(pnew,'0',sizeof(LIST));
	pnew->pdata = NULL;
	pnew->pnext = NULL;

	pnew->pdata = malloc(length);
	if(pnew->pdata == NULL){
		printf("创建数据区失败！\n");
		return;
	}
	memcpy(pnew->pdata,data,length);

	count = List_getSize(head);

	if(position >= count || position < 0){
		printf("超过链表总长度！");
		return;
	}else{
		while(ptemp != NULL){
			if(num == position){
				pnew->pnext = pre->pnext;
				pre->pnext = pnew;
			}else{
				pre = pre->pnext;
				ptemp = ptemp->pnext;
			}
			num++;
		}
	}
}

int deleteByPos(LIST * head,int position){
	int count = 0;
	int num = 0;
	LIST * pre = head;
	LIST * ptemp = head->pnext;

	count = List_getSize(head);
	if(position >= count || position < 0){
		printf("超过链表总长度！");
		return 1;
	}else{
		while(ptemp != NULL){
			if(num == position){
				pre->pnext = ptemp->pnext;
				free(ptemp);
				return 1;
			}else{
				pre = pre->pnext;
				ptemp = ptemp->pnext;
			}
			num++;
		}
	}
	return 0;
}

void List_free(LIST * head){
	int count = 0;
	LIST * ptemp = head;
	
	while(ptemp != NULL){
		head = head->pnext;
		free(ptemp);
		ptemp = head;
		count++;
		printf("释放%d个结点\n",count);
	}
}
