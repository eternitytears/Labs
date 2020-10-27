#include <iostream>
#pragma once

class dArray {
public:
	dArray();
	dArray(int size);
	dArray(int in[], int insize);
	dArray(const dArray& other);
	~dArray();
	void setElement(int element);
	void searchelement(int detectiveelem);
	void changeelement(int newelement, int numbelem);
	void deleteelement(int num);
	void getArray();
	int* getPoint();
	int getSize();
	void toString(int num, char* out, int& cnt);
	dArray& operator = (const dArray& other);
	dArray operator + (const dArray&other);
    friend dArray& operator + (dArray& kekw, int number);
	//dArray operator - (const dArray& other);
	dArray operator - (int number);
	dArray& operator ++ ();
	dArray& operator -- ();
	dArray& operator ++ (int a);
	dArray& operator -- (int a);
	int& operator [](int index);
private:
	int size;
	int index;
	int* point;
	int currentelement;
	static int statsize, statindex, statcurrentelement;
};
