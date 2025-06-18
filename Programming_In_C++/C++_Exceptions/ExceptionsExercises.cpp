/////////////////////////////////////////
//// EXCEPTIONS EXERCISE:
////////////////////////////////////////
// QUESTION 1: spuedo <<311.10>>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

float divide(int a, int b) {

    if(b == 0)

        throw string("You divided 0... ");

        return a/b;
}

int main(void) {

    float a, b;

    while(cin >> a) {

        try {

            cin >> b;

            cout << divide(a, b) << endl;

        } catch (string &problem) {

        cout << "Cannot divide by zero! " << endl;
        cout << problem << endl;
        }

    }

    return 0;

}

////////////////////////////////////////////////
// QUESTION 2:
/*
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;
class InvalidAgeException

int main() {

    cout << " " << endl;
    return 0;
}
*/
