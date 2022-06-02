#include <iostream>
using namespace std;

struct Node{
	int element;
	Node *left = NULL;
	Node *right = NULL;

};

struct Tree{
	Node *root = NULL;

	void insertNode(int val, Node* &ptr){
		if (ptr == NULL){
			ptr = new Node;
			ptr->left = ptr->right = NULL;
			ptr->element = val;
		}

		else if (val < ptr->element){
			insertNode(val, ptr->left);
		}

		else insertNode(val, ptr->right);
	}
	
	/*Node* findNode(int val, Node* ptr){

	if (ptr == NULL){
	return ptr;
	}

	if (ptr->element == val){
		return ptr;
	}

	if (val < ptr->element){
	return findNode(val, ptr->left);
	}

	else {
	return findNode(val, ptr->right);
	}*/
	

int findNode(int val, Node* ptr){

		if (ptr == NULL){
			return -1;
		}

		if (ptr->element == val){
			return val;
		}

		if (val < ptr->element){
			return findNode(val, ptr->left);
		}

		else {
			return findNode(val, ptr->right);
		}

	}

void Preorder(Node *ptr){
	cout << ptr->element << '\t';

	if (ptr->left != NULL){
		return Preorder(ptr->left);
	}

	if (ptr->right != NULL){
		return Preorder(ptr->right);
	}
}


void Postorder(Node *ptr){

	if (ptr->left != NULL){
		return Preorder(ptr->left);
	}

	if (ptr->right != NULL){
		return Preorder(ptr->right);
	}

	cout << ptr->element << '\t';
 }

void Inorder(Node *ptr){

	if (ptr->left != NULL){
		return Preorder(ptr->left);
	}

	cout << ptr->element << '\t';

	if (ptr->right != NULL){
		return Preorder(ptr->right);
	}

  }

};

void main(){
	
	Tree t;
	/*
	t.insertNode(30, t.root);
	t.insertNode(40, t.root);
	t.insertNode(50, t.root);
	t.insertNode(39, t.root);

	cout << t.findNode(39, t.root); */

}
