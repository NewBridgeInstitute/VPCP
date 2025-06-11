#include <iostream>
//#include <string>
using namespace std;
class Super {
private:
    int storage;
public:
    void put(int val) { storage = val; }
    int get(void) { return storage; }
};
int main(void) {
    Super object;

    object.put(582);
    object.put(object.get() + 1);
    cout << object.get() << endl;
    return 0;
}
