/*
// Calculate Circle Area
#include <iostream>
using namespace std;

const double PI = 3.14159;

int main () {
    double radius, area;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    area = PI * radius * radius;

    cout <<"Ther area of the circle is: " << area <<endl;

    return 0;
}
*/
/*FRIENDS OF CLASSES EXERCISE:*/

#include <iostream>
using namespace std;
class Sport {
private:
    int players;
    void print(void) { cout << "This sport has: " << players << " players" << endl;}
public:
    friend class Golf;
    friend class Baseball;
};
class Golf {
public:
    void play (Sport &s) { s.players = 853; s.print();}
};
class Baseball {
public:
    void play(Sport &s) { s.players = 962; s.print();}
};
int main() {
    Sport sport;
    Golf golf;
    Baseball baseball;
    golf.play(sport);
    baseball.play(sport);
return 0;
}






















