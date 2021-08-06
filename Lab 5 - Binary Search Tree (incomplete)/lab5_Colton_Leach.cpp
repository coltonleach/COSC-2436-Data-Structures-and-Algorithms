/*
Colton Leach, COSC 2436-85853 - Dec 8, 2019
This program is supposed to take in employee IDs and names, store them in a binary search tree,
and allow the user to search for an ID to see if it's in the tree.

This program doesn't actually do any of that. I could not figure out how to make a proper BST
while having the variables in a private class and the getters and setters. It was just too confusing.

I tried making a recursive method to add integers to the BST, but the program doesn't seem to actually
enter the recursive method. I was able to hard code them into the tree, but I doubt that's what you're expecting.
*/

#include <iostream>
#include <memory>
using namespace std;

class Node{
	private:
		int value;
		shared_ptr<Node> left, right;
	public:
		Node();
		int getValue();
		shared_ptr<Node> getRight();
		shared_ptr<Node> getLeft();
		void setValue(int);
		void setRight(shared_ptr<Node>);
		void setLeft(shared_ptr<Node>);
};

Node::Node(){
	value = 0;
	left = nullptr;
	right = nullptr;
}

int Node::getValue(){ return value; }
shared_ptr<Node> Node::getRight(){ return right; }
shared_ptr<Node> Node::getLeft(){ return left; }

void Node::setValue(int v){ value = v; }
void Node::setRight(shared_ptr<Node> r){ right = r; }
void Node::setLeft(shared_ptr<Node> l){ left = l; }

void addLeaf(shared_ptr<Node> &, int);
void rAddLeaf(shared_ptr<Node>, int);

int main() {
	shared_ptr<Node> startPtr = nullptr;
	addLeaf(startPtr, 5); //Test value
	addLeaf(startPtr, 7); //Test value
	addLeaf(startPtr, 3); //Test value
	addLeaf(startPtr, 4); //Test value
	
	return 0;
}

void addLeaf(shared_ptr<Node> &startPtr, int num){
	shared_ptr<Node> leftPtr, rightPtr;
	startPtr = nullptr;
	leftPtr = nullptr;
	rightPtr = nullptr;
	shared_ptr<Node> aNode (new Node);

	if(startPtr == nullptr){
		aNode->setValue(num);
		aNode->setRight(rightPtr);
		aNode->setLeft(leftPtr);
	}//end if
	else{ //If the tree root (startPtr) has a value, that means a tree is there and we will add a leaf to the tree.
		if(startPtr->getValue() > num){ //If the value is less than the root, make a leaf to the left of the root.
			rAddLeaf(startPtr->getLeft(), num); //The idea with this was rAddLeaf(Left subtree, num)
		}//end if
		else if(startPtr->getValue() < num){ //If the value is more than the root, make a leaf to the right of the root.
			rAddLeaf(startPtr->getRight(), num); //The idea with this was rAddLeaf(Right subtree, num)
		}//end else if
	}//end else
	
	if(startPtr)
		aNode->setLeft(leftPtr);
		aNode->setRight(rightPtr);
	
	startPtr = aNode;
}//end addLeaf()

void rAddLeaf(shared_ptr<Node> subTree, int num){//Recurssion method.
	shared_ptr<Node> leftPtr, rightPtr;
	leftPtr = nullptr;
	rightPtr = nullptr;
	shared_ptr<Node> aNode (new Node);
	
	if(subTree == nullptr){
		aNode->setValue(num);
		aNode->setRight(nullptr);
		aNode->setLeft(nullptr);
	}//end if
	else{ //If the tree root (startPtr) has a value, that means a tree is there and we will add a leaf to the tree.
		if(subTree->getValue() > num){ //If the value is less than the root, make a leaf to the left of the root.
			rAddLeaf(subTree->getLeft(), num);
		}//end if
		else if(subTree->getValue() < num){ //If the value is more than the root, make a leaf to the right of the root.
			rAddLeaf(subTree->getRight(), num);
		}//end else if
	}//end else
	return;
}//end rAddLeaf()
