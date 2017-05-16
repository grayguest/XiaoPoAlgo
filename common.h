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

//常用工具集
int gcd(int m, int n); //求两个整数的最大公约数


//LinkList
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;//稍微修改一下，把LinkList改为指针型

//linklist* CreateLinklist(void);//改为下面的
//Status init_linklist(LinkList *L); //不要改成这种，因为它不像是STL那样是一种纯粹的算法，应用于容器。
Status InitLinkList(LinkList *L); //改为这种，首字母也不要小写，因为它可以独挡一面，并非属于某类或某结构体。
//int InsertIntoLinlist(linklist *L, int x);//tail
//int PrintLinklist(linklist* L);//改为下面的
Status TraverseLinkList(LinkList L, Status (*Visit)(ElemType e));
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
Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e)); //前序遍历
Status InOrderTraverse(BiTree T, Status(* Visit)(TElemType e));  //后序遍历
//访问函数
Status PrintTElemData(TElemType e);



//Stack
typedef int SElemType;
typedef struct SeqStack{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SeqStack;
Status InitStack(SeqStack *S);
Status Push(SeqStack *S, SElemType e);
Status Pop(SeqStack *S);
Status StackEmpty(SeqStack S);

//LinkStack
typedef int SElemType;
typedef struct LStackNode{
    SElemType data;
    struct LStackNode* next;
}SNode, *LinkStack;

Status InitLinkStack(LinkStack *S);


//Queue




#endif // COMMON_H_
