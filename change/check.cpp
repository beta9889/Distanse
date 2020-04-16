#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "check int :";
    string test;
    cin >> test;
    if (bool has_only_didgts = (test.find_first_not_of("012345679") == std::string::npos)){
        cout << "only integers\n";
	 }
    else {
    cout << "contains string\n";
    }
    return 0;
}

