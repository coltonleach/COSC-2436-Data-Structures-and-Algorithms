/*
Colton Leach, COSC 2436-85853 - Nov 16, 2019
This program makes use of a queue.
It starts out with asking the user to choose a data type they would like to use.
Then a second menu displays giving the user the queue options (enqueue, dequeue, display, then back to the main menu).
enqueue: asks the user what they would like to put into the queue
dequeue: automatically removes the first entry in the queue, and displays what was removed, unless empty.
display: displays the entire queue, unless empty.
	For some reason I could not get the program to function properly with seperate IntQueue.cpp and IntQueue.h files.
	It only functioned properly when I had everything in the .h file.
	vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/

#include <iostream>
#include <cstdlib>
#include <memory>
#include "IntQueue.h"
using namespace std;

void menu();
void dataMenu();

int main(){
	/*	
		input is the variable for the second menu options
		option is the variable for the main menu
		count keeps track of how many entries are in the queue
		userInt/userString/userFloat/userChar are the variables that hold the user's queue entry input
	*/
	int input, userInt, option, count = 0;
	string userString;
	float userFloat;
	char userChar;
	dataMenu();
	cin >> option;
	while(option != 5){ //Until the user chooses to quit from the main menu, keep running the program
		switch(option){
			case 1:{ //Integer option
				count = 0; //Has to be initialized to 0, otherwise it will carry over to the other data type options
				IntQueue<int> iQ{6}; //initializes int array to 6 elements
				input = 0; //initialized to 0 to reduce the risk of the program bugging out and choosing an option by itself
				menu();
				cin >> input;
				while (input != 4){
					if(input == 1){//put item in queue
						cout << "Enter an int: ";
						cin >> userInt;
						iQ.enqueue(userInt);
						cout << userInt << " was added to the queue." << endl;
						count++;
					}//end if
					if(input == 2){//remove item from queue
						if(!iQ.isEmpty()){
							iQ.dequeue(userInt);
							cout << userInt << " was removed from the queue." << endl;
							count--;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					if(input == 3){//display items in queue
						if(!iQ.isEmpty()){
							int i = 0;
							while(i < count){ //loops through the array and displays it all
								iQ.dequeue(userInt); //removes the first entry and stores what was removed into the variable "userInt"
								cout << userInt << " "; //prints out the variable "userInt"
								iQ.enqueue(userInt); //puts the entry back into the queue. It will be in the same place due to every entry being removed.
								i++;
							}// end while
							cout << endl;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					menu();
					cin >> input;
				}
				dataMenu();
				cin >> option;
			}//end case 1
				break;
			case 2:{ //string option
				count = 0; //Has to be initialized to 0, otherwise it will carry over to the other data type options
				IntQueue<string> iQ{6}; //initializes string array to 6 elements
				input = 0; //initialized to 0 to reduce the risk of the program bugging out and choosing an option by itself
				menu();
				cin >> input;
				while (input != 4){
					if(input == 1){//put item in queue
						cout << "Enter a string: ";
						cin >> userString;
						iQ.enqueue(userString);
						cout << userString << " was added to the queue.\n";
						count++;
					}//end if
					if(input == 2){//remove item from queue
						if(!iQ.isEmpty()){
							iQ.dequeue(userString);
							cout << userString << " was removed from the queue." << endl;
							count--;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					if(input == 3){//display items in queue
						if(!iQ.isEmpty()){
							int i = 0;
							while(i < count){
								iQ.dequeue(userString); //removes the first entry and stores what was removed into the variable "userInt"
								cout << userString << " "; //prints out the variable "userInt"
								iQ.enqueue(userString); //puts the entry back into the queue. It will be in the same place due to every entry being removed.
								i++;
							}// end while
							cout << endl;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					menu();
					cin >> input;
				}
				dataMenu();
				cin >> option;
			}//end case 2
				break;
			case 3:{ //char option
				count = 0; //Has to be initialized to 0, otherwise it will carry over to the other data type options
				IntQueue<char> iQ{6};//initializes char array to 6 elements
				input = 0; //initialized to 0 to reduce the risk of the program bugging out and choosing an option by itself
				menu();
				cin >> input;
				while (input != 4){
					if(input == 1){//put item in queue
						cout << "Enter a character: ";
						cin >> userChar;
						iQ.enqueue(userChar);
						cout << userChar << " was added to the queue." << endl;
						count++;
					}//end if
					if(input == 2){//remove item from queue
						if(!iQ.isEmpty()){
							iQ.dequeue(userChar);
							cout << userChar << " was removed from the queue." << endl;
							count--;
						}// end if
					}//end if
					if(input == 3){//display items in queue
						if(!iQ.isEmpty()){
							int i = 0;
							while(i < count){
								iQ.dequeue(userChar); //removes the first entry and stores what was removed into the variable "userInt"
								cout << userChar << " "; //prints out the variable "userInt"
								iQ.enqueue(userChar); //puts the entry back into the queue. It will be in the same place due to every entry being removed.
								i++;
							}// end while
							cout << endl;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					menu();
					cin >> input;
				}
				dataMenu();
				cin >> option;
			} //end case 3
				break;
			case 4:{ //float option
				count = 0; //Has to be initialized to 0, otherwise it will carry over to the other data type options
				IntQueue<float> iQ{6};//initializes float array to 6 elements
				input = 0; //initialized to 0 to reduce the risk of the program bugging out and choosing an option by itself
				menu();
				cin >> input;
				while (input != 4){
					if(input == 1){//put item in queue
						cout << "Enter a float: ";
						cin >> userFloat;
						iQ.enqueue(userFloat);
						cout << userFloat << " was added to the queue." << endl;
						count++;
					}//end if
					if(input == 2){//remove item from queue
						if(!iQ.isEmpty()){
							iQ.dequeue(userFloat);
							cout << userFloat << " was removed from the queue." << endl;
							count--;
						}// end if
					}//end if
					if(input == 3){//display items in queue
						if(!iQ.isEmpty()){
							int i = 0;
							while(i < count){
								iQ.dequeue(userFloat); //removes the first entry and stores what was removed into the variable "userInt"
								cout << userFloat << " "; //prints out the variable "userInt"
								iQ.enqueue(userFloat); //puts the entry back into the queue. It will be in the same place due to every entry being removed.
								i++;
							}// end while
							cout << endl;
						}// end if
						else
							cout << "The queue is empty." << endl;
					}//end if
					menu();
					cin >> input;
				}
				dataMenu();
				cin >> option;
			}//end case 4
				break;
		}
	}
	cout << "Goodbye!";
	
	return 0;
}

void menu(){ //second menu
	cout << "1. Put an item in the queue" << endl;
	cout << "2. Remove an item from the queue" << endl;
	cout << "3. Display the items in the queue" << endl;
	cout << "4. Choose new data type"<< endl;
}//end menu

void dataMenu(){ //main menu
	cout << "Choose what data type you would like to work with:" << endl;
	cout << "1. Integers" << endl;
	cout << "2. Strings" << endl;
	cout << "3. Characters" << endl;
	cout << "4. Floats" << endl;
	cout << "5. Quit" << endl;
}//end dataMenu
