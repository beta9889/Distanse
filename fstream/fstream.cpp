#include <iostream>
#include <fstream>

using namespace std;

int main (){
    ofstream myfile ("bla.txt");
   
    if (myfile.is_open()){
	    myfile << "blablabla \n";
	    myfile << "second line bla bla \n";
	    myfile.close();
    }
    else{
	    cout << "messup up file opening";
    }
    return 0;


}
