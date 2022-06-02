#include<iostream>
#include <string>
using namespace std;

const int size = 20;

class stack{
private:
	int top;
	int st[size];

public:
	stack(){
		top = -1;
	}

	bool isFull(){
		if (top == size - 1){
			cout << "stack is full";
			return true;
		}
		else
			return false;
	}

	bool isEmpty(){
		if (top == -1){
			cout << "stack is empty";
			return true;
		}
		else
			return false;
	}

	void push(int x){
		if (!isFull()){
			top++;
			st[top] = x;
		}
	}

	int pop(){
		if (!isEmpty()){
			int temp;
			temp = st[top];
			top--;
			return temp;
		}
		else
			return 0;
	}

	void display(){
		for (int i = top; i >= 0; i--){
			cout << "Element: " << st[i] << endl;
		}
	}

};

int evaluate(char arr[],int number){
	int pop1;
	int pop2;
	int value = 0;
	int i = 0;

	stack s;

	while (arr[i] != '\0' && i < number){
		if (isdigit(arr[i]))
			s.push((float)arr[i]-'0');

		else {
			pop1 = s.pop();
			pop2 = s.pop();
		  
			switch (arr[i]){
			case '+':
				value = pop1 + pop2;
				break;

			case '-':
				value = pop2 - pop1;
				break;


			case '*':
				value = pop1*pop2;
				break;

			case '/':
				value = pop2 / pop1;
				break;
			}
			s.push(value);
		}

		i++;
	}

	return (s.pop());
}

void main(){
	char array[20];
	int length;
	cout << "enter postfix expression" << endl;
	cin >> array;
	//char array[] = "934*8+4/-";
	cout << "enter length of expression" << endl;
	cin >> length;
	
	int result;
	result = evaluate(array, length);

	cout << "The result is: " << result << endl;
}