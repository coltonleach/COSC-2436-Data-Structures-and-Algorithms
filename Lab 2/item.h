#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
	private:
		string itemName;
		string color;
		
		//This variable is the "top" of the stack.
		int top = -1; //This is set to -1 to indicate an empty stack, since an array cannot have an index less than 0.
	
	public:
		//Default constructor
		Item();
		
		//Overloaded constructor
		Item(string n, string c);
		
		//Getter and Setter prototype for ItemName
		void setItemName(string);
		string getItemName();
		
		//Getter and Setter prototype for Color
		void setColor(string);
		string getColor();
		
		//Prototypes
		void isEmpty();
		void push(Item[], string, string);
		void pop(Item[]);
		void peek(Item[]);
		void menu();
	
};
#endif
