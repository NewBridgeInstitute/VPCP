/*
#include <iostream>
using namespace std;

class Class {
public:
    int field;

    //Parameterized constructor
    Class(int n) : field(n) { }

    //Copy constructor
    Class(const Class &c) : field(0) { }

    //Default constructor
    Class(void) : field(1) { }

    //Member function to set the vale of 'field'
    void set(int n) { field = n; }

    //Member function to get the value of 'field'
    int get(void) const { return field; } //Note the 'const' qualifier
};

int main() {
    //Example of a constant object
    const Class obj1(145); // Declaration of a constant object

    //Attempting to modify a constant object results in s compilation error
    //obj1.set(99); // Uncommenting this line would rusult in a compilation error
    //Accessing a member function that is marked as 'const' is allowed

    cout << "THIS IS THE VALUE OF A CONSTANT OBJECT: " << obj1.get() <<endl;

    //Creating a non-constant object is allowed
    Class obj2(77);

    //Just creating a breakline for display
    cout << "===================================================" <<endl;

    //Modifying a non-constant object is allowed
    obj2.set(428);

    //Accessing a member function of a non-constant object
    cout << "AND THIS IS THE VALUE OF A NON-CONSTANT OBJECT: " << obj2.get() <<endl;

    return 0;
}
*/
//THIS IS AN UPDATE OF 'THE CONST KEYWORD' IN << 2.6.1.8 >>
//THIS TALKS ABOUT 'CONSTANT MEMBER FUNCTIONS'
/*
#include <iostream>
using namespace std;

class Class {
public:
	int field;
	Class(int n) : field(n) { };
	Class(Class &c) : field(0) { };
	Class(void) : field(1) { };
	void set(int n) { field = n; }
	int get(void) const { return field; }
};

int main() {
    const Class obj1(145);
    cout << "Contant OBJ: " <<obj1.get() <<endl;
    Class obj2(77);
    cout << "===========================" <<endl;
    obj2.set(444);
    cout << "Non-Constant OBJ: " << obj2.get() <<endl;
    return 0;
}
*/
















































