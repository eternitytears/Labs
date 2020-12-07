#include "dQueue.h"
#include <iostream>
using namespace std;

dQueue::dQueue() {
	size = 0;
	index = -1;
	point = new int[size];
}
void dQueue::push(int a) {
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
bool dQueue::empty() {
	if (index == -1)
		return 1;
	else return 0;
}
void dQueue::del() {
	try
	{
		if (size == 0) {
			throw exception("Queue is empty");
		}
		int* tmp = new int[size - 1];
		for (int i = 1; i < size; i++) {
			tmp[i - 1] = point[i];
		}
		index--;
		size--;
		delete[] point;
		point = tmp;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int dQueue::front() {
	try
	{
		if (size == 0) {
			throw exception("Queue is empty");
		}
		return point[0];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int dQueue::back() {
	try
	{
		if (size == 0) {
			throw exception("Queue is empty");
		}
		return point[index];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

}
int dQueue::peek(int ind) {
	try
	{
		if (size == 0) {
			throw exception("Queue is empty");
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

void dQueue::getArray() {
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
		std::cout << "Size: " << size << endl << "Queue: " << c << std::endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}