#include <iostream>
using namespace std;


struct Node {
	int info;
	Node *link;
};

class LinkedList{
private:
	Node *head;
	Node *tail;
	int length;
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
		length = 0;
	}

	void printList(){
		Node *current = head;

		while (current != NULL){
			cout << current->info << " ";
			current = current->link;
		}

		cout << endl;
	}

	void insertLast(int item){
		Node *newNode = new Node;

		newNode->info = item;
		newNode->link = NULL;
		length++;

		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->link = newNode;
			tail = newNode;
		}
	}

	bool search(int item){
		Node *current = head;

		while (current != NULL){
			if (current->info == item){
				return true;
			}
			current = current->link;
		}
		return false;
	}

	void deleteNode(int item){

		if (head == NULL){ //case 1 linked list empty
			cout << "cannot delete from empty LinkedList" << endl;
		}
		else{
			Node *current, *q;

			if (head->info == item){ //case 2 first item is the desired item
				current = head; 
				head = head->link;

				if (head == NULL) { //case 2.1 only one item in list
					tail = NULL;
				}

				delete current;
				length--;
			}

			else{ // Case 3 element is somewhere in the list
				q = head; // used to follow the (current) pointer
				current = head->link;

				bool found = false;

				while (current != NULL){ //loop on the linked list

					if (current->info == item){ //case 3.1 found the item
						q->link = current->link; 

						if (tail == current){ // case 3.2 the found item is the last item
							tail = q;
						}

						delete current;
						length--;
						found = true;

						break;
					}

					else{ //increments the pointers to next node
						q = q->link;
						current = current->link;

					}
				}

				if (!found){ //Item not found
					cout << item << "Not Found" << endl;
				}

			}
		}
	}
};

void main(){
	LinkedList list;

	for (int i = 0; i < 10; i++){
		list.insertLast(i);
	}

	list.printList();

	for (int i = -1; i < 12; i++){
		cout << list.search(i) << endl;
	}

	for (int i = -1; i < 12; i++){
		list.deleteNode(i);
		list.printList();
	}

}