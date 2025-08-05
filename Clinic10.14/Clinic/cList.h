#ifndef CLIST_H
#define CLIST_H

#include"cData.h"
#include"cTool.h" 

//��������
LIST * List_init();

//������ĩβ���ӽ��
void List_pushback(LIST * head, void * data, int length);

//��ȡ���������
int List_getSize(LIST * head);

LIST * getByPos(LIST * head, int position);

void List_insert(LIST * head, void * data,int length,int position);

int deleteByPos(LIST * head,int position);

void List_free(LIST * head);

#endif