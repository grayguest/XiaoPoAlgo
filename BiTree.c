//BiTree.c
//[2014/12/11]
//xiaopo

#ifndef BITREE_C_
#define BITREE_C_

#include "common.h"

Status CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == '#') *T = NULL;//#代表空格
    else{
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if(NULL == *T) exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e))
{
    BiTree p = T;
    SeqStack S;
    InitStack(&S);
    while(p != NULL || !StackEmpty(S)){
        while(p){
            (*Visit)(p->data);
            Push(&S, (SElemType)p);
            p = p->lchild;
        }
        if(!StackEmpty(S)){
            p = Pop(&S);
            p = p->rchild;
        }
    }
}

Status PrintTElemData(TElemType e)
{
    putchar((char)e);
    return OK;
}


#endif // BITREE_C_
