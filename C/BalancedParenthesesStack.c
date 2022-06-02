/**************************************/
/* Author: Omar                       */
/* SW: Stack Balanced Parentheses     */
/* Version: V1.0                      */
/**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int Stack_intBalanced(Stack *ps, char *arr,int size);
int main(){

    Stack s;
    Stack *ps = &s;

    char bracket[11] = "{}[]()(){}";

    int sz = strlen(bracket);
    
    Stack_voidInit(ps);
    if(Stack_intBalanced(ps,bracket,sz)){
        printf("THE BRACKETS ARE BALANCED!!!");
    }

    /*Stack s;
    Stack *ps = &s;
    char name[4] = "Omar";

    printf("%s",name);

    Stack_voidInit(ps);
    Stack_voidPush(name[0], ps);
    Stack_voidPush(name[1], ps);
    Stack_voidPush(name[2], ps);
    Stack_voidPush(name[3], ps);

    Stack_voidReverse(ps,name,4);

    printf("%s",name);*/
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
        printf("%c\n",ps->Arr[currTop]);
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

//CHALLENGE
int Stack_intBalanced(Stack *ps, char *arr,int size){
    int i;
    //int top = ps->top;
    for(i = 0; i<size; i++){
        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '['){
            Stack_voidPush(arr[i],ps);
        }else if(arr[i] == ')' || arr[i] == '}' || arr[i] == ']'){
            if(arr[i] == ')' && ps->Arr[ps->top] == '('){
                Stack_intPop(ps);
                //top--;
            }
            else if(arr[i] == '}' && ps->Arr[ps->top] == '{'){
                Stack_intPop(ps);
                //top--;
            }
            else if(arr[i] == ']' && ps->Arr[ps->top] == '['){
                Stack_intPop(ps);
                //top--;
            }else{
                printf("%s","7ARAAAAAAM");
            }

        }
    }
    Stack_voidPrint(ps);
    printf("%d\n",ps->top);
    printf("%c\n", ps->Arr[ps->top]);
    printf("%s\n", arr);
    printf("%d",Stack_voidIsEmpty(ps));
    return Stack_voidIsEmpty(ps);
}