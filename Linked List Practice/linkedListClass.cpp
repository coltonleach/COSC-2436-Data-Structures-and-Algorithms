#include <iostream>
using namespace std;

class ListNode{
	private:
		double value;
		ListNode *next;
		friend class LinkedList;
		
	public:
		ListNode(double v, ListNode *p){
			value = v;
			next = p;
		}
};

class LinkedList{
	private:
		ListNode *head;
		bool isMemberRec(double, ListNode*);
		
	public:
		LinkedList(){head = nullptr;}
		~LinkedList();
		void add(double x);
		bool isMember(double);
		void display();
		bool remove(double x);
		void reverse();
};

LinkedList::~LinkedList(){
	while(head != 0){
		ListNode *p = head;
		head = head->next;
		delete p;
	}
}

void LinkedList::add(double x){
	head = new ListNode(x, head); // old = 0xDEADBEEF new = 0xFATCHEEC
	
	
	/*
	node (dynamically allocated memory [value p, ptr p])
	new ListNode
	head = 0xFATCHEEC
	delete head
			0xFATCHEEC (1010101010101010110101010)
			0xFATCHEEC (0000000000000000000000000)
			
			
	deleteNode(position)
		nodePointer = position(head)
		nodeBefore = position(head-1)
		nodeAfter = position(head->next)
		nodeBefore.next = nodeAfter
	*/
}

bool LinkedList::isMember(double x){
	return isMemberRec(x, head);
}

bool LinkedList::isMemberRec(double x, ListNode *pList){
	if(pList == nullptr)
		return false;
	if(pList->value == x)
		return true;
	return isMemberRec(x, pList->next);
}
void LinkedList::display(){
	ListNode *p = head;
	
	while(p != nullptr){
		cout << p->value << endl;
		p = p->next;
	}
}

bool LinkedList::remove(double x){
	ListNode *curr = head;
	ListNode *prev = nullptr;
	
	bool removed = false;
	while(curr != nullptr && !removed){
		if(curr->value == x){
			removed = true;
			if(curr==head)
				head = curr->next;
			else{
				prev->next = curr->next;
			curr->next = nullptr;
			delete curr;
			curr = nullptr;
			}
		}else{
			prev = curr;
			curr = curr->next;
		}
	}
	return removed;
}

void LinkedList::reverse(){
	ListNode *newHead = nullptr;
	ListNode *deletePtr = nullptr;
	
	while(head != nullptr){
		deletePtr = head;
		newHead = new ListNode(head->value, newHead);
		head = head->next;
		deletePtr->next = nullptr;
		delete deletePtr;
		deletePtr = nullptr;
	}
	head = newHead;
}

int main() {
	LinkedList aList;
	double num;
	
	for(int i = 0; i < 5; i++){
		cout << "Enter a real number: ";
		cin >> num;
		aList.add(num);
		
	}
	cout << "Before..\n";
	aList.display();
	
	aList.reverse();
	cout << "After..\n";
	aList.display();
	
	/*
	for(int i = 0; i < 5; i++){
		aList.display();
		cout << "Enter a number to remove: ";
		cin >> num;
		if(aList.remove(num))
			cout << num << " was removed" << endl;
		else
			cout << num << " is NOT in the list" << endl;
	cout << "------------------\n";
	}*/
	return 0;
}
