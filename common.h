//common.h
//[2014/12/11]
//xiaopo


#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef int Status;


//LinkList
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct Lnode* next;
}LNode, *LinkList;//稍微修改一下，把LinkList改为指针型

//linklist* CreateLinklist(void);//改为下面的
Status InitList(LinkList *L);
//int InsertIntoLinlist(linklist *L, int x);//tail
//int PrintLinklist(linklist* L);//改为下面的
Status ListTraverse(LinkList L, Status (*Visit)(ElemType e));
Status PrintLinkListElemData(ElemType e);

//Stack
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10


//BiTree
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTree * lchild;
    struct BiTree * rchild;
} BiTNode,*BiTree;

//按照先序顺序输入二X树中结点的值（一个字符），递归建立二X树，空格字符表示空树，
//构造二X链表表示的二X树T。
Status CreateBiTree(BiTree *T);
Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e));
Status InOrderTraverse(BiTree T, Status(* Visit)(TElemType e));
//访问函数
Status PrintTElemData(TElemType e);


//Stack
typedef BiTree SElemType;
typedef struct SeqStack{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SeqStack;
Status InitStack(SeqStack *S);
Status Push(SeqStack *S, SElemType e);
Status Pop(SeqStack *S, SElemType *e);
Status StackEmpty(SeqStack S);


#endif // COMMON_H_
