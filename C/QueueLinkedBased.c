/**************************************/
/* Author: Omar                       */
/* SW: Queue Linked Based             */
/* Date: 18 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/


#include <stdio.h>
#include <stdlib.h>



typedef  struct queuenode
{
    int data;
    struct queuenode* Next;
    
}QueueNode;

typedef struct queue
{
    QueueNode* Front;
    QueueNode* Rear;
    int size;
}Queue;




/**************************************/
/**********function prototypes*********/
/**************************************/

void Queue_voidInitQueue(Queue* pq);
void Queue_voidEnQueue(int Copy_intValue,  Queue* pq);
void Queue_voidDeQueue(Queue* pq, int* pd);
int Queue_intIsEmpty(Queue* pq);
int Queue_intIsFull(Queue* pq);
void Queue_voidPrint(Queue* pq);
int Queue_intSize(Queue* pq);
void Queue_voidClear(Queue* pq);

int main(){
    int Front_Value, size;
    Queue q;
    Queue_voidInitQueue(&q);

    Queue_voidEnQueue(5,&q);
    Queue_voidEnQueue(12,&q);
    Queue_voidEnQueue(7,&q);
    Queue_voidEnQueue(3,&q);

    size = Queue_intSize(&q);
    printf("The size is: %d\n",size);

    printf("Print queue\n");
    Queue_voidPrint(&q);
    printf("================================\n");

    Queue_voidDeQueue(&q, &Front_Value);
    printf("The dequed value: %d\n",Front_Value);

    printf("Print again after deque\n");
    Queue_voidPrint(&q);
    printf("================================\n");

    size = Queue_intSize(&q);
    printf("The new size: %d\n",size);

    printf("Clearing:\n");
    Queue_voidClear(&q);

    printf("Queue after clearing:\n");
    Queue_voidPrint(&q);

    return 0;
}



void Queue_voidInitQueue(Queue* pq){

    pq->Front = NULL;
    pq->Rear = NULL;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue,  Queue* pq){

    //1- create node
    QueueNode* pn= (QueueNode*)malloc(sizeof(QueueNode));
    
    //2- assign value of node to the data field
    pn->data = Copy_intValue;

    //3- assign null as next of allocated node
    pn->Next = NULL;

    if(pq->Front == NULL){
        pq->Front = pn;
    }else{
        // update next of rear
        pq->Rear->Next = pn;
    }

    //update rear
    pq->Rear = pn;

    pq->size++;
}

void Queue_voidDeQueue(Queue* pq, int* pd){

    //1- make pointer to holde dequeued node
    QueueNode* pn = pq->Front;
    
    //2-return data
    *pd = pn->data;

    //3-front node
    pq->Front = pq->Front->Next;

    //4-deallocate
    free(pn);

    //5- handle last node
    if(pq->Front == NULL){
        pq->Rear = NULL;
    }

    //6- decrement size
    pq->size--;
}

void Queue_voidReturnValue(Queue* pq, int* pd){
    
    if(!Queue_intIsEmpty(pq)){
        *pd = pq->Front->data;
    }
}

int Queue_intIsEmpty(Queue* pq){
    return (pq->Front == NULL);
}

int Queue_intIsFull(Queue* pq){
    return 0;
}

void Queue_voidPrint(Queue* pq){
    QueueNode* pn = pq->Front;
    
    if(pn == NULL) printf("This is an empty queue, NOTHING TO PRINT!!!");
    while(pn!=NULL){
        printf("%d\n", pn->data);
    
        pn = pn->Next;
    }
}

int Queue_intSize(Queue* pq){
    return pq->size;
}

void Queue_voidClear(Queue* pq){
    QueueNode* pn = pq->Front;

    while(pq->Front!=NULL){
        pn = pq->Front;
        pq->Front = pq->Front->Next;
        
        free(pn);
    }
}