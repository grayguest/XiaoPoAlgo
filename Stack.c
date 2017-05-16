//Stack.c
//[2014/12/11]
//xiaopo

#ifndef STACK_C_
#define STACK_C_

#include "common.h"

//实现
Status InitStack(SeqStack *S)
{
    //构造一个空栈S
    (*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!(*S).base) exit(OVERFLOW);
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SeqStack *S, SElemType e)
{
    //插入元素e为新的栈顶元素
    //判断栈是否已经满了，如果满了就要追加空间
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
    //判断栈是否为空
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
