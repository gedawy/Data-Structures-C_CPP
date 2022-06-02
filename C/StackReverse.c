/**************************************/
/* Author: Omar                       */
/* SW: Stack Array Based Reverse      */
/* Date: 15 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct stack{
    char Arr[MAX_SIZE];
    int top;
}Stack;

/**************************************/
/**********function prototypes*********/
/**************************************/

void Stack_voidInit(Stack *ps);
void Stack_voidPush(char copy_IntValue, Stack *ps);
int Stack_intPop(Stack *ps);
int Stack_voidIsEmpty(Stack *ps);
int Stack_voidIsFull(Stack *ps);
void Stack_voidPrint(Stack *ps);
void Stack_voidReverse(Stack *ps, char *arr,int size);

int main(){
    Stack s;
    Stack *ps = &s;
    char name[4] = "Omar";

    printf("%s",name);

    Stack_voidInit(ps);
    Stack_voidPush(name[0], ps);
    Stack_voidPush(name[1], ps);
    Stack_voidPush(name[2], ps);
    Stack_voidPush(name[3], ps);

    Stack_voidReverse(ps,name,4);

    printf("%s",name);

    //ex 1
    //Stack s;
    //Stack *ps = &s;

    /*Stack_voidInit(ps);
    Stack_voidPush(3, ps);
    Stack_voidPush(4, ps);
    Stack_voidPush(5, ps);*/

    //int popped = Stack_intPop(ps);

    //Stack_voidPrint(ps);

 return 0;
}

/**************************************/
/******function implementation*********/
/**************************************/

void Stack_voidInit(Stack *ps){
    ps -> top = -1;
}
void Stack_voidPush(char copy_CharValue, Stack *ps){
    if(!Stack_voidIsFull(ps)){
        ps -> top++;
        ps->Arr[ps->top] = copy_CharValue;
         
    }
    else {
        printf("THE STACK IS FULL!");
    }
}
int Stack_intPop(Stack *ps){
    if(!Stack_voidIsEmpty(ps)){
        int val = ps->Arr[ps->top];
        ps->top--;
        return val;
    }else{
        printf("THE STACK IS EMPTY!");
    }
}

int Stack_voidIsEmpty(Stack *ps){
    return (ps->top) == -1;
}

int Stack_voidIsFull(Stack *ps){
    return (ps->top) == (MAX_SIZE - 1);
}

void Stack_voidPrint(Stack *ps){
    int currTop = ps->top;

    while(currTop != -1){
        printf("%d\n",ps->Arr[currTop]);
        currTop -= 1;
    }
}

void Stack_voidReverse(Stack *ps, char *arr, int size){
    //int size = sizeof(arr) / sizeof(char);
    int i;
    for(i = 0; i<size; i++){
        arr[i] = Stack_intPop(ps);
    }
}

