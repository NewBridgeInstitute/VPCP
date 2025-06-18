/*
// << 3.5.1.1 EXCEPTIONS IN ACTION >>
Stack again
Our good old friend, the stack, is back! We’re going to rewrite it in order to:

make it more reliable and safe
show how exceptions can improve the quality of the code
present a simple example of building an independent, reusable module
The initial form of the code is in the editor.
//////////////////////////////////////////////////////////////////
///// SDO CODE OF:
class Stack {
    private:
	int *stackstore;
	int stacksize;
	int SP;
    public:
	Stack(int size = 100);
	~Stack();
	void push(int value);
	int pop(void);
};
Stack::Stack(int size) {
	stackstore = new int[size];
	stacksize = size;
	SP = 0;
}
Stack::~Stack(void) {
	delete []stackstore;
}
void Stack::push(int value) {
	stackstore[SP++] = value;
}
int Stack::pop(void) {
	return stackstore[--SP];
}

#include <iostream>
using namespace std;
int main(void) {
	Stack stk;
	stk.push(1);
	cout << stk.pop() << endl;
	return 0;
}
//////////////////////////////////////////////////////////////////
// << 3.5.1.2 EXCEPTIONS IN ACTION>>
Stack again – new exceptions
Let’s try to identify all the “bad” surprises our stack may face in its life. We can see four of them right here:

improper stack size specification (less or equal to zero)
failure in allocating memory for the stack
invoking push when the stack is full
invoking pop when the stack is empty...
//
//////////////////////////////////////////////////////////////////
// << 3.5.1.3 EXCEPTIONS IN ACTION>>
// = Stack again – new exception classes =
Here are the declarations along with the includes required for successful compilation:
SDO->[[
#include <iostream>
#include <exception>
#include <stdexcept>

class stack_size_error : public std::length_error {
public:
    explicit stack_size_error(const std::string &msg);
};
class stack_bad_alloc : public std::bad_alloc {
public:
    explicit stack_bad_alloc(void);
};
class stack_overflow : public std::logic_error {
public:
    explicit stack_overflow(const std::string &msg);
};
class stack_empty : public std::logic_error {
public:
    explicit stack_empty(const std::string &msg);
};
ALSO THEN ->Analyse the following aspects of the code:

- the names of the base classes used in each declaration
- the constructors defined for each class
- the std:: prefix placed inside the declarations; can we omit them? Why? ]]

////
////

Here are the definitions corresponding to the previous declarations:
SDO-> [[
stack_size_error::stack_size_error(const std::string &msg) : std::length_error(msg) {
};
stack_bad_alloc::stack_bad_alloc(void) : std::bad_alloc() {
};
stack_overflow::stack_overflow(const std::string &msg) : std::logic_error(msg) {
};
stack_empty::stack_empty(const std::string &msg) : std::logic_error(msg) {
}; ]]

////
////

The completed declaration is here:
SDO-> [[
class Stack {
    private:
    int *stackstore;
    int stacksize;
    int SP;
    public:
    Stack(int size = 100) throw(stack_size_error, stack_bad_alloc);
    ~Stack();
    void push(int value) throw(stack_overflow);
    int pop(void) throw(stack_empty);
};]]
//////////////////////////////////////////////////////////////////
// << 3.5.1.4 EXCEPTIONS IN ACTION>>
+ STACK AGAIN - NEW CONSTRUCTOR
+ STACK AGAIN - NEW PUSH
+ STACK AGAIN - NEW POP
//
////////////////////////////////////////////////////////////////////
// << 3.5.1.5 EXCEPTIONS IN ACTION>>
////
= STACK AGAIN - A HEADER FILE FOR A NEW MODULE =
We’ve said previously that we’re going to build a new stack code as an “aggregate” of two source files. Now it’s time to fulfil that promise.

First, we’ll write the header file – a file containing all the necessary declarations. The file can be included by any other source file making use of our newly built stack. This is the same mechanism we utilize when we include e.g. the iostreams header file.

/////////////////////////////
SDO-CODE:
#ifndef __MYSTACK__
#define __MYSTACK__

#include <iostream>
#include <exception>
#include <stdexcept>

class stack_size_error : public std::length_error {
public:
	explicit stack_size_error(const std::string &msg);
};

class stack_bad_alloc : public std::bad_alloc {
public:
	explicit stack_bad_alloc(void);
};

class stack_overflow : public std::logic_error {
public:
	explicit stack_overflow(const std::string &msg);
};

class stack_empty : public std::logic_error {
public:
	explicit stack_empty(const std::string &msg);
};

class Stack {
    private:
	int *stackstore;
	int stacksize;
	int SP;
    public:
	Stack(int size = 100) throw(stack_size_error, stack_bad_alloc);
	~Stack();
	void push(int value) throw(stack_overflow);
	int pop(void) throw(stack_empty);
};
#endif
////////////////////////////////////////////////////////////////////
// << 3.5.1.6 EXCEPTIONS IN ACTION>>
////

Stack again - implementation
Here’s the mystack.cpp content.

You already know all of its parts except for one important line – the first line. Note that we’ve included our header. It’s obligatory – don’t forget that.
/////////////////////
#include "mystack.h"

stack_size_error::stack_size_error(const std::string &msg) : std::length_error(msg) {
};

stack_bad_alloc::stack_bad_alloc(void) : std::bad_alloc() {
};

stack_overflow::stack_overflow(const std::string &msg) : std::logic_error(msg) {
};

stack_empty::stack_empty(const std::string &msg) : std::logic_error(msg) {
};

Stack::Stack(int size) throw(stack_size_error, stack_bad_alloc) {
	if(size <= 0)
		throw stack_size_error("size must be >= 0");
	try {
		stackstore = new int[size];
	} catch(std::bad_alloc ba) {
		throw stack_bad_alloc();
	}
	stacksize = size;
	SP = 0;
}

Stack::~Stack(void) {
	delete stackstore;
}

void Stack::push(int value) throw(stack_overflow) {
	if(SP == stacksize)
		throw stack_overflow("stack size exceeded");
	stackstore[SP++] = value;
}

int Stack::pop(void) throw(stack_empty) {
	if(SP == 0)
		throw stack_empty("stack is empty");
	return stackstore[--SP];
}
////////////////////////////////////////////////////////////////////
// << 3.5.1.7 EXCEPTIONS IN ACTION>>
////
= Stack again – main function =
We need the main function to run the stack. It’ll be easy compared to the hard work with the new stack implementation.

The new main function is in the editor.

Note that we’ve included the #include directive referring to the “mystack.h” header file. This is how the compiler learns about the stack and all of its components, as well as the exceptions we’ve jointly defined.
///////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	Stack stk;
	stk.push(1);
	cout << stk.pop() << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////
// << 3.5.1.8 EXCEPTIONS IN ACTION>>
////
= Stack again – new, better main function =
Here are emperor’s, sorry, main’s, new clothes.

Now we’re prepared for all circumstances (at least we believe so). All stack operations are covered by the try block, and we have a complete set of catches ready to diagnose all problems. Let’s do some crash tests.
/////////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	try {
		Stack stk;
		stk.push(1);
		cout << stk.pop() << endl;
	}
	catch(stack_bad_alloc sba) {
		cout << "No room for the stack - sorry!" << endl;
	}
	catch(stack_size_error sse) {
		cout << "Stacks of that size don't exist - sorry!" << endl;
	}
	catch(stack_overflow se) {
		cout << "Stack is too small for that many pushes - sorry!" << endl;
	}
	catch(stack_empty su) {
		cout << "Stack is empty - sorry!" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////
// << 3.5.1.9 EXCEPTIONS IN ACTION>>
////
= Stack again – crash tests =
First, we’ll check if the constructor properly detects stack size values that are too low - look at the code in the editor.

Ok, it works fine – we’ve got:

Stacks of that size don't exist - sorry!
output
////////////////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	try {
		Stack stk(0);
		stk.push(1);
		cout << stk.pop() << endl;
	}
	catch(stack_bad_alloc sba) {
		cout << "No room for the stack - sorry!" << endl;
	}
	catch(stack_size_error sse) {
		cout << "Stacks of that size don't exist - sorry!" << endl;
	}
	catch(stack_overflow se) {
		cout << "Stack is too small for that many pushes - sorry!" << endl;
	}
	catch(stack_empty su) {
		cout << "Stack is empty - sorry!" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////
// << 3.5.1.10 EXCEPTIONS IN ACTION>>
////
= Stack again – crash tests =
Next, we’ll check if the constructor can handle our exorbitant demands on the stack size - look at the code in the editor.

Ours can - we see:

No room for the stack - sorry!
output
////////////////////////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	try {
		Stack stk(2000000000);
		stk.push(1);
		cout << stk.pop() << endl;
	}
	catch(stack_bad_alloc sba) {
		cout << "No room for the stack - sorry!" << endl;
	}
	catch(stack_size_error sse) {
		cout << "Stacks of that size don't exist - sorry!" << endl;
	}
	catch(stack_overflow se) {
		cout << "Stack is too small for that many pushes - sorry!" << endl;
	}
	catch(stack_empty su) {
		cout << "Stack is empty - sorry!" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////
// << 3.5.1.11 EXCEPTIONS IN ACTION>>
////
= Stack again – crash tests =
Is our stack too-many-pushes-proof?

Yes, it is – it says:

Stack is too small for that many pushes - sorry!
outpu
///////////////////////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	try {
		Stack stk(1);
		stk.push(1);
		stk.push(2);
		cout << stk.pop() << endl;
	}
	catch(stack_bad_alloc sba) {
		cout << "No room for the stack - sorry!" << endl;
	}
	catch(stack_size_error sse) {
		cout << "Stacks of that size don't exist - sorry!" << endl;
	}
	catch(stack_overflow se) {
		cout << "Stack is too small for that many pushes - sorry!" << endl;
	}
	catch(stack_empty su) {
		cout << "Stack is empty - sorry!" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////
////
// << 3.5.1.12 EXCEPTIONS IN ACTION>>
////
= Stack again – crash tests =
And what about too many pops?

That’s okay too:

Stack is empty - sorry!
output

Our mission is complete. It’s time to rest.


///////////////////////////////////
#include "mystack.h"
#include <iostream>

using namespace std;

int main(void) {
	try {
		Stack stk(1);
		stk.push(1);
		cout << stk.pop() << endl;
		cout << stk.pop() << endl;
	}
	catch(stack_bad_alloc sba) {
		cout << "No room for the stack - sorry!" << endl;
	}
	catch(stack_size_error sse) {
		cout << "Stacks of that size don't exist - sorry!" << endl;
	}
	catch(stack_overflow se) {
		cout << "Stack is too small for that many pushes - sorry!" << endl;
	}
	catch(stack_empty su) {
		cout << "Stack is empty - sorry!" << endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////
