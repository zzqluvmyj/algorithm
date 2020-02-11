#include "List.h"

void InitList(SqList *L)
{
	L->data = new ElemType[LIST_INIT_SIZE]();//����Ҫ�����������ڴ��ʼ�����˴�ȫ����ʼ��Ϊ0
	if(!L->data)
		exit(OVERFLOW);//�����ڴ�ʧ��
	L->length = 0;
	L->size = LIST_INIT_SIZE;
}

void DestroyList(SqList *L)
{
	delete[] L->data;
	L->data = nullptr;
	L->length = 0;
	L->size = 0;
}

void ClearList(SqList *L)
{
	L->length = 0;//�˴�Ϊ�����ܣ�����ֱ��������飬������ձ�־���´����õ�ʱ�����ֱ�Ӹ��ǣ���ʡ����
}

bool ListEmpty(SqList *L)
{
	if(L->length == 0)
		return true;
	else
		return false;
}

int ListLength(SqList *L)
{
	return L->length;
}

bool GetElem(SqList *L, int i, ElemType *e)
{
	if(i <= L->length && i >= 1)
	{
		*e = L->data[i - 1];
		return true;
	}
	else
	{
		return false;
	}
}

int LocateElem(SqList *L, ElemType e, int(*compare)(ElemType, ElemType))
{
	ElemType *temp;
	temp = L->data;
	for(int i = 1; i <= L->length; i++)
	{
		if(compare(*temp, e)>0)
			return i;
		++temp;
	}
	return 0;
}

bool PriorElem(SqList *L, ElemType cur_e, ElemType *pre_e)
{
	//�˴�i���������У�Ϊ1����Ϊ�϶��Ǵӵ�2��Ԫ�ؿ�ʼ�ıȽϵ�
	for(int i=1; i < L->length; i++)
	{
		if(L->data[i] == cur_e)
		{
			*pre_e = L->data[i - 1];
			return true;
		}
	}
	return false;
}

bool NextElem(SqList *L, ElemType cur_e, ElemType *next_e)
{
	
	for(int i = 0; i < L->length - 1; i++)
	{
		if(L->data[i] == cur_e)
		{
			*next_e = L->data[i + 1];
			return true;
		}
	}
	return false;
}

bool ListInsert(SqList *L, int i, ElemType e)
{
	ElemType *newbase, *p, *q;
	//��i==(*L).length + 1��Ҳ���������һ��Ԫ�صĺ������Ԫ��
	if(i < 1 || i>L->length + 1)
		return false;
	//������ȴ��ڵ��������С����Ҫ����ռ�
	if(L->length >= L->size)
	{
		L->data = (ElemType *)realloc(L->data, (L->size + LIST_INCREMENT) * sizeof(ElemType));
		if(!L->data) exit(OVERFLOW);
		L->size += LIST_INCREMENT;
	}
	p = L->data + i - 1;//Ҫ�����λ��ָ��
	q = L->data + L->length;//��������λ��ָ��
	for(; q != p; q--)
	{
		*q = *(q-1);
		q = q - 1;
	}
	*p = e;
	L->length++;
	return true;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
	if(i < 1 || i>L->length)
		return false;
	int *p, *q;
	q = L->data + i - 1;//Ҫɾ����Ԫ�ص�ָ��
	p = L->data + L->length - 1;//���һ��Ԫ�ص�ָ��
	*e = *q;//���ر�ɾ����Ԫ��
	for(; q != p; ++q)
		*q = *(q + 1);
	--L->length;
	return true;
}

void ListTraverse(SqList *L, void(*vi)(ElemType *))
{
	ElemType *temp=L->data;
	for(int i = 1; i <= L->length; i++)
		vi(temp++);
}


void PrintList(SqList *l)
{
	for(int i = 0; i < l->length; i++)
	{
		cout << l->data[i] << " ";
	}
	cout << endl;
}

//������->������

void InitList(LinkList *l)
{
	//��Ҫ�޸Ĵ�������ָ�룬��ָ�뵱����ͨ��������ͨ����Ҫ�޸Ŀ϶����ܴ�����Ҫ������ָ��
	//ͬ�������Ҫ�޸�ָ���ֵ�����봫ָ���ָ�룬�����ú���ܶԸ�ָ������޸�
	(*l) = new LinkNode();
	if(!(*l))
		exit(1);//�������˳�
	(*l)->next = nullptr;
}

void DestroyList(LinkList *L)
{
	while(*L)
	{
		delete(*L);
		*L = nullptr;
	}
}

void ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	(*L)->next = nullptr;
}

bool ListEmpty(LinkList L)
{
	if(L->next)
		return false;
	else
		return true;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

bool GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p = L->next;
	int j = 1;//��Ϊpȡ���ǵ�һ����ֵ�Ľ�㣬������1��������׽�㣬����Ϊ0
	if(i <= 0)return false;
	while(p && j != i)
	{
		p = p->next;
		j++;
	}
	if(!p)
	{
		return false;
	}
	else
	{
		*e = p->data;
		return true;
	}
}

int LocateElem(LinkList L, ElemType e, int(*compare)(ElemType, ElemType))
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if(compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList q, p = L->next;
	while(p->next)//��Ϊ��һ���ڵ�û��ǰ��������ֱ�Ӵӵ�2����ʼ
	{
		q = p->next;//qΪ��ǰ�ڵ㣬pΪ�ϸ��ڵ�
		if(q->data == cur_e)
		{
			*pre_e = p->data;
			return true;
		}
		p = p->next;
	}
	return false;
}

bool NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	LinkList p = L->next;
	while(p->next)//�ӵ�2����㿪ʼ������Ϊ���ȿ���ǰ���p��û�к�̽�㣬û���ǾͿ϶�û����һ��ֵ
	{
		if(p->data == cur_e)
		{
			*next_e = p->next->data;
			return true;
		}
		p = p->next;
	}
	return false;
}

bool ListInsert(LinkList L, int i, ElemType e)
{
	int j = 0;//ָ�׽��j=0��ָ��һ����ֵ�Ľ�����1��ûë����
	LinkList p = L, s;
	while(p && j < i - 1)//����ѭ����i-1��Ϊ��Ѱ�ҵ�i-1�����,Ϊʲô�ж�p����Ϊ��i���������i-1������ϣ�Ҳ������Ϊj<i-1����ѭ��ʱ��p
	{
		p = p->next;
		j++;
	}
	if(!p)//�����������
		return false;
	s = new LinkNode();
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete(LinkList L, int i, ElemType *e)
{
	int j = 0;
	LinkList p = L, q;
	while(p->next && j < i - 1)//�˴�Ϊ����p->next����ΪҪɾ��i����㣬����Ҫ�ж�i������Ƿ���ڣ���������ڣ���Ȼ����ɾ��
	{
		p = p->next;
		j++;
	}
	if(!p->next)
		return false;
	q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

void ListTraverse(LinkList L, void(*vi)(ElemType*))
{
	LinkList p = L->next;
	while(p)
	{
		vi(&p->data);
		p = p->next;
	}
}

void PrintList(LinkList L)
{
	if(!L)
	{
		return;
	}
	LinkList q = L->next;
	while(q)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}

