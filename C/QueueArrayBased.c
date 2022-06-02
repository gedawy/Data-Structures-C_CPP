/**************************************/
/* Author: Omar                       */
/* SW: Queue Array Based              */
/* Date: 18 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SZIE 100

typedef struct  queue
{
    int Arr[MAX_SZIE];
    int Front;
    int Rear;
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

int main(){
    int Front_Value, size;
    Queue q;
    Queue_voidInitQueue(&q);

    Queue_voidEnQueue(5,&q);
    Queue_voidEnQueue(12,&q);
    Queue_voidEnQueue(7,&q);
    Queue_voidEnQueue(3,&q);

    size = Queue_intSize(&q);
    printf("%d\n",size);

    Queue_voidPrint(&q);
    printf("\n================================\n");

    Queue_voidDeQueue(&q, &Front_Value);
    printf("%d\n",Front_Value);

    Queue_voidPrint(&q);
    printf("\n================================\n");

    size = Queue_intSize(&q);
    printf("%d\n",size);

    return 0;
}



void Queue_voidInitQueue(Queue* pq){

    pq->Front = -1;
    pq->Rear = -1;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue,  Queue* pq){

    
    if(!Queue_intIsFull(pq)){
        if(Queue_intIsEmpty(pq)) pq->Front = 0; //handling the first enque operation
   
        pq->Rear++;
        pq->Arr[pq->Rear] = Copy_intValue;

        pq->size++;
    }  

}

void Queue_voidDeQueue(Queue* pq, int* pd){

    if(!Queue_intIsEmpty(pq)){
        *pd = pq->Arr[pq->Front];

        pq->Front++;

        pq->size--;

        if(pq->Front > pq->Rear){
            pq->Front = pq->Rear = -1;
            pq->size = 0;
        }
    }else{
        printf("Queue is Empty!!\n");
    }
}

void Queue_voidReturnValue(Queue* pq, int* pd){
    
    if(!Queue_intIsEmpty(pq)){
        *pd = pq->Arr[pq->Front];
    }
}

int Queue_intIsEmpty(Queue* pq){
    return (pq->Front == -1);
}

int Queue_intIsFull(Queue* pq){
    return (pq->Rear == MAX_SZIE-1);
}

void Queue_voidPrint(Queue* pq){
    if(!Queue_intIsEmpty(pq)){
        for(int i = pq->Front; i<= pq->Rear; i++){

            printf("%d\n", pq->Arr[i]);
        }
    }
    else{
        printf("Queue is Empty!!\n");
    }
}

int Queue_intSize(Queue* pq){
    return pq->size;
}