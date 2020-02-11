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
	q->front = q->rear = 0;//�ռ䲻�ػ���
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
	return (q->rear - q->front+MAXQSIZE)%MAXQSIZE;//��Ϊ��ѭ������
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
bool DestroyQueue(LinkQueue *q)//����Ҫ��ͷ���Ҳɾ��
{
	//QNode *p = q->front;
	//QNode *t;
	//�˴����Բ��ö����ָ��
	while(q->front)
	{
		q->rear = q->front->next;
		delete q->front;
		q->front = q->rear;//��ʱ��q->rear����q->front����һ�����
	}
	return true;
}
bool  ClearQueue(LinkQueue *q)//���Ҫ����ͷ���
{
	QNode *p=q->front->next;//Ҫɾ������p
	while(p)
	{
		q->rear = p->next;
		delete p;
		p = q->rear;//��ʱ��q->rear����q->front����һ�����
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