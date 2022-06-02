/**************************************/
/* Author: Omar                       */
/* SW: Stack Linked Based             */
/* Date: 16 Dec 2021                  */
/* Version: V1.0                      */
/**************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct stacknode{
    int data;
    struct stacknode* next;
}StackNode;

typedef struct stack{
    int size;
    StackNode* top;
}Stack;

/**************************************/
/**********function prototypes*********/
/**************************************/

void Stack_voidInit(Stack *ps);
void Stack_voidPush(int copy_IntValue, Stack *ps);
int Stack_intPop(Stack *ps);
int Stack_voidIsEmpty(Stack *ps);
int Stack_voidIsFull(Stack *ps);
void Stack_voidPrint(Stack *ps);
void Stack_voidSize(Stack *ps, int* topVal);
int Stack_getMin(Stack *ps);
void Stack_clearstk(Stack *ps);

int main(){
    Stack s;
    Stack *ps = &s;

    Stack_voidInit(ps);
    Stack_voidPush(9, ps);
    Stack_voidPush(7, ps);
    Stack_voidPush(3, ps);
    Stack_voidPush(5, ps);
    Stack_voidPush(4, ps);

    Stack_intPop(ps);
    Stack_intPop(ps);

    Stack_voidPrint(ps);

    printf("The min element is %d\n",Stack_getMin(ps));

    //clear
    printf("The stack after being cleared\n");
    Stack_clearstk(ps);
    Stack_voidPrint(ps);

 return 0;
}

/**************************************/
/******function implementation*********/
/**************************************/


void Stack_voidInit(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
    
}
void Stack_voidPush(int copy_IntValue, Stack *ps){
    //1- Create new node
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = copy_IntValue;
    node->next = ps->top;
    //2- modify the first node
    ps->top = node;
    //3- increment the size
    ps->size++;
}
int Stack_intPop(Stack *ps){

    //get the first element
    StackNode* pn = ps->top;

    //get data
    int data = pn->data;

    //move the top to the node that was previously the next of the top
    ps->top = ps->top->next;

    //free the pn
    free(pn);

    ps->size--;
}

int Stack_voidIsEmpty(Stack *ps){
    return (ps->top  == NULL);
}

int Stack_voidIsFull(Stack *ps){
    return 0;
}

void Stack_voidPrint(Stack *ps){
    StackNode* pn = ps->top;

    while(pn != NULL){
        printf("%d\n", pn->data);
        pn = pn->next;
    }
}

void Stack_voidSize(Stack *ps, int* topVal){
    *topVal = ps->size;
}

int Stack_getMin(Stack *ps){
    StackNode* pn = ps->top;
    int min = pn->data;
    while(pn != NULL){
        if(pn->data < min) min = pn->data;
        //printf("%d\n", pn->data);
        pn = pn->next;
    }
    return min;
}

void Stack_clearstk(Stack *ps){
    StackNode* pn = ps->top;

    while(pn != NULL){

    //get the top element
    pn = ps->top;

    //move the top to the node that was previously the next of the top
    ps->top = ps->top->next;

    //free the pn
    free(pn);

    ps->size--;
    }
}