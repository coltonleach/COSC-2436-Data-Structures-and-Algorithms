/*
Colton Leach, COSC 2436-85853 - Oct 13, 2019
This program is about stack implamentation using an array.
The program asks the user if they would like to:
	check isEmpty, Push, Pop, Peek, or quit the program.
isEmpty checks whether or not the stack is empty.
Push allows the user to add to the stack. It asks for a item name, and a color. Both get added into a single index.
Pop allows the user to remove the top item from the stack.
Peek allows the user to see what is at the top of the stack.
*/

#include <iostream>
#include "item.h"

using namespace std;

int main() {
	Item i;
	Item myArr[5];
	int userInput;
	string n;
	string c;
	
	cout << "What would you like to do?" << endl;
	i.menu();
	cin >> userInput;
	while(userInput != 5){ //If the user inputs 5, it quits the program.
		if(userInput == 1){
			i.isEmpty();
		}
		else if(userInput == 2){
			cout << "Enter an item name: ";
			cin >> n;
			cout << "Enter a color: ";
			cin >> c;
			i.push(myArr, n, c);
		}
		else if(userInput == 3){
			i.pop(myArr);
		}
		else if(userInput == 4){
			i.peek(myArr);
		}
		else{
			cout << "Sorry, that was an invalid input. Please choose from the following: \n";
		}
		cout << endl;
		i.menu();
		cin >> userInput;
	}
	cout << "Goodbye!";
	return 0;
}
