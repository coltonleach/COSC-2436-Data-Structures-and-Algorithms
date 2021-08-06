#include <iostream>
using namespace std;

class Node(){
	private:
		Node* node;
		int value;
	
	public:
		Node();
		int getValue();
		void setValue(int);
		
		Node getNext*();
		void setNext(Node*);
};

Node::Node(){
	value = 0;
	next = nullptr;
}

int getValue(){
	return value;
}
void setValue(int v){
	value = v;
}

Node getNext*(){
	return next;
}
void setNext(Node* n){
	next = n;
}

int menu();

int main() {
	Node* startPtr = nullptr;
	int userInput;
	menu();
	
	while(userInput != 4){
		if(userInput == 1)
	}
	
	return 0;
}

int menu(){
	cout << "1. Add node\n";
	cout << "2. Display Nodes\n";
	cout << "3. Delete Node\n";
	cout << "4. Quit\n";
}
