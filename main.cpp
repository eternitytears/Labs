#include "dArray.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;

bool teststream() {
	int b[5] = { 1,2,3,4,5 };
	dArray temp(b, 5);
	stringstream stream("");
	stream << temp;
	if (stream.str() == "Size: 5\nArray: 1 2 3 4 5 \n") {
		return 1;
	}
	else {
		return 0;
	}
}

bool testtextfile(dArray one, dArray two) {
	dArray temp1 = one;
	dArray temp2 = two;
	ofstream f1("text.txt");
	if (!f1) {
		cout << "File open error " << endl;
		return 1;
	}
	f1 << two << one;
	f1.close();

	ifstream f("text.txt");
	if (!f) {
		cout << "File open error " << endl;
		return 1;
	}
	f >> two >> one;
	f.close();
	if (temp1 == one && temp2 == two) {
		return 1;
	}
	else {
		return 0;
	}
}

bool testdatfile(dArray two) {
	dArray temp2 = two;
	ofstream in("asdasd.dat", ios::binary | ios::app);
	if (!in) {
		cout << "File open error " << endl;
		return 1;
	}
	two.write(in);
	in.close();
	ifstream out("asdasd.dat", ios::binary | ios::app);
	if (!out) {
		cout << "File open error " << endl;
		return 1;
	}
	two.read(out);
	out.close();
	if (temp2 == two) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int a[2] = { 3,2 };
	int b[8] = { 3,4,5,6,7,8,9,10 };
	int c[5] = { 1,2,3,4,5 };
	dArray one(a, 2);
	dArray two(b, 8);
	dArray three(c, 5);
	int x = 0;
	int y = 0;

	/*ofstream f1("text.txt");
	if (!f1) {
		cout << "File open error " << endl;
		return 1;
	}
	f1 << two << one << three;
	f1.close();
	ifstream f("text.txt");
	if (!f) {
		cout << "File open error " << endl;                         // txt file write/read
		return 1;
	}
	f >> two >> one >> three;
	f.close();
	cout << two << one << three;
	ofstream out("asd.dat", ios::binary | ios::in);
	out.write((char*)&two, sizeof(two));
	out.close();
	ifstream in("asd.dat", ios::binary | ios::out);
	in.read((char*)&two, sizeof(two));
	in.close();
	cout << two;
	cout << testtextfile(one, two);*/

	//ofstream in("asdasd.dat", ios::binary);
	//two.write(in);
	//one.write(in);
	//in.close();
	//ifstream out("asdasd.dat", ios::binary);            // binary file write/read
	//two.read(out);
	//one.read(out);
	//out.close();
	//cout << two << one;

	//cout << testdatfile(two);
	if (testtextfile(one,two) == 1) {
		cout << "Text file test successful." << endl;
	}
	else {
		cout << "Text file test failed." << endl;
	}

	if (testdatfile(two) == 1) {
		cout << "Dat file test successful." << endl;
	}
	else {
		cout << "Dat file test failed." << endl;
	}

	if (teststream() == 1) {
		cout << "Stream test successful." << endl;
	}
	else {
		cout << "Stream test failed. " << endl;
	}
}