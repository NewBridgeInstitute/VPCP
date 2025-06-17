//HOW TO GET IN TROUBLE:
//<< 3111 >>
//NOTHING WILL SHOW IN THIS E.G.
/*
#include <iostream>

using namespace std;

int main(void) {
	float a, b;
	cin >> a;
	cin >> b;
	cout << a / b << endl;
	return 0;
}

//<< 3112 >>
#include <iostream>

using namespace std;

int main(void) {
	float a, b;
	while(cin >> a) {
		cin >> b;
		cout << a / b << endl;
	}
	return 0;
}

//<< 3113 >>
#include <iostream>

using namespace std;

int main(void) {
	float a, b;
	while(cin >> a) {
		cin >> b;
		if(b != 0.0)
			cout << a / b << endl;
		else
			cout << "Are you kidding me?" << endl;
	}
	return 0;
}
//<< 3114 >>
#include <iostream>
using namespace std;
bool div(float &res, float arg1, float arg2) {
	if(arg2 == 0.0)
		return false;
	res = arg1 / arg2;
	return true;
}
int main(void) {
	float r, a, b;
	while(cin >> a) {
		cin >> b;
		if(div(r,a,b))
			cout << r << endl;
		else
			cout << "Are you kidding me?" << endl;
	}
	return 0;
}

//<< 3115 >>
//We’ve showed this in the example here as a pseudocode:
[[
bool low_level_eval(…) {
    :
    if(something_went_wrong) return false;
    :
}
bool middle_level_eval(…){
    :
    bool result = low_level_eval(…);
    if(!result) return false;
    :
}
bool top_level_eval(…){
    :
    bool result = middle_level_eval(…);
    if(!result) return false;
    :
}
int main(void){
    :
    bool result = top_level_eval(…);
    if(!result) {
        cout << "Sarcasm!" << endl;
        return 1;
    }
}
]]

// << 3116 >>
//ANATOMY OF AN EXCEPTION OBJECT:
THE EXCEPTION CLASS IS VERY MODEST(SIMPLE).
[[VITUAL CHAR* WHAT() ]]
//WHERE ARE EXCEPTIONS THROWN?
YOU DO HIS BY USING THE "TRY" STATEMENT.
[[
TRY {
    :
    :
    :
]}..

//<< 3117 >>
