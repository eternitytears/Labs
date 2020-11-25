#include "dArray.h"
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
	int* tmp = new int[size - 1];
	for (int i = 1; i < size; i++) {
		tmp[i - 1] = point[i];
	}
	index--;
	size--;
	delete[] point;
	point = tmp;
}
int dQueue::front() {
	return point[0];
}
int dQueue::back() {
	return point[index];
}
int dQueue::peek(int ind) {
	return point[ind];
}