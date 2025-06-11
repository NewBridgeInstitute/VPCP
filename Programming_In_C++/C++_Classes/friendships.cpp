class Class { // Defining class named 'Class'
friend class Friend; // Grants 'Friend' access to private members of 'Class'

private:
    int field; // A private integer member variable, not accessible outside this class

    void print(void) // A private function that prints the value of 'field'
    { cout << "It's a secret, that field = " << field << endl; } //Outputs the value of "field"
};

class Friend { // Defines another class named 'Friend'
public:
    void DoIt (Class &c) { // A public function that modifies 'Class' object
         c.field = 100; // Changes the private variable 'field' inside 'Class' (allows due to 'friend' declaration)
         c.print(); //Calls the private 'print' function of 'Class' to display the updated value
    }
};
int main(void) { // Is the entry point of the program
    Class o; // Creates an instance of "CLass"
    Friend f; // Creates an instance of 'Friend'

    f.DoIt(o); // Calls 'DoIt' function on 'o', modifying 'field' and printing it's new value
    return 0; // And then 'return 0' of cause indicates successful execution(if you did not know by now:))
}

