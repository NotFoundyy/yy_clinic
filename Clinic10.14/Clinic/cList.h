#ifndef CLIST_H
#define CLIST_H

#include"cData.h"
#include"cTool.h" 

//创建链表
LIST * List_init();

//在链表末尾增加结点
void List_pushback(LIST * head, void * data, int length);

//获取链表结点个数
int List_getSize(LIST * head);

LIST * getByPos(LIST * head, int position);

void List_insert(LIST * head, void * data,int length,int position);

int deleteByPos(LIST * head,int position);

void List_free(LIST * head);

#endif