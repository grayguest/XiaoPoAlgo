#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int main()
{
    /*// �������������
    LinkList L;
    InitLinkList(&L);
    TraverseLinkList(L, PrintLinkListElemData);
    */

    /*// ˳��ջ��������
    SeqStack seqStack;
    int i;

    InitStack(&seqStack);
    Push(&seqStack, 1);
    Push(&seqStack, 2);
    Push(&seqStack, 3);

    printf("%d %d %d\n", i=Pop(&seqStack), Pop(&seqStack), Pop(&seqStack)); //����������㣬�ҽ���ԡ�
    printf("%d\n", i); // 1
    //printf("%d\n", Pop(&seqStack));
    //printf("%d\n", Pop(&seqStack));
    //printf("%d\n", Pop(&seqStack));
    */

    /*// ��ջ��������
    LinkStack S;
    InitLinkStack(&S);
    LinkStackPush(&S, 1);
    LinkStackPush(&S, 2);
    LinkStackPush(&S, 3);
    printf("%d\n", LinkStackPop(&S));
    printf("%d\n", LinkStackPop(&S));
    printf("%d\n", LinkStackPop(&S));



//    BiTree T;
//    CreateBiTree(&T);
//    PreOrderTraverse(T, PrintTElemData);


    return 0;
}
