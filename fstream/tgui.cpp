#include <fstream>
#include <iostream>
using namespace std;

int main (){
	char data[100];

	ofstream outfile;
	outfile.open("afile.txt");

	cout << "name : ";
	cin.getline(data, 100);

	outfile << data <<endl;

	cout << "enter your age : ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;

	outfile.close();
	
	//open file
	ifstream infile;
	infile.open("afile.txt");

// first line of file
	infile >> data;
	cout << data << endl;
//second line of file
	infile >> data;
	cout << data << endl;

	infile.close();

	return 0;
}
