//
// Cat readable
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	string line;
	fstream myfile;
	myfile.open("example.txt" ,ios::out | ios::in );

	if (myfile.is_open()){

		string test;
		myfile >> test;
		string bla;
		myfile >> bla;
		cout << test << endl <<bla << endl;

		myfile << "\nblabla\n";
		
		myfile.close();

	}
	else cout << "unable to open the file\n";

	return 0;
}
