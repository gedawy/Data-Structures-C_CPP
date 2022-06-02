/**************************************/
/* Author: Omar                       */
/* SW: Queue Array Based + sort       */
/* Date: 18 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

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
void Queue_SelectSort(Queue* pq);
void selectionSort(Queue* pq);

int main(){
    int Front_Value, size;
    Queue q;
    Queue_voidInitQueue(&q);

    //Queue_voidEnQueue(1,&q);
    //Queue_voidEnQueue(2,&q);
    //Queue_voidEnQueue(4,&q);
    //Queue_voidEnQueue(3,&q);

    //Queue_voidEnQueue(2,&q);
    //Queue_voidEnQueue(5,&q);
    //Queue_voidEnQueue(8,&q);
    //Queue_voidEnQueue(6,&q);


    Queue_voidEnQueue(1,&q);
    Queue_voidEnQueue(5,&q);
    Queue_voidEnQueue(8,&q);
    Queue_voidEnQueue(7,&q);
    Queue_voidEnQueue(6,&q);
    Queue_voidEnQueue(16,&q);

    size = Queue_intSize(&q);
    printf("The size is: %d\n",size);

    printf("The array is\n");
    Queue_voidPrint(&q);
    printf("\n================================\n");

    printf("The dequeued value: \n");
    Queue_voidDeQueue(&q, &Front_Value);
    printf("%d\n",Front_Value);
    Queue_voidDeQueue(&q, &Front_Value);

    printf("Queue after dequeue: \n");
    Queue_voidPrint(&q);
    printf("\n================================\n");

    printf("The new size: \n");
    size = Queue_intSize(&q);
    printf("%d\n",size);

    printf("The sorted Queue: \n");
    Queue_SelectSort(&q);
    //selectionSort(&q);
    Queue_voidPrint(&q);
    printf("\n================================\n");

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
    return (pq->Rear == MAX_SIZE-1);
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

void swap(Queue* pq, int idx1, int idx2){
    int temp = pq->Arr[idx1];
    pq->Arr[idx1] = pq->Arr[idx2];
    pq->Arr[idx2] = temp;
}

void Queue_SelectSort(Queue* pq){
    int i, j, min;

    for(i = pq->Front; i < pq->Front + pq->size -1; i++){
        min = i;
        
        for(j = i+1; j< pq->Front + pq->size; j++) 
            if(pq->Arr[j] < pq->Arr[min]) min = j;

       
        swap(pq, i, min);
    }
}

