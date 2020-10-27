#include "dArray.h"
#include <iostream>

dArray::dArray() {
	size = 1;
	point = new int[size];
	index = statindex;
	currentelement = statcurrentelement;
	point[index] = currentelement;
}

dArray::dArray(int size) {
	this->size = size;
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

dArray::dArray(const dArray &other) {
	this->size = other.size;
	this->point = new int[other.size];
	this->index = other.index;
	this->currentelement = other.currentelement;
	for (int i = 0; i < other.size; i++) {
		this->point[i] = other.point[i];
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
	}
	else {
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
		}
		else {
			tmp[i] = point[i];
		}
	}
	size--;
	delete[] point;
	point = tmp;
}

void dArray::getArray() {
	char* c = new char[size * 2 + 1];
	int i, count;
	for (i = 0, count = 0; i < size; i++) {
		if (point[i] > 0) {
			toString(abs(point[i]), c, count);
			c[count++] = ' ';
		}
		if (point[i] == 0) {
		    c[count++] = '0';
		    c[count++] = ' ';
		}
		if (point[i] < 0) {
		    c[count] = '-';
		    count++;
		    toString(abs(point[i]), c, count);
		    c[count++] = ' ';
		}
		
	}
	c[count] = '\0';
	std::cout << c << "- array" << std::endl;
}


void dArray::toString(int num, char* out, int& cnt) {
	int i, t;
	for (i = 0, t = num; t > 0; t /= 10, i++);
	for (int j = cnt + i - 1, t = num; j > cnt - 1; t /= 10, j--) {
		out[j] = '0' + (char)(t % 10);
	}
	cnt += i;
}

int* dArray::getPoint() {
	int* tmpoint = new int[size];
	for (int i = 0; i < size; i++) {
		tmpoint[i] = point[i];
	}
	return tmpoint;
}

int dArray::getSize() {
	return size;
}

dArray& dArray::operator = (const dArray& other) {
	delete[] this->point;
	this->point = new int[other.size];
	this->size = other.size;
	this->index = other.index;
	this->currentelement = other.currentelement;
	for (int i = 0; i < other.size; i++) {
		this->point[i] = other.point[i];
	}
	return *this;
}

//dArray dArray::operator + (const dArray& other) {
//	dArray temp;
//	temp = *this;
//	for (int i = 0; i < this->size && i < other.size; i++) {
//		temp.point[i] = this->point[i] + other.point[i];
//	}
//	return temp;
//}

//dArray dArray::operator - (const dArray& other) {
//	dArray temp;
//	temp = *this;
//	for (int i = 0; i < this->size && i < other.size; i++) {
//		temp.point[i] = this->point[i] - other.point[i];
//	}
//	return temp;
//}

dArray dArray::operator + (const dArray & other) {
	dArray temp(this->size + other.size);
	for (int i = 0; i < this->size; i++) {
		temp.point[i] = this->point[i];
	}
	for (int i = this->size; i < temp.size; i++) {
		temp.point[i] = other.point[i - this->size];
	}
	return temp;
}

dArray& dArray::operator ++ () {
	for (int i = 0; i < size; i++) {
		point[i]++;
	}
	return *this;
}

dArray& dArray::operator -- () {
	for (int i = 0; i < size; i++) {
		point[i]--;
	}
	return *this;
}

dArray& dArray::operator ++ (int a) {
	dArray temp(*this);
	for (int i = 0; i < size; i++) {
		point[i]++;
	}
	return *this;
}

dArray& dArray::operator -- (int a) {
	dArray temp(*this);
	for (int i = 0; i < size; i++) {
		point[i]--;
	}
	return *this;
}

int& dArray::operator [](int index) {
	if (index >= this->size) {
		throw std::exception("arrayOutOfBounds");
	}
	return point[index];
}

dArray& operator + (dArray& kekw, int number) {
	for (int i = 0; i < kekw.size; i++) {
		kekw.point[i] = kekw.point[i] + number;
	}
	return kekw;
}

dArray dArray:: operator - (int number) {
	for (int i = 0; i < size; i++) {
		if (point[i] == number) {
			for (int j = i; j < size; j++) {
				point[j] = point[j + 1];
			}
			break; 
		}
	}
    size--;
    return *this;
}