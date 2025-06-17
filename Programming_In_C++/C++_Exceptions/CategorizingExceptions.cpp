/*
<< 3311 CATEGORIZING EXCEPTIONS>>

= Exception classes hierarchy =
-------------------------------
We’ve said previously that any object of any class (or even the value of any basic type) may be used as a container for an event. In spite of this, there’s a predefined hierarchy of classes designed especially for this purpose.

We showed it to you at our first meeting devoted to exceptions. Now we’re going to go deeper inside this issue.


You may ask about the rationale: why do we need to categorize like this? Is it really useful? Is it effective?

Yes, it is. It allows us to build a universal and extensible mechanism for handling exceptions.

Sometimes we may want to accurately identify all the possible causes of our problems. And sometimes it’s enough for us to know the general conditions which may cause the exception.

Both approaches can coexist within the same program, e.g. at different levels of the program’s logic. This is why such a hierarchy may simplify our code.

Additionally, the hierarchy may be extended in many ways, allowing us to adapt this scheme to our specific needs.

But before we start discussing the hierarchy, we need to say a few words about a new keyword we haven’t mentioned yet.
*/
/////////////////////////////////////////////////////////////////
/*
<< 3312 >>
- The 'explicit' keyword -
The explicit keyword may be placed in front of a class’s constructor declaration. It protects the constructor from being used in any context requiring the use of implicit conversions. This constructor may only be used in an explicit way; hence, the keyword is used when a programmer wants to avoid any side effects that may result from the reckless use of the selected constructors, or indeed of all constructors.

Take a look at the example in the editor.

There are two very similar classes, named A and B, respectively. They’re both dummies, in fact – they do nothing at all, but they’re suitable for our didactic purposes. As you can see, they’re almost identical. The only difference comes from the constructor declaration: the A class makes use of the explicit keyword, while the B class doesn’t.
//////
class A {
public:
   explicit A(int) {}
};

class B {
public:
   B(int) {}
};
int main(void) {
	A a = 1;  // compilation error!
	B b = 1;
	return 0;
}
///////

<< 3313 >>
The 'exception' class
Yes, it’s obligatory.

The exception class is a base (or a root) for all other predefined exceptions. It contains a function called what, which is designed to provide a pointer to the so-called “C”-style string (a character sequence terminated with a null character) describing the nature of the exception.

::Note that the exact form of this message is implementation-dependent and different compilers may name the same events in different ways.

The example program in the editor illustrates the functioning of that mechanism. We’ve tried to perform illegal typecasting and used the exception object caught by the catch statement to demonstrate the message we may get.

#We’ve got “[Bad dynamic_cast!]” ...and you?
////
#include <iostream>
#include <exception>
using namespace std;

class A {
public:
   virtual void f(void) {}
};

class AA : public A {
public:
   void aa(void) {};
};

int main(void) {
	A a;
	try {
		dynamic_cast<AA &>(a).aa();
	} catch (exception ex) {
		cout << "[" << ex.what() << "]" << endl;
	}
	return 0;
}
////

<< 3314 >>
/*THE 'LOGIC_ERROR CLASS'
exception ← logic_error

It’s designed to represent all the exceptions caused by a violation of the rules imposed by the logic of the algorithm/program. It may (but doesn’t always) mean that exceptions of this kind are preventable, i.e. they won’t happen if all the processed data is valid. It also means that this kind of exception may be predicted statically by analysing the structure of the source code.
The constructor of the class allows us to “pack” a detailed message inside the exception object.
*/
/*THE 'DOMAIN_ERROR' CLASS
exception ← logic_error ← domain_error

The domain_error class is derived from the logic_error class. It’s designed to represent all exceptions caused by the data exceeding the permissible range. The term “domain” comes from mathematical terminology and describes a set of all arguments that the function is defined for. Using a value of 100 for the field designed to store an employee's age is a good reason to throw such an exception.
*/
/*THE 'INVALID_ARGUMENT' CLASS
exception ← logic_error ← invalid_argument

The invalid_argument class is derived from the logic_error class. It’s designed to represent all exceptions caused by passing improper arguments to methods or functions or constructors.
Passing a string containing only letters to a function expecting a date coded in ISO8601 format may be considered a reason for throwing this kind of exception.
*/
///////////////////////////////////////////////////////////////
/*
////////////////
<< 3315 CATEGORIZING EXCEPTIONS(CONTINUES 'ERROR CLASS EXPLANATIONS') >>
////////////////

*/
