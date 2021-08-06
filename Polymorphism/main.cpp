#include <iostream>
using namespace std;

class Human{
	protected:
		string greeting;
		string name;
		int age;
		bool walk;
		string major;
	
	public:
		void setGreet(string g){
			greeting = g;
		}
		void setName(string n){
			name = n;
		}
		void setAge(int a){
			age = a;
		}
		void setWalk(int w){
			walk = w;
		}
		void setMajor(string m){
			major = m;
		}
		void greet(){
			cout << greeting << endl;
			cout << "My name is " << name << endl;
			cout << "I am " << age << " years old." << endl;
		
			if(!walk)
				cout << "I cannot walk." << endl;
			else
				cout << "I can walk." << endl;
		
			cout << "My major is " << major << endl;
		}
};

class Maggie: public Human{
	public:
		void info(){
			cout << "I like to draw and watch GMM." << endl;
		}	
};

class Colton: public Human{
	public:
		void info(){
			cout << "I'm an amature photographer and love technology." << endl;
		}	
};

int main() {
	Maggie m;
	Colton c;
	
	Human *human1 = &m;
	Human *human2 = &c;
	
	human1->setGreet("hi");
	human1->setName("Maggie");
	human1->setAge(23);
	human1->setMajor("Enviormental health and society");
	human1->setWalk(0);
	
	human2->setGreet("Howdy perner");
	human2->setName("Cotton");
	human2->setAge(21);
	human2->setMajor("copmp sci");
	human2->setWalk(1);
	
	human1->greet();
	m.info();
	human2->greet();
	c.info();

	return 0;
}
