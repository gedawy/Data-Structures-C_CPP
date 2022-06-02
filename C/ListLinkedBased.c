/**************************************/
/* Author: Omar                       */
/* SW: Lst Linked Based               */
/* Date: 19 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ListEntry;

typedef struct listnode
{
    ListEntry Data;
    struct listnode* Next;

}ListNode;

typedef struct list
{
    int size;
    ListNode* head;

}List;


/********************************************/
/**********functions prototypes**************/
/********************************************/

void List_voidInit(List* pl);
void List_voidInsertList(int Pos, List* pl, int Copy_intValue);
void List_voidReplaceList(int Pos, List* pl, int Copy_intValue);
void List_voidDeleteList(int Pos, List* pl, int* pd);
void List_voidRetriveList(int Pos, List* pl, int* pd);
int List_intIsEmpty(List* pl);
int List_intIsFull(List* pl);
int List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);

int main(){
    int size, RetrievedVal;
    List L;
    List_voidInit(&L);

    List_voidInsertList(0,&L,11);
    List_voidInsertList(0,&L,7);
    List_voidInsertList(0,&L,4);

    size = List_intSize(&L);

    printf("The size of list is: %d\n",size);

    printf("The elements are:\n");
    List_voidPrint(&L);

    List_voidRetriveList(2,&L,&RetrievedVal);
    printf("Retrived vale is: %d\n",RetrievedVal);

    List_voidDeleteList(1,&L,&RetrievedVal);
    printf("Retrived vale is: %d\n",RetrievedVal);

    size = List_intSize(&L);

    printf("The size of list is: %d\n",size);

    printf("List after delete:\n");
    List_voidPrint(&L);

    List_voidDestroyList(&L);
    printf("List after destroy:\n");
    size = List_intSize(&L);
    printf("The size of list is: %d\n",size);

}

void List_voidInit(List* pl){
    pl->head = NULL;
    pl->size = 0;
}

int List_intIsEmpty(List* pl){
    return (pl->head == NULL);
}

int List_intIsFull(List* pl){
    return 0;
}

int List_intSize(List* pl){
    return (pl->size);
}


void List_voidInsertList(int Pos, List* pl, int Copy_intValue){
    /*1- Create a node*/
    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    ListNode* q;

    pn->Data = Copy_intValue;
    pn->Next = NULL;    

    if(Pos == 0){ //Inserting at first
        pn->Next = pl->head;
        pl->head = pn;
    }else
    {
        int i;
        for(q = pl->head, i = 0; i < Pos-1; i++){
            q = q->Next;
        }

        pn->Next = q->Next;
        q->Next = pn;
    }

    pl->size++;  
}

void List_voidReplaceList(int Pos, List* pl, int Copy_intValue){
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i <Pos; i++){
        q = q->Next;
    }

    q->Data = Copy_intValue;
}

void List_voidDeleteList(int Pos, List* pl, int* pd){

    int i;
    ListNode* q;
    ListNode* tmp;

    if(Pos == 0){
        *pd = pl->head->Data;

        tmp = pl->head->Next;

        free(pl->head);

        pl->head = tmp;
    }
    else{
        for(q= pl->head, i=0; i <Pos-1; i++){
            q = q->Next;
        }

        *pd = q->Next->Data;
        tmp = q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}

void List_voidRetriveList(int Pos, List* pl, int* pd){
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i <Pos; i++){
        q = q->Next;
    }

    *pd = q->Data;
}

void List_voidPrint(List* pl){

    ListNode* q;
    q = pl->head;

    while(q != NULL){
        printf("%d\n", q->Data);
        q = q->Next;
    }
}

void List_voidDestroyList(List* pl){
    ListNode* tmp;

    while(pl->head != NULL){ //!List_intIsEmpty(pl)

        tmp = pl->head->Next;

        free(pl->head);

        pl->head = tmp;
    }

    pl->size = 0;
}