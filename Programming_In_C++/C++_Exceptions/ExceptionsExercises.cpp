////////////////////////////////////////
//// EXCEPTIONS EXERCISE:
////////////////////////////////////////
/*/ QUESTION 1: sudo<<311.10>>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

float divide(int a, int b) { // MY INTEGERS

    if(b == 0) // CHECKING FOR DIVISION BY ZERO

        throw string("You divided 0... ");  // THROWING AN EXCEPTION

        return a/b;  // RETURNING THE RESULT OF THE DIVISION
}

int main(void) { // MAIN

    float a, b; // DECLARING FLOATING POINT VARIABLES

    while(cin >> a) {  // WHILE LOOP TO CONTINUE READING INPUT

        try {  // TRY BLOCK TO CATCH EXCEPTIONS

            cin >> b;  // READING SECOND FLOATING POINT VARIABLE

            cout << divide(a, b) << endl;  // CALLING THE DIVIDE FUNCTION

        } catch (string &problem) {  // CATCHING STRING EXCEPTIONS

        cout << "Cannot divide by zero! " << endl;  // PRINTING A MESSAGE
        cout << problem << endl;
        }

    }

    return 0;

}
*/
/*
////////////////////////////////////////////////
// QUESTION 2:

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;
class InvalidAgeException

int main() {

    cout << " " << endl;
    return 0;
}
*/
