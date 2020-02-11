#pragma once
#include "base.h"
#define LIST_INIT_SIZE 50
#define LIST_INCREMENT 50

//顺序表数据结构定义
struct SqList
{
	int length,size;//长度和容量
	ElemType *data;
};
//链表数据结构定义
struct LinkNode
{
	ElemType data;
	LinkNode *next;
};
typedef LinkNode* LinkList;//LinkList是LinkNode的指针类型


//注意位置不是坐标，顺序表中所有元素位置从1开始
void InitList(SqList *L);//构造空线性表
void DestroyList(SqList *L);//销毁线性表
void ClearList(SqList *L);//清空线性表
bool ListEmpty(SqList *L);//判断线性表是否为空
int ListLength(SqList *L);//线性表的长度
bool GetElem(SqList *L, int i, ElemType *e);//得到指定位置的元素
int LocateElem(SqList *L, ElemType e, int(*compare)(ElemType, ElemType));//根据比较函数比较某个元素来定位元素,按顺序找到第一个符合比较条件的元素的位置
bool PriorElem(SqList *L, ElemType cur_e, ElemType *pre_e);//当前元素的先驱
bool NextElem(SqList *L, ElemType cur_e, ElemType *next_e);//当前元素的后继
bool ListInsert(SqList *L, int i, ElemType e);//插入元素
bool ListDelete(SqList *L, int i, ElemType *e);//删除元素
void ListTraverse(SqList *L, void(*vi)(ElemType *));//对每个元素，调用vi函数,vi是一个函数指针，即一个函数没有括号，vi的函数原型是接受int*，返回void
void PrintList(SqList *L);

//L本身就是一个指针了，除非是是修改该指针指向的内容，否则不要传指针的指针
void InitList(LinkList *L);
void DestroyList(LinkList *L);
void ClearList(LinkList *L);
bool ListEmpty(LinkList L);
int ListLength(LinkList L);
bool GetElem(LinkList L, int i, ElemType *e);
int LocateElem(LinkList L, ElemType e, int(*compare)(ElemType, ElemType));
bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
bool NextElem(LinkList L, ElemType cur_e, ElemType *next_e);
bool ListInsert(LinkList L, int i, ElemType e);
bool ListDelete(LinkList L, int i, ElemType *e);
void ListTraverse(LinkList L, void(*vi)(ElemType*));
void PrintList(LinkList L);