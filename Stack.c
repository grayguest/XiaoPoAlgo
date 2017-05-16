//Stack.c
//[2014/12/11]
//xiaopo

#ifndef STACK_C_
#define STACK_C_

#include "common.h"

//ʵ��
Status InitStack(SeqStack *S)
{
    //����һ����ջS
    (*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!(*S).base) exit(OVERFLOW);
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SeqStack *S, SElemType e)
{
    //����Ԫ��eΪ�µ�ջ��Ԫ��
    //�ж�ջ�Ƿ��Ѿ����ˣ�������˾�Ҫ׷�ӿռ�
    if((*S).top == (*S).base + (*S).stacksize){
        (*S).base = (SElemType*)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!(*S).base) exit(OVERFLOW);
        (*S).stacksize += STACKINCREMENT;
    }
    *(*S).top++ = e;
    return OK;
}


Status Pop(SeqStack *S, SElemType *e)
{
    //�ж�ջ�Ƿ�Ϊ��
    if((*S).top == (*S).base) return ERROR;
    *e = *--(*S).top;
    return OK;
}

Status StackEmpty(SeqStack S)
{
    if(S.top == S.base) return TRUE;
    else return FALSE;
}

#endif // STACK_C_
