#include <iostream>
#include<list>
#include <iterator>
using namespace std;

void intersection(list<int> l1, list<int> l2){

	int i;
	int j;

	for (auto i = l1.begin(); i != l1.end(); i++){
		for (auto j = l2.begin; j != l2.end(); j++){
			if (*i == *j){
				cout << *i << " ";
			}
		}
	}
}

void Union(list<int> l1, list<int> l2){

	list<int> l3;



	for (auto i = l1.begin(); i != l1.end(); i++){
		l3.push_front(*i);
	}

	for (auto i = l2.begin(); i != l2.end(); i++){
		l3.push_front(*i);
	}

	l3.unique();
	l3.sort();

	for (auto i = l3.begin(); i != l3.end(); i++){
		cout << *i << " ";
	}

	cout << endl;
}

bool availableInBoth(list<int> l1, list<int> l2, int val){
	bool inOne = false; bool inTwo = false;
	for (auto i = l1.begin(); i != l1.end(); i++){
		if (*i == val) inOne = true;
		break;
	}
	for (auto i = l2.begin(); i != l2.end(); i++){
		if (*i == val) inTwo = true;
		break;
	}
	
	if (inOne && inTwo) return true;

	return false;
}

void difference(list<int> l1, list<int> l2){

	list<int> diff;

	for (auto i = l1.begin(); i != l1.end(); i++){
		if (!availableInBoth(l1, l2, *i)) diff.push_back(*i);
	}

	for (auto i = diff.begin(); i != diff.end(); i++){
		cout << *i << " ";
	}

}



void main(){ 
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	list<int> l2;
	l2.push_back(2);
	l2.push_back(10);
	l2.push_back(5);

}