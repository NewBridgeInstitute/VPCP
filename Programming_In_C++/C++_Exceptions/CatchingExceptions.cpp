//<< 3.4.1.1 CATCHING EXCEPTIONS >>

/*
= Different catches for different purposes =

As you’ve already learnt, the catch instruction is supposed to “catch” events passing through the instruction’s scope. You also know that the catch “catches” only these exceptions that are compatible in type with the catch header. For example, the following instruction:

///////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	}
}
int main(void) {
	for(int i = 0; i < 3; i++) {
		try {
			function(i);
		}
		catch(...) {
			cout << "Exception caught!" << endl;
		}
	}
	return 0;
}
*/
/////////////////////////////

/* << 3.4.1.2 >>
- We’ve modified our program – can you see the difference? Yes, we’ve changed the catch header and added the “exception ex” instead of the ellipsis.
////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	case 3: throw exception();
	}
}
int main(void) {
	for(int i = 0; i < 4; i++) {
		try {
			function(i);
		}
		catch(exception &ex) {
			cout << "Exception caught: " << ex.what() << endl;
		}
	}
	return 0;
}
////////////////////////

<< 3.4.1.3 >>
- If we’re going to, or if we have to, provide different ways of handling different exceptions, we’re allowed to specify as many different catch branches as we want (or need). In our example, the function throws four different exceptions and we can make four catch branches: one branch per exception type.

The modified program is in the editor.

Currently, each of the exceptions is handled separately.
//////////////////////////
#include <iostream>
#include  <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	case 3: throw exception();
	}
}
int main(void) {
	for(int i = 0; i < 4; i++) {
		try {
			function(i);
		}
		catch(out_of_range &ofr) {
			cout << "Out of range: " << ofr.what() << endl;
		}
		catch(overflow_error &ovf) {
			cout << "Overflow: " << ovf.what() << endl;
		}
		catch(domain_error &dmn) {
			cout << "Domain: " << dmn.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
	}
	return 0;
}
//////////////////////////

<< 3.4.1.4 >>
- There’s no need to choose between “all or none”. We can selectively choose the exceptions we want to catch and handle carefully, and those that we want to handle very briefly.

The code in the editor mixes the two previous approaches: some of the exceptions are caught individually while others go to the ellipsis.
///////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	case 3: throw exception();
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(out_of_range &ofr) {
			cout << "Out of range: " << ofr.what() << endl;
		}
		catch(overflow_error &ovf) {
			cout << "Overflow: " << ovf.what() << endl;
		}
		catch(domain_error &dmn) {
			cout << "Domain: " << dmn.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
///////////////////////////

<< 3.4.1.5 >>
- Order of the catch branches
Our last question may suggest that the order of the catch branches matters. Does it really matter?

The answer isn’t really clear: yes and no.

We’ll show you two examples justifying both answers.

We’ll start from the “no” variant.

Take a look at the example: we’ve swapped two of the first catch branches. Does it change the program’s behaviour?
///////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	case 3: throw exception();
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(overflow_error &ovf) {
			cout << "Overflow: " << ovf.what() << endl;
		}
		catch(out_of_range &ofr) {
			cout << "Out of range: " << ofr.what() << endl;
		}
		catch(domain_error &dmn) {
			cout << "Domain: " << dmn.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
////////////////////////////////////

<< 3.4.1.6 >>
- It’s time for the next swap. Now we’ve swapped the first and the fourth catch branches.

[Does it change the program’s behaviour?

Yes, it does!]

First of all, you should expect that the compiler is going to produce some warning messages. It won’t prevent your program from being successfully compiled, but the warnings suggest that not everything has gone as we would have liked.
////////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw out_of_range("0");
	case 1: throw overflow_error("1");
	case 2: throw domain_error("2");
	case 3: throw exception();
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(out_of_range &ofr) {
			cout << "Out of range: " << ofr.what() << endl;
		}
		catch(overflow_error &ovf) {
			cout << "Overflow: " << ovf.what() << endl;
		}
		catch(domain_error &dmn) {
			cout << "Domain: " << dmn.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
///////////////////////////////////

<< 3.4.1.7 >>
- When the exception arrives at a set of catch branches, the first compatible branch is chosen (and only this one) as a target handler.

This means that when a more general type/class is placed before the more specific compatible type/class, the second branch will receive no exceptions at all.
//////////////////////////////////////
#include<iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
	}
	return 0;
}
////////////////////////////////////////

<< 3.4.1.8 >>
- We can repair our program in a very simple way – all we have to do here is add an ellipsis branch, which will be responsible for taking care of all the orphaned exceptions. Of course, it’s not a remedy for all your problems with unhandled exceptions. Real life creates more complicated circumstances.
/////////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
/////////////////////////////////////////

<< 3.4.1.9 >>
-
Now we’re going to test you. The next two slides should prove that you understand the process of selecting the target exception handler.

We’ve modified the previous program slightly – you can find it in the editor.

Can you predict its output?

You’ll find the answer on the next slide.
////////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
/////////////////////////////////////

<< 3.4.1.10 >>
- Your answer should look like this:

Logic error: 0

Logic error: 1

Exception: Unknown exception

Exception: 2

Something bad happened
output

Another test for you – it’s in the editor. Can you see the difference? Can you predict the program output?
///////////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			function(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(runtime_error &re) {
			cout << "Runtime error: " << re.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
/////////////////////////////////////////////

<< 3.4.1.10 >>
- Sharing the responsibility
The answer is:

Logic error: 0

Logic error: 1

Exception: Unknown exception

Runtime error: 2

Something bad happened
output

Is your answer the same?

Now we’ll make our program more complex (look at the code in the editor). We’ve added a broker between the main and the function. The broker handles some of the passing exceptions, namely those compatible with the exception class. Now the handling process is dispersed over two levels: lower (inside broker) and upper (inside main).

The output of the program is as follows:

Broker - exception: 0

Broker - exception: 1

Broker - exception: Unknown exception

Broker - exception: 2

Something bad happened
output

As you see, most of the exceptions have been handled by the broker and haven’t reached the main function. You can use this method when you want to divide the responsibility of handling different kinds of exceptions between different layers of the program logic.
//////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
void broker(int i) {
	try { function(i); }
	catch(exception ex) { cout << "Broker - exception: " << ex.what() << endl; }
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			broker(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(runtime_error &re) {
			cout << "Runtime error: " << re.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
////////////////////////////////////////

<< 3.4.1.12 >>
-
The program in the editor will check your understanding of the problem. Can you predict its output?

Yes, it’ll look like this:
/////////////////////////////////////////
#include <stdexcept>
#include <exception>
#include <iostream>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
void broker(int i) {
	try { function(i); }
	catch(logic_error &le) { cout << "Broker - logic_error: " << le.what() << endl; }
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			broker(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(runtime_error &re) {
			cout << "Runtime error: " << re.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
//////////////////////////////////////

<< 3.4.1.13 >>
- A badly constructed broker may ruin the exception handling logic at higher levels. Take a look at the example code in the editor.

The broker’s decided to take control over all arriving exceptions. None of them will leave the broker. We can say that “everything that comes to the broker stays in the broker”.

The output of the program isn’t really varied – this is how it looks:
/////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
void broker(int i) {
	try {
		function(i);
	}
	catch(...) {
		cout << "Broker swept problems under the carpet " << endl;
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			broker(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(runtime_error &re) {
			cout << "Runtime error: " << re.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
////////////////////////////////////

<< 3.4.1.14 >>
- The responsibility of handling exceptions may not only be divided – it may be shared, too. This means that the handling of the same exceptions may be provided at more than one level.

Note that any of the catch branches might throw an exception too, and the exception won’t be handled in the place where it was created, but at a higher level.
/////////////////////////////////////
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
void function(int i) {
	switch(i) {
	case 0: throw domain_error("0");
	case 1: throw logic_error("1");
	case 2: throw exception();
	case 3: throw range_error("2");
	case 4: throw "so bad";
	}
}
void broker(int i) {
	try {
		function(i);
	}
	catch(...) {
		cout << "Broker swept problems under the carpet " << endl;
		throw;
	}
}
int main(void) {
	for(int i = 0; i < 5; i++) {
		try {
			broker(i);
		}
		catch(logic_error &le) {
			cout << "Logic error: " << le.what() << endl;
		}
		catch(runtime_error &re) {
			cout << "Runtime error: " << re.what() << endl;
		}
		catch(exception &ex) {
			cout << "Exception: " << ex.what() << endl;
		}
		catch(...) {
			cout << "Something bad happened" << endl;
		}
	}
	return 0;
}
/////////////////////////////////////////

