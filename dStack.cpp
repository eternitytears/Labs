#include "dArray.h"
#include "dStack.h"
#include <iostream>
using namespace std;

dStack::dStack() {
	size = 0;
	index = -1;
	point = new int[size];
}
void dStack::push(int a) {
	if (size == 0) {
		delete[] point;
		size++;
		index++;
		point = new int[size];
		point[index] = a;
	}
	else {
		int* tmp = new int[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = point[i];
		}
		index++;
		size++;
		tmp[index] = a;
		delete[] point;
		point = tmp;
	}
}

bool dStack::empty() {
	if (index == -1)
		return 1;
	else return 0;
}
void dStack::del() {
	try
	{
		if (this->size = 0) {
			throw exception("Stack is empty");
		}
		int* tmp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			tmp[i] = point[i];
		}
		size--;
		index--;
		delete[] point;
		point = tmp;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int dStack::top() {
	try
	{
		if (this->size = 0) {
			throw exception("Stack is empty");
		}
		return point[index];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int dStack::peek(int ind) {
	try
	{
		if (size == 0) {
			throw exception("Stack is empty");
		}
		if (ind + 1 < size || ind < 0) {
			throw exception("Wrong index");
		}
		return point[ind];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

