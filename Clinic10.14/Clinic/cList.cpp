#include "cList.h"

LIST * List_init(){
	LIST * head = NULL;
	//��̬���ռ�
	head = (LIST *)malloc(sizeof(LIST));
	if(head == NULL){
		printf("������ʧ�ܣ�");
		return NULL;
	}else{
		//�ڴ��ʼ��
		memset(head,'0',sizeof(LIST));
		head->pdata = NULL;
		head->pnext = NULL;
		printf("�������ɹ���\n");
	}
	return head;
}

void List_pushback(LIST * head,void* data,int length){
	//��ʱ��ָ��ָ���������
	LIST * ptemp = head;
	LIST * pnew = (LIST *)malloc(sizeof(LIST));
	if(pnew == NULL){
		printf("�����½��ʧ�ܣ�\n");
		return;
	}
	memset(pnew,'0',sizeof(LIST));
	//������������ݲ��� 
	//�������������ַ����ͨ��������ֵ������Ҫ�Լ����ռ䣬����ͨ�������ڴ�õ�
	pnew->pdata = malloc(length);
	if(pnew->pnext == NULL){
		printf("����������ʧ�ܣ�\n");
		return;
	}
	memcpy(pnew->pdata,data,length);
	//ָ�����������ʱ����ΪNULL
	pnew->pnext = NULL;
	while(ptemp->pnext != NULL){
		ptemp = ptemp->pnext;
	}
	ptemp->pnext = pnew;
}

//��ȡ�������
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
		printf("���������ܳ��ȣ�");
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
		printf("�����½��ʧ�ܣ�\n");
		return;
	}
	memset(pnew,'0',sizeof(LIST));
	pnew->pdata = NULL;
	pnew->pnext = NULL;

	pnew->pdata = malloc(length);
	if(pnew->pdata == NULL){
		printf("����������ʧ�ܣ�\n");
		return;
	}
	memcpy(pnew->pdata,data,length);

	count = List_getSize(head);

	if(position >= count || position < 0){
		printf("���������ܳ��ȣ�");
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
		printf("���������ܳ��ȣ�");
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
		printf("�ͷ�%d�����\n",count);
	}
}
