//
//cat readable
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    
    ofstream file;
    file.open ("text.txt");
    cout << "Type something for text editor\n";
    
    string input;
    cin >> input;

    file << input;
    file.close();




    ifstream print;
    print.open("afile.txt");
    input = "something different";
     

    print  >> input;
    cout << "done : ";
    cout << input << endl;

    file.close();
    return 0;

}
