#include "test_list.h"
#include "List.h"
#define N 15
#define M 40

int compare(ElemType e1, ElemType e2)
{
	return e1 - e2;

	/*
	if(e1 == e2)
		return 0;//��������ȵ�ʱ�򣬲��޷���Ϊ��ĸ
	return (e1 - e2) / abs(e1 - e2);
	*/
}
void vi(ElemType *e)
{
	*e = 2 * (*e);
}

void testSqList()
{
	cout << "˳������" << endl;
	SqList L;
	ElemType e,e1,e2;
	InitList(&L);
	cout << "��ʼ��" << endl;
	PrintList(&L);
	for(int i = 1; i <= 60; i++)
	{
		ListInsert(&L, i, (ElemType)i);
	}
	cout << "��ֵ���" << endl;
	PrintList(&L);
	cout << "���� " << ListLength(&L);
	GetElem(&L, N, &e);
	cout << "�� "<< N <<" ��Ԫ���� " << e<<endl;
	cout << "����Ƚ������ĵ�һ��ֵ������Ϊ" << LocateElem(&L, e, compare)<<endl;
	PriorElem(&L, e, &e1);
	NextElem(&L, e, &e2);
	cout << e<<"��ǰһ��Ԫ����" <<e1<<"��һ����"<<e2<< endl;
	ListTraverse(&L, vi);
	cout << "ת����" << endl;
	PrintList(&L);
	cout << "ɾ����"<<M <<"��Ԫ�غ�"<< endl;
	ListDelete(&L, M, &e);
	PrintList(&L);
	ClearList(&L);
	cout << "��պ�" << endl;
	PrintList(&L);
	cout << "�Ƿ���� " << ListEmpty(&L)<<endl;
	DestroyList(&L);
	cout << "�Ƿ����� " << (L.data==nullptr)<<endl;
	cout << "�������" << endl;
}

//���������
void testLinkList()
{
	cout << "���������" << endl;
	LinkList L;
	ElemType e, e1, e2;
	InitList(&L);
	cout << "��ʼ��" << endl;
	PrintList(L);
	for(int i = 1; i <= 60; i++)
	{
		ListInsert(L, i, (ElemType)i);
	}
	cout << "��ֵ���" << endl;
	PrintList(L);
	cout << "���� " << ListLength(L);
	GetElem(L, N, &e);
	cout << "�� " << N << " ��Ԫ���� " << e << endl;
	cout << "����Ƚ������ĵ�һ��ֵ������Ϊ" << LocateElem(L, e, compare) << endl;
	PriorElem(L, e, &e1);
	NextElem(L, e, &e2);
	cout << e << "��ǰһ��Ԫ����" << e1 << "��һ����" << e2 << endl;
	ListTraverse(L, vi);
	cout << "ת����" << endl;
	PrintList(L);
	cout << "ɾ����" << M << "��Ԫ�غ�" << endl;
	ListDelete(L, M, &e);
	PrintList(L);
	ClearList(&L);
	cout << "��պ�" << endl;
	PrintList(L);
	cout << "�Ƿ���� " << ListEmpty(L) << endl;
	DestroyList(&L);
	cout << "�Ƿ����� " << (L == nullptr) << endl;
	cout << "�������" << endl;
}

