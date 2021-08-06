/*
Colton Leach, COSC 2436-85853 - Oct 24, 2019
This program uses smart pointers and a linked list to
view text from a file, and remove duplicates from said file.
The three main functions are:
	addNode, removeduplicate, and displayList.
addNode: adds a node that will store a string value from the file.
removeDuplicate: removes duplicates that are in the file.
displayList: displays the linked list values.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <Windows.h> //gives access to Sleep()
using namespace std;

class Node
{
	private:
		string line;
		shared_ptr<Node> next;
		
	public:
		Node();
		string getLine();
		shared_ptr<Node> getNext();
		void setLine(string);
		void setNext(shared_ptr<Node>);
};

//Default constructor
Node::Node(){
	line = "";
	next = nullptr;
}

//Getters and setters-------------------
string Node::getLine(){ return line; }
shared_ptr<Node> Node::getNext(){ return next; }

void Node::setLine(string l){ line = l; }
void Node::setNext(shared_ptr<Node> n){ next = n; }
//--------------------------------------


//Prototpyes----------------------------
void addNode(shared_ptr<Node> &startPtr);
void removeDuplicate(shared_ptr<Node> &);
void displayList(shared_ptr<Node>);
void pause();
//--------------------------------------

int main() {
	shared_ptr<Node> startPtr = nullptr;	
	
	cout << "Adding the lines to the linked list";
	addNode(startPtr);
//	pause();
	cout << "Finished.\n\n";
	
	cout << "Displaying linked list";
//	pause();
	cout << "----------------------------\n";
	displayList(startPtr);
	cout << "----------------------------\n";
	cout << "Finished.\n\n";
	
	cout << "Removing duplicates\n";
	removeDuplicate(startPtr);
//	pause();
	cout << "Finished.\n\n";
	
	cout << "Displaying the new list";
	pause();
	cout << "----------------------------\n";
	displayList(startPtr);
	cout << "----------------------------\n";
	cout << "Finished.\n\n";
	
	return 0;
}

void pause(){ //This is just to make the code prettier.
	for(int i = 0; i < 3; i++){
		cout << ".";
		Sleep(450); //Pauses the program for x milliseconds.
	}//end for
	cout << endl;
}//end pause()

void addNode(shared_ptr<Node> &startPtr){
	Node n;
	ifstream file; //Allows the client to open/close/read/write files.
	string line; //This will hold the string from the file one at a time.
	file.open("test.txt"); //the "file" variable now holds the text file.
	startPtr = nullptr;
	
	while (!file.eof()){ //If it's not at the end of the file, do what's in the scope.
		shared_ptr<Node> aNode (new Node);
		getline(file, line);
		aNode->setLine(line);
		aNode->setNext(nullptr);
		
		if(startPtr)
			aNode->setNext(startPtr);
		
		startPtr = aNode;
	}//end while
}//end addNode()

void displayList(shared_ptr<Node> startPtr){
	if(startPtr){
		shared_ptr<Node> currPtr = startPtr;
		
		while(currPtr){
			cout << currPtr->getLine() << endl;
			currPtr = currPtr->getNext();
			Sleep(50); //Pauses the program for x milliseconds.
		}
	}
	else
		cout << "The list is empty." << endl; //For debugging perposes. If this shows up, something is wrong with either the text file or the program.
}

void removeDuplicate(shared_ptr<Node> &startPtr)
{
	int i = 1;
	int j = 1;
	int k = 1;
	int l = 1;
	shared_ptr<Node> currPtr = startPtr;
	shared_ptr<Node> currPtr2;
	while(currPtr != nullptr && currPtr->getNext() != nullptr){ //If there is no linked list, the start and start's next won't have any values. Therefor, won't enter the while loop.
		cout << "first while loop: " << i++ << endl;
		currPtr2 = currPtr;
		while(currPtr2->getNext() != nullptr){ //currPtr transverses, so once it reaches the end (a nullptr), it will not enter the while loop
			cout << "second while loop: " << j++ << endl;
			if(currPtr->getLine() == currPtr2->getNext()->getLine()){
				cout << "if statement: " << k++ << endl;
				currPtr2->getNext() = currPtr2->getNext()->getNext();
				cout << currPtr->getLine() << endl;
				cout << currPtr->getNext()->getLine() << endl;
				cout << currPtr->getNext()->getNext()->getLine() << endl;
				cout << currPtr->getNext()->getNext()->getNext()->getLine() << endl;
				cout << currPtr->getNext()->getNext()->getNext()->getNext()->getLine() << endl;
			}//end if
			else{
				cout << "else statement: " << l++ << endl;
				currPtr2 = currPtr2->getNext();
			}
			Sleep(100);
		}//end while
		currPtr = currPtr->getNext(); 
	}//end while
}














