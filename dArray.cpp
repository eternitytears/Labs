#include "dArray.h"
#include <iostream>
#include <fstream>
using namespace std;

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

dArray::dArray(const dArray& other) {
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
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++) {
			tmp[i] = point[i];
	}

	tmp[size++] = element;
	delete[] point;
	point = tmp;
}

void dArray::searchElement(int detectiveelem) {
	try
	{
		if (size == 0) {
			throw exception("Array is empty");
		}
		int i;
		for (i = 0; i < size; i++) {
			if (point[i] == detectiveelem) {
				std::cout << "\nSearched element index: " << i << "; searched element value: " << point[i];
			}
		}
		if (i == size) {
			throw exception("Search failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

void dArray::changeElement(int newelement, int numbelem) {
	try
	{
		if (numbelem + 1 == size || numbelem < 0) {
			throw exception("Wrong index");
		}
		if (size == 0) {
			throw exception("Array is empty");
		}
		for (int i = 0; i < size; i++) {
			if (i == numbelem) {
				point[i] = newelement;
			}
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void dArray::deleteElement(int num) {
	try
	{
		if (num + 1 >= size || num < 0) {
			throw exception("Wrong index");
		}
		if (size == 0) {
			throw exception("Array is empty");
		}
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
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

    void dArray::getArray() {
	try
	{
		if (size == 0) {
			throw exception("Array is empty");
		}
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
		std::cout << "Size: " << size << endl << "Array: " << c << std::endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
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

dArray dArray::operator + (const dArray& other) {
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

bool operator < (const dArray& one, const dArray& two) {
	return one.size < two.size;
}
bool operator > (const dArray& one, const dArray& two) {
		return one.size > two.size;
}

int& dArray::operator [](int index) {
	try
	{
		if (index >= this->size) {
			throw exception("Array index out of bounds");
		}
		return point[index];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

dArray& operator + (dArray& kekw, int number) {
	for (int i = 0; i < kekw.size; i++) {
		kekw.point[i] = kekw.point[i] + number;
	}
	return kekw;
}

dArray dArray:: operator - (int number) {
	try
	{
		int i;
		for (i = 0; i < size; i++) {
			if (point[i] == number) {
				for (int j = i; j < size; j++) {
					point[j] = point[j + 1];
				}
				break;
			}
		}
		size--;
		if (i == size) {
			throw exception("Wrong number");
		}
		return *this;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

bool dArray::operator == (const dArray& other) {
	if (this->size != other.size) {
		return 0;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->point[i] != other.point[i]) {
			return 0;
		}
	}
	return 1;
}

ostream& operator<< (ostream& os, dArray& ar) {
	os << "Size: " << ar.size << endl << "Array: ";
	for (int i = 0; i < ar.size; i++) {
		os << ar.point[i] << " ";
	}
	os << endl;
	return os;
}

istream& operator>> (istream& is, dArray& ar) {
	if (ar.point) delete[] ar.point;
	cout << "Enter size" << endl;
	is >> ar.size;
	ar.point = new int[ar.size];
	cout << "Enter array with this size " << ar.size << " " << endl;
	for (int i = 0; i < ar.size; i++) {
		is >> ar.point[i];
	}
	return is;
}

ofstream& operator<< (ofstream& os, dArray& ar) {
	try
	{
		if (!os) {
			throw exception("File open error");
		}
		os << "Size: " << ar.size << endl << "Array: ";
		for (int i = 0; i < ar.size; i++) {
			os << ar.point[i] << " ";
		}
		os << endl;
		return os;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

ifstream& operator>> (ifstream& is, dArray& ar) {
	try
	{
		if (!is) {
			throw exception("File open error");
		}
		if (ar.point) {
			delete[] ar.point;
		}
		is.seekg(6, ios::cur);
		is >> ar.size;
		ar.point = new int[ar.size];
		is.seekg(8, ios::cur);
		for (int i = 0; i < ar.size; i++) {
			is >> ar.point[i];
		}
		is.seekg(2, ios::cur);
		return is;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void dArray::write(ostream& os)
{
	try
	{
		if (!os) {
			throw exception("File open error");
		}
		os.write((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++) {
			os.write((char*)&point[i], sizeof(point[i]));
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	
}

void dArray::read(istream& in)
{
	try
	{
		if (!in) {
			throw exception("File open error");
		}
		in.read((char*)&size, sizeof(size));
		if (point) {
			delete[] point;
			point = new int[size];
		}
		for (int i = 0; i < size; i++) {
			in.read((char*)&point[i], sizeof(point[i]));
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}