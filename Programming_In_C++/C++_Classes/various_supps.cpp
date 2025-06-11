/*
#include <iostream>
using namespace std;
class WithConstructor {
public:
	int i;
	float f;
	WithConstructor(int a = 0, float b = 0) : i(a), f(b) { }
	void Display(void) { cout << "i=" << i << ",f=" << f << endl; }
};
int main(void) {
	WithConstructor  o1;
	WithConstructor *o2;
	o2 = new WithConstructor;
	o1.Display();
	o2 -> Display();
	return 0;
}
*/

// HERE WE CALL THEM ALL OUT IN THIS EXAMPLE
#include <iostream>
using namespace std;
class A {
public:
	A(A &src) { cout << "copying A..." << endl; }
	A(void) { }
	void Do(void) { cout << "A is doing something" << endl; }
};
class B {
public:
	B(B &src) { cout << "copying B..." << endl; }
	B(void){ }
	void Do(void) { cout << "B is doing something" << endl; }
};
class Compo {
public:
    Compo(Compo &src) : f1(src.f1), f2(src.f2) { cout << "Copying Compo..." << endl; } //here we call them all out
	Compo(void) { } ;
	A f1;
	B f2;
};
int main(void) {
	Compo  co1;
	Compo  co2 = co1;
	co2.f1.Do();
	co2.f2.Do();
	return 0;
}
