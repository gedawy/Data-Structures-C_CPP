/**************************************/
/* Author: Omar                       */
/* SW: Circular Queue                 */
/* Date: 18 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct  queue
{
    int Arr[MAX_SIZE];
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

    Queue_voidEnQueue(1,&q);
    Queue_voidEnQueue(2,&q);
    Queue_voidEnQueue(3,&q);
    Queue_voidEnQueue(4,&q);
    Queue_voidEnQueue(5,&q);
    Queue_voidEnQueue(6,&q);
    Queue_voidEnQueue(7,&q);
    Queue_voidEnQueue(8,&q);
    Queue_voidEnQueue(9,&q);
    Queue_voidEnQueue(10,&q);
    Queue_voidDeQueue(&q, &Front_Value);
    Queue_voidEnQueue(164,&q);

    size = Queue_intSize(&q);
    printf("The size is: %d\n",size);

    printf("Elements in the queue: \n"); 
    Queue_voidPrint(&q);
    printf("\n================================\n");

    printf("Dequeue one element: \n");
    Queue_voidDeQueue(&q, &Front_Value);
    printf("%d\n",Front_Value);
    printf("\n================================\n");

    printf("Print elements after dequeue\n");
    Queue_voidPrint(&q);
    printf("\n================================\n");

    size = Queue_intSize(&q);
    printf("The size after dequeue is %d\n",size);

    return 0;
}


//circular done
void Queue_voidInitQueue(Queue* pq){
    pq->Front = -1;
    pq->Rear = -1;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue,  Queue* pq){

    
    if(!Queue_intIsFull(pq)){
        
        //handle first element
        if (pq->Front == -1)
            pq->Front = 0;

        //use modulo operator to circulate
        pq->Rear = (pq->Rear + 1) % MAX_SIZE;

        //insert element in the result rear index
        pq->Arr[pq->Rear] = Copy_intValue;

        //increase the size
        pq->size++;

    } else{
        printf("The queue is full -- CANNOT INSERT!");
    }

}

void Queue_voidDeQueue(Queue* pq, int* pd){

    if(!Queue_intIsEmpty(pq)){

        //get element
        *pd = pq->Arr[pq->Front];

        //handle case of last element dequeued
        if(pq->Front == pq->Rear){
            pq->Front = -1;
            pq->Rear = -1;
        } 
        else{
        //increase front using modulo operator
        pq->Front = (pq->Front+1) % MAX_SIZE;
        }
        //decrease size
        pq->size--;

    }else{
        printf("Queue is Empty!!\n");
    }
}

//circular
void Queue_voidReturnValue(Queue* pq, int* pd){
    
    if(!Queue_intIsEmpty(pq)){
        *pd = pq->Arr[pq->Front];
    }
}

//circular done
int Queue_intIsEmpty(Queue* pq){
    return (pq->Front == -1);
}

//ciruclar done
int Queue_intIsFull(Queue* pq){
    return ((pq->Front == pq->Rear+1) || (pq->Front == 0 && pq->Rear == MAX_SIZE-1));
}

void Queue_voidPrint(Queue* pq){
    if(!Queue_intIsEmpty(pq)){
        int i;
        for(i = pq->Front; i != pq->Rear; i = ((i+1) %  MAX_SIZE)){

            printf("%d\n", pq->Arr[i]);
        }

        printf("%d ", pq->Arr[i]);
    }
    else{
        printf("Queue is Empty!!\n");
    }
}

int Queue_intSize(Queue* pq){
    return pq->size;
}