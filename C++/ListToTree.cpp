#include <iostream>
#include<list>
using namespace std;

struct treeNode{
	int element;
	treeNode *right;
	treeNode *left;
};

struct TREE{
	treeNode *root;

	void insertBNode(int val, treeNode* &ptr){

		if (ptr == NULL) {
			ptr = new treeNode;
			ptr->left = ptr->right= NULL;
			ptr->element = val;
		}

		if (val < ptr->element) insertBNode(val, ptr->left);
		if (val > ptr->element) insertBNode(val, ptr->right);
	}


	void Preorder(treeNode *ptr){
		cout << ptr->element << " ";
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
};

treeNode *list2tree(list<int> l1){
	int i;
	TREE t;

	for (auto i = l1.begin(); i <= l1.end(); i++){

		t.insertBNode(*i,t.root);
	}

	return t.root;
}


void main(){
	TREE t;
	list<int> L;
	int input;
	bool choice = true;
	while (choice){
		cout << "enter element" << endl;
		cin >> input;
		L.push_back(input);
		cout << "enter again ? press 1, otherwise 0 " << endl;
		cin >> choice;
	}

	t.Preorder(list2tree(L));

}