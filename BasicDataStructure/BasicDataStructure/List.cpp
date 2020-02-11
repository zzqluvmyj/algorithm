#include "List.h"

void InitList(SqList *L)
{
	L->data = new ElemType[LIST_INIT_SIZE]();//后面要加括号来给内存初始化，此处全部初始化为0
	if(!L->data)
		exit(OVERFLOW);//分配内存失败
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
	L->length = 0;//此处为了性能，并不直接清空数组，而是清空标志，下次再用的时候可以直接覆盖，节省运算
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
	//此处i是数组所有，为1是因为肯定是从第2个元素开始的比较的
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
	//当i==(*L).length + 1，也就是向最后一个元素的后面添加元素
	if(i < 1 || i>L->length + 1)
		return false;
	//如果长度大于等于数组大小，需要扩充空间
	if(L->length >= L->size)
	{
		L->data = (ElemType *)realloc(L->data, (L->size + LIST_INCREMENT) * sizeof(ElemType));
		if(!L->data) exit(OVERFLOW);
		L->size += LIST_INCREMENT;
	}
	p = L->data + i - 1;//要插入的位置指针
	q = L->data + L->length;//插入后最后位置指针
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
	q = L->data + i - 1;//要删除的元素的指针
	p = L->data + L->length - 1;//最后一个元素的指针
	*e = *q;//返回被删除的元素
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

//可以用->操作符

void InitList(LinkList *l)
{
	//如要修改传进来的指针，把指针当做普通变量，普通变量要修改肯定不能传自身，要传它的指针
	//同样，如果要修改指针的值，必须传指针的指针，解引用后才能对该指针进行修改
	(*l) = new LinkNode();
	if(!(*l))
		exit(1);//非正常退出
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
	int j = 1;//因为p取的是第一个有值的结点，所以是1，如果是首结点，这里为0
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
	while(p->next)//因为第一个节点没有前驱，所以直接从第2个开始
	{
		q = p->next;//q为当前节点，p为上个节点
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
	while(p->next)//从第2个结点开始看是因为：先看当前结点p有没有后继结点，没有那就肯定没有下一个值
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
	int j = 0;//指首结点j=0，指第一个有值的结点就是1，没毛病啊
	LinkList p = L, s;
	while(p && j < i - 1)//跳出循环是i-1，为了寻找第i-1个结点,为什么判断p，因为第i个结点连在i-1个结点上，也就是因为j<i-1跳出循环时的p
	{
		p = p->next;
		j++;
	}
	if(!p)//如果超出长度
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
	while(p->next && j < i - 1)//此处为何是p->next，因为要删除i个结点，首先要判断i个结点是否存在，如果不存在，自然不能删除
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

