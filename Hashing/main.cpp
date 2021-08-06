#include <iostream>
using namespace std;

int addValue(int, int, int, int);
void menu();

int main() {
	int myArr[10] = {};
	int arrSize = sizeof(myArr)/sizeof(myArr[1]);
	int value, input;
	bool collision = 0;
	
	cout << "What would you like to do?" << endl;
	menu();
	cin >> input;
	while(input != 3){
		if (input == 1){
			cout << "Enter a value: ";
			cin >> value;
			
			int i = 0;
			int position = addValue(arrSize, value, 0, i);
			while(myArr[position] != 0 || collision == arrSize){ //Idea here is if there's a collision, the variable "collision" increases by 1, which should enter the addValue method, which should do a linear probing algoirthm.
				cout << i++ << endl; //counter due to infinite loop
				collision++;
				int position = addValue(arrSize, value, collision, i);
			}
			
			myArr[position] = value;
		}
		if (input == 2){
			cout << endl;
			for(int i = 0; i < arrSize; i++){
				cout << myArr[i] << endl;
			}
		}
		menu();
		cin >> input;
	}
	cout << "Bye!";
	
	return 0;
}

int addValue(int arrSize, int value, int collision, int i){
	int position = (value+collision) % arrSize;
	return position;
}

void menu(){
	cout << "1. Add a new value to the hash table" << endl;
	cout << "2. Display hash table" << endl;
	cout << "3. Quit" << endl;
}
