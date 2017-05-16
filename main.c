#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int main()
{

    LinkList L;
    InitList(&L);
    ListTraverse(L, PrintLinkListElemData);

//    BiTree T;
//    CreateBiTree(&T);
//    PreOrderTraverse(T, PrintTElemData);


    return 0;
}
