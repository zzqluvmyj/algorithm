#include "test_list.h"
#include "List.h"
#define N 15
#define M 40

int compare(ElemType e1, ElemType e2)
{
	return e1 - e2;

	/*
	if(e1 == e2)
		return 0;//当两者相等的时候，差无法作为分母
	return (e1 - e2) / abs(e1 - e2);
	*/
}
void vi(ElemType *e)
{
	*e = 2 * (*e);
}

void testSqList()
{
	cout << "顺序表测试" << endl;
	SqList L;
	ElemType e,e1,e2;
	InitList(&L);
	cout << "初始化" << endl;
	PrintList(&L);
	for(int i = 1; i <= 60; i++)
	{
		ListInsert(&L, i, (ElemType)i);
	}
	cout << "赋值完成" << endl;
	PrintList(&L);
	cout << "长度 " << ListLength(&L);
	GetElem(&L, N, &e);
	cout << "第 "<< N <<" 个元素是 " << e<<endl;
	cout << "满足比较条件的第一个值的坐标为" << LocateElem(&L, e, compare)<<endl;
	PriorElem(&L, e, &e1);
	NextElem(&L, e, &e2);
	cout << e<<"的前一个元素是" <<e1<<"后一个是"<<e2<< endl;
	ListTraverse(&L, vi);
	cout << "转换后" << endl;
	PrintList(&L);
	cout << "删除第"<<M <<"个元素后"<< endl;
	ListDelete(&L, M, &e);
	PrintList(&L);
	ClearList(&L);
	cout << "清空后" << endl;
	PrintList(&L);
	cout << "是否清空 " << ListEmpty(&L)<<endl;
	DestroyList(&L);
	cout << "是否销毁 " << (L.data==nullptr)<<endl;
	cout << "测试完成" << endl;
}

//单链表测试
void testLinkList()
{
	cout << "单链表测试" << endl;
	LinkList L;
	ElemType e, e1, e2;
	InitList(&L);
	cout << "初始化" << endl;
	PrintList(L);
	for(int i = 1; i <= 60; i++)
	{
		ListInsert(L, i, (ElemType)i);
	}
	cout << "赋值完成" << endl;
	PrintList(L);
	cout << "长度 " << ListLength(L);
	GetElem(L, N, &e);
	cout << "第 " << N << " 个元素是 " << e << endl;
	cout << "满足比较条件的第一个值的坐标为" << LocateElem(L, e, compare) << endl;
	PriorElem(L, e, &e1);
	NextElem(L, e, &e2);
	cout << e << "的前一个元素是" << e1 << "后一个是" << e2 << endl;
	ListTraverse(L, vi);
	cout << "转换后" << endl;
	PrintList(L);
	cout << "删除第" << M << "个元素后" << endl;
	ListDelete(L, M, &e);
	PrintList(L);
	ClearList(&L);
	cout << "清空后" << endl;
	PrintList(L);
	cout << "是否清空 " << ListEmpty(L) << endl;
	DestroyList(&L);
	cout << "是否销毁 " << (L == nullptr) << endl;
	cout << "测试完成" << endl;
}

