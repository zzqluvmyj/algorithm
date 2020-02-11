#pragma once
#include "base.h"
#define LIST_INIT_SIZE 50
#define LIST_INCREMENT 50

//˳������ݽṹ����
struct SqList
{
	int length,size;//���Ⱥ�����
	ElemType *data;
};
//�������ݽṹ����
struct LinkNode
{
	ElemType data;
	LinkNode *next;
};
typedef LinkNode* LinkList;//LinkList��LinkNode��ָ������


//ע��λ�ò������꣬˳���������Ԫ��λ�ô�1��ʼ
void InitList(SqList *L);//��������Ա�
void DestroyList(SqList *L);//�������Ա�
void ClearList(SqList *L);//������Ա�
bool ListEmpty(SqList *L);//�ж����Ա��Ƿ�Ϊ��
int ListLength(SqList *L);//���Ա�ĳ���
bool GetElem(SqList *L, int i, ElemType *e);//�õ�ָ��λ�õ�Ԫ��
int LocateElem(SqList *L, ElemType e, int(*compare)(ElemType, ElemType));//���ݱȽϺ����Ƚ�ĳ��Ԫ������λԪ��,��˳���ҵ���һ�����ϱȽ�������Ԫ�ص�λ��
bool PriorElem(SqList *L, ElemType cur_e, ElemType *pre_e);//��ǰԪ�ص�����
bool NextElem(SqList *L, ElemType cur_e, ElemType *next_e);//��ǰԪ�صĺ��
bool ListInsert(SqList *L, int i, ElemType e);//����Ԫ��
bool ListDelete(SqList *L, int i, ElemType *e);//ɾ��Ԫ��
void ListTraverse(SqList *L, void(*vi)(ElemType *));//��ÿ��Ԫ�أ�����vi����,vi��һ������ָ�룬��һ������û�����ţ�vi�ĺ���ԭ���ǽ���int*������void
void PrintList(SqList *L);

//L�������һ��ָ���ˣ����������޸ĸ�ָ��ָ������ݣ�����Ҫ��ָ���ָ��
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