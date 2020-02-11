#pragma once
#include "base.h"

#define MAXQSIZE 100
struct SqQueue//ѭ��˳�����
{
	ElemType *base;
	int front;
	int rear;
};
struct QNode
{
	ElemType data;
	QNode *next;
};
struct LinkQueue//��������,��ͷ��㣬ͷ��㲻�洢����
{
	QNode *front;
	QNode *rear;
};

bool InitQueue(SqQueue *q);
bool DestroyQueue(SqQueue *q);
bool  ClearQueue(SqQueue *q);
bool QueueEmpty(SqQueue *q);
int QueueLength(SqQueue *q);
bool EnQueue(SqQueue *q, ElemType e);
bool DeQueue(SqQueue *q, ElemType *e);

bool InitQueue(LinkQueue *q);
bool DestroyQueue(LinkQueue *q);
bool  ClearQueue(LinkQueue *q);
bool QueueEmpty(LinkQueue *q);
int QueueLength(LinkQueue *q);
bool EnQueue(LinkQueue *q, ElemType e);
bool DeQueue(LinkQueue *q, ElemType *e);
