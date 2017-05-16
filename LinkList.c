//LinkList.c
//[2014/12/12]
//xiaopo

#ifndef LINKLIST_C_
#define LINKLIST_C_


#include "common.h"

//linklist* CreateLinklist(){
//    linklist* L;
//    L = (lnode*)malloc(sizeof(lnode));
//    if(!L) return 0;
//    L->next = NULL;
//    return L;
//}

Status InitLinkList(LinkList *L)
{
    int value;
    LinkList head, p;
    //����ͷ�ڵ�
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)) exit(OVERFLOW);
    (*L)->next = NULL;
    p = head = *L;
    printf("���������ֵ:_\b(�Կո�ֿ�),��#�Ž���");
    while(1 == scanf("%d", &value)){
        LinkList q;
        q = (LinkList)malloc(sizeof(LNode));
        if(!q) exit(OVERFLOW);
        q->data = value;
        //ͷ�巨����
        /*
        q->next = (*L)->next;//�˴�������������*L������ֵ����ӦΪ�����ò����ı������������޸ĶԺ���������Ӱ��ģ�����
        (*L)->next = q;
        */
        //β�巨����
        q->next = p->next;
        p->next = q;
        p = q;
    }
    return OK;
}

////tail
//int InsertIntoLinlist(linklist *L, int x){
//    if(!L) return 0;
//    lnode* p;
//    p = (lnode*)malloc(sizeof(lnode));
//    p->next = NULL;
//    p->data = x;
//    p->next = L->next;
//    L->next = p;
//    return 1;
//}

//int PrintLinklist(linklist* L){
//    if(!L || !L->next) return 0;
//    lnode* p;
//    p = L->next;
//    while(p){
//        printf("%d", p->data);
//        p = p->next;
//    }
//    return 1;
//}

Status TraverseLinkList(LinkList L, Status (*Visit)(ElemType e))
{
    LinkList p = L;
    p = p->next;//��ͷ����ƶ�����ʼ���
    while(p){
        (*Visit)(p->data);
        p = p->next;
    }
}

Status PrintLinkListElemData(ElemType e)
{
    printf("%d ", (int)e);
}

/*
int SortLinklist(linklist* L){
    if(!L || !L->next) return 0;
    lnode *over, *temp, *pir;
    int flag;
    pir = L;
    over = L;
    while(pir->next->next){
            flag = 1;
            pir = L;
            while(pir->next->next != over && pir->next->next){
                if(pir->next->data > pir->next->next->data){
                    temp = pir->next;
                    pir->next = pir->next->next;
                    temp->next = pir->next->next;
                    pir->next->next = temp;
                    flag = 0;
                }
                pir = pir->next;
            }
        over = pir->next;
    }
    return 1;
}*/

#endif // LINKLIST_C_
