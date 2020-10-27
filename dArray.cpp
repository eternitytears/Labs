#include "dArray.h"
#include <iostream>

dArray::dArray() {
	size = 1;
	point = new int[size];
	index = statindex;
	currentelement = statcurrentelement;
	point[index] = currentelement;
}

dArray::dArray(int in[], int insize) {
	if (insize < statsize) {
		size = insize;
	}
	else {
		size = statsize;
	}
	point = new int[size];
	index = statindex;
	for (int i = 0; i < size; i++) {
		point[i] = in[i];
	}
	currentelement = point[index];
}

dArray::dArray(dArray& in) {
	size = in.size;
	point = new int[size];
	index = in.index;
	currentelement = in.currentelement;
	for (int i = 0; i < size; i++) {
		point[i] = in.point[i];
	}
}

dArray::~dArray() {
	if (point) {
		delete[] point;
	}
}

void dArray::setElement(int element) {
	if (size == statsize) {
		std::cout << "Array is over";
	} else {
		int* tmp = new int[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = point[i];
		}

		tmp[size++] = element;
		delete[] point;
		point = tmp;
	}
}

void dArray::searchelement(int detectiveelem) {
	for (int i = 0; i < size; i++) {
		if (point[i] == detectiveelem) {
			std::cout << "\nSearched element index: " << i << "; searched element value: " << point[i];
		}
	}
}

void dArray::changeelement(int newelement, int numbelem) {
	for (int i = 0; i < size; i++) {
		if (i == numbelem) {
			point[i] = newelement;
		}
	}
}

void dArray::deleteelement(int num) {
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		if (i == num) {
			tmp[i] = point[i + 1];
			num++;
		} else {
			tmp[i] = point[i];
		}
	}
	size--;
	delete[] point;
	point = tmp;
}

void dArray::getArray() {
	char* c = new char[size*2 + 1];
	int i, count;
	for (i = 0, count = 0; i < size; i++) {
		toString(point[i], c, count);
		c[count++] = ' ';
	}
	c[count] = '\0';
	std::cout << c << " - array";
}


void dArray::toString(int num, char* out, int &cnt) {
	int i, t;                 
	for (i = 0, t = num; t > 0; t /= 10, i++);
	for (int j = cnt + i - 1, t = num; j > cnt - 1; j--) {
		out[j] = '0' + (char)(t % 10);   
	}
	cnt += i;
}

int* dArray::getPoint() {
	return point;
}

int dArray::getSize() {
	return size;
}