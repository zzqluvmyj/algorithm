#pragma once
#include "base.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 50
struct SqStack
{
	ElemType *base;//Õ»µ×Ö¸Õë
	ElemType *top;//Õ»¶¥Ö¸Õë
	int size;
};

bool InitStack(SqStack *s);
bool DestroyStack(SqStack *s);
bool ClearStack(SqStack *s);
bool StackEmpty(SqStack *s);
int StackLength(SqStack *s);
bool Pop(SqStack *s, ElemType *e);
bool Push(SqStack *s, ElemType e);
