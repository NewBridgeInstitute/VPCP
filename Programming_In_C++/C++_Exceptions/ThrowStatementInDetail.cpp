/*
Throw and catch coupled together
Now we’re going to talk about some details regarding the throw instruction. Of course, we can’t talk about it without its companion, the catch statement. Nevertheless, the throw is the main character of our story now, although we promise that the next episode will be devoted to catch’s life and problems.

Let’s go back to the simplest form of exception handling, where our two actors play their roles on the same stage i.e. inside the same function. You’ve already learnt how it works. Take our example (shown here in the editor) as a quick reminder.

The DoCalculations function contains four “sensible” fragments where an error may occur: they’re connected to divisions which – as we all know perfectly well – may go wrong sometimes.

All these divisions are “protected” by appropriate checks and in case of a wrong argument, an exception is thrown. The exception is “packed” in a box of type string and carries a simple message describing the problem.

There’s also one catch branch designed to catch the exception and provide very simple (and, to be honest, very naive) handling.

One important fact we want to emphasize here: the exception specification placed in the catch branch header, e.g. this one:

catch(string &exc)

works like a local (automatic) variable declaration. This means that inside the following snippet:

int main(void) {

string str;

try {

throw string("1");

} catch(string &str) {

cout << str;

}

return 0;

}

there are two different variables, named str (the former is hidden by the latter inside the catch block).

The example program outputs the following text to the screen:

catch(string &exc)

works like a local (automatic) variable declaration. This means that inside the following snippet:

Something bad happened: Bad arg d

You should be able to explain this easily enough.
START CODE SAMPLES HERE:...
-->[[// << 3211 THROW STAT IN DETAIL: >>
#include <iostream>
using namespace std;
float DoCalculations(float a, float b, float c, float d) {
    try {
	float x;
	if(a == 0.0)
		throw string("Bad arg a");
	x = 1 / a;
	if(b == 0.0)
		throw string("Bad arg b");
	x /= b;
	if(c == 0.0)
		throw string("Bad arg c");
	x /= c;
	if(d == 0.0)
		throw string("Bad arg d");
	return x / d;
   } catch(string &exc) {
	cout << "Something bad happened: " << exc << endl;
	return 0;
   }
}
int main(void) {
	DoCalculations(1,2,3,0);
	return 0;
}
]]

<< 3213 >>
