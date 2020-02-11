#include "test_stack.h"
void testSqStack()
{
	cout << "顺序栈测试" << endl;
	SqStack s;
	cout << "初始化" << endl;
	InitStack(&s);
	cout << "添加数据" << endl;
	for(int i = 0; i < 10; i++)
	{
		Push(&s, i);
	}
	cout << "栈的长度" << StackLength(&s)<<endl;
	cout << "弹出数据" << endl;
	ElemType e;
	while(Pop(&s, &e))
		cout << e << " ";
	cout << endl;
	cout << "栈是否为空？" <<StackEmpty(&s) <<endl;
}
bool InitStack(SqStack *s);
bool DestroyStack(SqStack *s);
bool ClearStack(SqStack *s);
bool StackEmpty(SqStack *s);
int StackLength(SqStack *s);
bool Pop(SqStack *s, ElemType *e);
bool Push(SqStack *s, ElemType e);