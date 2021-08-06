#include "item.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
Item::Item(){
	itemName = "NULL";
	color = "NULL";
}

//Overloaded constructor
Item::Item(string n, string c){
	itemName = n;
	color = c;
}

//Getter and Setter for ItemName
void Item::setItemName(string iN){ itemName = iN; }
string Item::getItemName(){ return itemName; }

//Getter and Setter for Color
void Item::setColor(string c){ color = c; }
string Item::getColor(){ return color; }

//This prints out a list of options the user has available.
void Item::menu(){
	cout << "1. Check isEmpty\n";
	cout << "2. push an item and color\n";
	cout << "3. pop - remove the top item\n";
	cout << "4. peek - look at the top item\n";
	cout << "5. Quit\n";
}//End menu

//This checks if the stack is, or is not empty.
void Item::isEmpty(){
	if(top <= -1)
		cout << "The stack is empty." << endl;
	else
		cout << "The stack is not empty." << endl; 
}//End isEmpty

//This lets the client pass the array (the stack), the item name, and the color.
void Item::push(Item myArr[], string name, string color){
	if(top >= 4){
		cout << "Sorry, but the stack is full!" << endl;
	}
	else{
		top++; //Top gets incrimented so that item and color can be at the top of the stack.
		setItemName(name); //Sets ItemName to the user's input
		setColor(color); //Sets color to the user's input
		myArr[top] = {getItemName(), getColor()}; //Sets the top of the array to the values the user inputed
	}
}//End push

void Item::pop(Item myArr[]){
	if(top <= -1) //-1 indicates an empty stack
		cout << "The stack is empty, cannot pop." << endl;
	else{
		cout << "The popped item was " << myArr[top].getItemName() << " and the color was " << myArr[top].getColor() << endl;
		top--; //Decraments so that the next push can overwrite the current values
	}
}//End pop

void Item::peek(Item myArr[]){
	if(top <= -1) //-1 indicates an empty stack
		cout << "The stack is empty, cannot peek." << endl;
	else{
		cout << "The item is " << myArr[top].getItemName() << " and the color is " << myArr[top].getColor() << endl;
	}
}//End peek
