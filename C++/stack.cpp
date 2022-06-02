#include<iostream>
using namespace std;

const int size = 5;

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
		for (int i = top ; i >= 0; i--){
			cout << "Element: " << st[i] << endl;
	  }
	}
};

void main(){
	stack stk;
	bool again = true;
	bool choice = true;
	int num;
	cout << "Enter a number:" << endl;
	cin >> num;
	stk.push(num);

	
	cout << "enter 1 to enter another number ";
	cin >> again;

	while (again){
		

		if (again){
			cout << "enter number:" << endl;
			cin >> num;
			stk.push(num);

		}
		    

		cout << "enter 1 to enter another number ";
		cin >> again;
	}

	stk.display();

}