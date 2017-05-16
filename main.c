#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int main()
{
    /*// µ•¡¥±Ì≤‚ ‘”√¿˝
    LinkList L;
    InitLinkList(&L);
    TraverseLinkList(L, PrintLinkListElemData);
    */

    /*// À≥–Ú’ª≤‚ ‘”√¿˝
    SeqStack seqStack;
    int i;

    InitStack(&seqStack);
    Push(&seqStack, 1);
    Push(&seqStack, 2);
    Push(&seqStack, 3);

    printf("%d %d %d\n", i=Pop(&seqStack), Pop(&seqStack), Pop(&seqStack)); //¥””“Õ˘◊Ûº∆À„£¨”“Ω·∫œ–‘°£
    printf("%d\n", i); // 1
    //printf("%d\n", Pop(&seqStack));
    //printf("%d\n", Pop(&seqStack));
    //printf("%d\n", Pop(&seqStack));
    */

    /*// ¡¥’ª≤‚ ‘”√¿˝
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
