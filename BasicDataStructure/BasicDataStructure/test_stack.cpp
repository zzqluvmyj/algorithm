#include "test_stack.h"
void testSqStack()
{
	cout << "˳��ջ����" << endl;
	SqStack s;
	cout << "��ʼ��" << endl;
	InitStack(&s);
	cout << "�������" << endl;
	for(int i = 0; i < 10; i++)
	{
		Push(&s, i);
	}
	cout << "ջ�ĳ���" << StackLength(&s)<<endl;
	cout << "��������" << endl;
	ElemType e;
	while(Pop(&s, &e))
		cout << e << " ";
	cout << endl;
	cout << "ջ�Ƿ�Ϊ�գ�" <<StackEmpty(&s) <<endl;
}
bool InitStack(SqStack *s);
bool DestroyStack(SqStack *s);
bool ClearStack(SqStack *s);
bool StackEmpty(SqStack *s);
int StackLength(SqStack *s);
bool Pop(SqStack *s, ElemType *e);
bool Push(SqStack *s, ElemType e);