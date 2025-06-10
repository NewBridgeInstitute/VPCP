#include <iostream>
#include <string>
using namespace std;
class Car {
protected:
	string Name;
public:
	Car(string n) { Name = n; }
	void Drive(void) { cout << Name << ": I'm Driving" << endl; }
};
class BMW : public Car {
public:
	BMW(string n) : Car(n) {};
	void MakeSound(void) { cout << Name << "just did a fly-by!" << endl; }
};
class German : public BMW {
public:
	German(string n) : BMW(n) {};
};
int main(void) {
	Car 	*a_car;
	German *a_german;
	a_car = a_german = new German("A BMW M3, ");
	a_german -> MakeSound();
	//static_cast<German *>(a_car) -> MakeSound();
	return 0;
}
