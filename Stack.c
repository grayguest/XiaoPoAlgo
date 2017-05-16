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
    *((*S).top++) = e;
    return OK;
}


SElemType Pop(SeqStack *S)
{
    //判断栈是否为空
    if((*S).top == (*S).base) return ERROR;
    return *(--(*S).top);
}

Status StackEmpty(SeqStack S)
{
    if(S.top == S.base) return TRUE;
    else return FALSE;
}


Status InitLinkStack(LinkStack *S)
{
    int value;
    LinkStack head, p;
    //建立头节点
    *S = (LinkStack)malloc(sizeof(SNode));
    if(!(*S)) exit(OVERFLOW);
    (*S)->next = NULL;
    p = head = *S; //S其实指向得就是头结点!!!
    return OK;
}

Status LinkStackPush(LinkStack *S, SElemType e)
{
    //插入元素e为新的栈顶元素
    LinkStack p = (LinkStack)malloc(sizeof(SNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = (*S)->next;
    (*S)->next = p;

    return OK;
}

SElemType LinkStackPop(LinkStack *S)
{
    LinkStack p;

    //判断栈是否为空
    if((*S)->next == NULL) return ERROR;
    p = (*S)->next;
    SElemType se = p->data;
    (*S)->next = p->next;
    free(p);
    return se;
}

Status LinkStackEmpty(LinkStack *S)
{
    if((*S)->next == NULL) return TRUE;
    else return FALSE;
}

#endif // STACK_C_
