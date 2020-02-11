#include "Queue.h"

bool InitQueue(SqQueue *q)
{
	q->base = new ElemType[MAXQSIZE];
	if(!q->base) exit(OVERFLOW);
	q->front = q->rear = 0;
	return true;
}
bool DestroyQueue(SqQueue *q)
{
	delete[] q->base;
	q->front = q->rear = 0;
}
bool  ClearQueue(SqQueue *q)
{
	q->front = q->rear = 0;//空间不必回收
}
bool QueueEmpty(SqQueue *q)
{
	if(q->front == q->rear)
		return true;
	else
		return false;
}
int QueueLength(SqQueue *q)
{
	return (q->rear - q->front+MAXQSIZE)%MAXQSIZE;//因为是循环队列
}
bool EnQueue(SqQueue *q,ElemType e)
{
	if((q->rear + 1) % MAXQSIZE == q->front)
		return false;
	else
	{
		q->base[q->rear] = e;
		q->rear = (q->rear + 1) % MAXQSIZE;
		return true;
	}
}
bool DeQueue(SqQueue *q,ElemType *e)
{
	if(q->rear == q->front)
		return false;
	else
	{
		*e= q->base[q->front];
		q->front = (q->front + 1) % MAXQSIZE;
		return true;
	}
}

bool InitQueue(LinkQueue *q)
{
	q->front = q->rear = new QNode();
	q->front->next = nullptr;
}
bool DestroyQueue(LinkQueue *q)//销毁要把头结点也删了
{
	//QNode *p = q->front;
	//QNode *t;
	//此处可以不用额外的指针
	while(q->front)
	{
		q->rear = q->front->next;
		delete q->front;
		q->front = q->rear;//此时的q->rear就是q->front的下一个结点
	}
	return true;
}
bool  ClearQueue(LinkQueue *q)//清空要保留头结点
{
	QNode *p=q->front->next;//要删除的是p
	while(p)
	{
		q->rear = p->next;
		delete p;
		p = q->rear;//此时的q->rear就是q->front的下一个结点
	}
	return true;
}
bool QueueEmpty(LinkQueue *q)
{

}
int QueueLength(LinkQueue *q)
{

}
bool EnQueue(LinkQueue *q, ElemType e)
{

}
bool DeQueue(LinkQueue *q, ElemType *e)
{

}