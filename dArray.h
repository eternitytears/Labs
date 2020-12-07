#include <iostream>
#include <fstream>
#pragma once
using namespace std;

class dArray {
public:
	dArray();
	dArray(int size);
	dArray(int in[], int insize);
	dArray(const dArray& other);
	~dArray();
	void setElement(int element);
	void searchElement(int detectiveelem);
	void changeElement(int newelement, int numbelem);
	void deleteElement(int num);
	virtual void getArray();
	int* getPoint();
	void write(ostream& os);
	void read(istream& in);
	int getSize();
	void toString(int num, char* out, int& cnt);
	dArray& operator = (const dArray& other);
	dArray operator + (const dArray& other);
	dArray operator - (int number);
	dArray& operator ++ ();
	dArray& operator -- ();
	dArray& operator ++ (int a);
	dArray& operator -- (int a);
	bool operator == (const dArray& other);
	int& operator [](int index);
	friend dArray& operator + (dArray& kekw, int number);
	friend ostream& operator<<(ostream& os, dArray& ar);
	friend istream& operator>> (istream& is, dArray& ar);
	friend ofstream& operator<< (ofstream& os, dArray& ar);
	friend ifstream& operator>> (ifstream& is, dArray& ar);


protected:
	int size;
	int index;
	int* point;
	int currentelement;
	static int statsize, statindex, statcurrentelement;
};