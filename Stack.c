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
    *((*S).top++) = e;
    return OK;
}


SElemType Pop(SeqStack *S)
{
    //�ж�ջ�Ƿ�Ϊ��
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
    //����ͷ�ڵ�
    *S = (LinkStack)malloc(sizeof(SNode));
    if(!(*S)) exit(OVERFLOW);
    (*S)->next = NULL;
    p = head = *S; //S��ʵָ��þ���ͷ���!!!
    return OK;
}

Status LinkStackPush(LinkStack *S, SElemType e)
{
    //����Ԫ��eΪ�µ�ջ��Ԫ��
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

    //�ж�ջ�Ƿ�Ϊ��
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
