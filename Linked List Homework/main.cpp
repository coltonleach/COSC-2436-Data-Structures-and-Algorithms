#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class linkedList{
	private:
		node *head,*tail;
	public:
		linkedList(){
			head = NULL;
			tail = NULL;
		}
		
	void addNode(int n){
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		
		if(head == NULL){
			head = tmp;
			tail = tmp;
		}
		else{
			tail->next = tmp;
			tail = tail->next;
		}
	}
	
	node* getHead(){
		return head;
	}
	
	void display(node *head){
		if(head == NULL)
			cout << "NULL" << endl;
		else{
			cout << head->data << endl;
			display(head->next);
		}
		
	}
	
	void menu(){
		cout << "1. Enter a node\n";
		cout << "2. Display the nodes\n";
		cout << "3. Quit\n";
	}
};


int main() {
	linkedList a;
	int input;
	a.menu();
	cin >> input;
	
	while(input != 3){
		if(input == 1){
			cout << "Enter a integer: ";
			cin >> input;
			a.addNode(input);
			input = 1;
		}
		if(input == 2){
			cout << "-------Nodes-------" << endl;
			a.display(a.getHead()); 
			cout << "-------Nodes-------" << endl;
		}
		
		a.menu();
		cin >> input;
	}
	
	return 0;
}
