#include <iostream>
using namespace std;

const int MAX = 10;

struct queue{
	int front;
	int rear;
	int q[MAX];

	queue(){
		front = -1;
		rear = -1;
	}
	bool isFull(){
		if (rear == MAX - 1)
			return true;

		else return false;
	}

	bool isEmpty(){
		if (front == -1){

			return true;
		}
		else if (front > rear)
			return true;
		else
			return false;
		    

	}
	void enqueue(int element){
		if (isEmpty()){
           rear++;
           front++;
			q[rear] = element;
			

		}
		else if (isFull()){
			cout << "Queue Overflow" << endl;
		}

		else
		{
			rear++;
			q[rear] = element;
		}
	}

	 int dequeue(){
		int x;
		if (!isEmpty()){
		    x = q[front];
			front++;
			return x;
		}
		else
			cout << "The queue is empty" << endl;
	}

	 void display(){
		 for (int i = 0; i < MAX; i++){
			 cout << dequeue() << endl;
		 }
	 }

};

void main(){

	queue q;

	int element;

	for (int i = 0; i < MAX; i++){
		cout << "Enter an element into the queue" << endl;
		cin >> element;
		q.enqueue(element);
	}

	q.display();


}