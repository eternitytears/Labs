#pragma once
#include "dArray.h"
#include "dStack.h"
#include "dQueue.h"
#include "List.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;


int main() {
	int A[3] = { 1,2,3 };
	dArray one(A, 3), two(0);
	two.getArray();
	one[5];
	one.deleteElement(5);
	cout << "File open error";
}