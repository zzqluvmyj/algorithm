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
	return s->top-s->base;//直接用指针相减计算栈的大小，这样最简单，复杂度也最低
}
bool Pop(SqStack *s, ElemType *e)
{
	if(s->base == s->top)return false;
	else
	{
		*e = *(--s->top);//因为top在栈顶元素的上一个位置，要取到栈顶元素需要首先减一
		return true;
	}
}
bool Push(SqStack *s, ElemType e)
{
	if(StackLength(s) == s->size)//如果栈满了，需要转移元素
	{
		s->base = (ElemType *)realloc(s->base,sizeof(ElemType)*( s->size + STACKINCREMENT));
		if(!s->base) exit(OVERFLOW);
		s->size += STACKINCREMENT;
		s->top = s->base + s->size;
		//此处需要特别注意，因为s->base可能由于原有的位置的后续空间不足，不能继续扩充，所以s->base有可能不是原来的位置（这会自动更新）
		//所以s->top有可能不是原来的位置的最后一个，所以需要更新
	}
	*(s->top++) = e;
	return true;
}