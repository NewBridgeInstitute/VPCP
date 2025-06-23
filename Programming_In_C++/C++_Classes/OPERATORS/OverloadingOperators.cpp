/* 4.1.1.1
Operators – a glance at the past
An operator is a symbol designed to operate on data – it’s that simple. The C++ language has a wide range of different operators operating on many different types of data. Some of the operators are more universal, some are more specific, some of them are written as single symbols, some are di-graphs or even tri-graphs, other are keywords.

All C++ language operators are divided into many groups and there’s more than one classification to help us categorize them. One of the possible classifications is based on a number of arguments. We know that there are:

unary operators
binary operators
ternary operators (to be honest, there’s only one ternary operator in the C++ language)
Some of the operators may belong to more than one of the above groups depending on the context they’re used in, e.g. “+” and “&” (and more besides) may work both as unary and binary operators.

Another classification relies on the location of the operator. We distinguish:

prefix operators (placed in front of their argument)
postfix operators (placed after their argument)
infix operators (placed in between their arguments)
*/
///////////////////////////////////////
/* 4.1.1.2
Stack stack(100);
int var;

stack << 200;     // push
stack >> var;   // pop
*/
///////////////////////////////////////
/* 4.1.1.3
#include "mystack_01.h"
#include <iostream>

using namespace std;

int main(void) {
    int i = 2;
    Stack stk;

    stk << 1;
    stk << 2 * i;
    stk << i;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    return 0;
}
*/
/////////////////////////////////////////
/* 4.1.1.4
#include "mystack_02.h"
#include <iostream>

using namespace std;

int main(void) {
    int i = 2;
    Stack stk;
    stk << 1;
    stk << 2 * i;
    stk << i;
    stk >> i; cout << i << endl;
    stk >> i; cout << i << endl;
    stk >> i; cout << i << endl;

    return 0;
}
*/
////////////////////////////////////////
/*4.1.1.5 IMPROVING THE << OPERATOR
#include "mystack_04.h"
#include <iostream>

using namespace std;

int main(void) {
    int i = 2, j;
    Stack stk;
    stk << 1 << 2 * i;
    stk >> j >> i;
    cout << j << endl << i << endl;
    return 0;
}
*/
