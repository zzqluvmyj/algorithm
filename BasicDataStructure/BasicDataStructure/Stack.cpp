#include "Stack.h"

bool InitStack(SqStack *s)
{
	s->base = new ElemType[STACK_INIT_SIZE]();
	if(!s->base) exit(OVERFLOW);
	s->top = s->base;
	s->size = STACK_INIT_SIZE;
	return true;
}
bool DestroyStack(SqStack *s)
{
	delete[] s->base;
	s->base = nullptr;
	s->top = nullptr;
	s->size = 0;
	return true;
}
bool ClearStack(SqStack *s)
{
	s->top = s->base;
	return true;
}
bool StackEmpty(SqStack *s)
{
	if(s->base==s->top) return true;
	else return false;
}
int StackLength(SqStack *s)
{
	return s->top-s->base;//ֱ����ָ���������ջ�Ĵ�С��������򵥣����Ӷ�Ҳ���
}
bool Pop(SqStack *s, ElemType *e)
{
	if(s->base == s->top)return false;
	else
	{
		*e = *(--s->top);//��Ϊtop��ջ��Ԫ�ص���һ��λ�ã�Ҫȡ��ջ��Ԫ����Ҫ���ȼ�һ
		return true;
	}
}
bool Push(SqStack *s, ElemType e)
{
	if(StackLength(s) == s->size)//���ջ���ˣ���Ҫת��Ԫ��
	{
		s->base = (ElemType *)realloc(s->base,sizeof(ElemType)*( s->size + STACKINCREMENT));
		if(!s->base) exit(OVERFLOW);
		s->size += STACKINCREMENT;
		s->top = s->base + s->size;
		//�˴���Ҫ�ر�ע�⣬��Ϊs->base��������ԭ�е�λ�õĺ����ռ䲻�㣬���ܼ������䣬����s->base�п��ܲ���ԭ����λ�ã�����Զ����£�
		//����s->top�п��ܲ���ԭ����λ�õ����һ����������Ҫ����
	}
	*(s->top++) = e;
	return true;
}