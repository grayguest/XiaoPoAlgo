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
}LNode, *LinkList;//��΢�޸�һ�£���LinkList��Ϊָ����

//linklist* CreateLinklist(void);//��Ϊ�����
Status InitList(LinkList *L);
//int InsertIntoLinlist(linklist *L, int x);//tail
//int PrintLinklist(linklist* L);//��Ϊ�����
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

//��������˳�������X���н���ֵ��һ���ַ������ݹ齨����X�����ո��ַ���ʾ������
//�����X�����ʾ�Ķ�X��T��
Status CreateBiTree(BiTree *T);
Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e));
Status InOrderTraverse(BiTree T, Status(* Visit)(TElemType e));
//���ʺ���
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
