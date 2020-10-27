#include <iostream>
#pragma once

class dArray {
public:
	dArray();
	dArray(int in[], int insize);
	dArray(dArray& in);
	~dArray();
	void setElement(int element);
	void searchelement(int detectiveelem);
	void changeelement(int newelement, int numbelem);
	void deleteelement(int num);
	void getArray();
	int* getPoint();
	int getSize();
	void toString(int num, char* out, int &cnt);
private:
	int size;
	int index;
	int *point;
	int currentelement;
	static int statsize, statindex, statcurrentelement;
};