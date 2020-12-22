#pragma once
#include "dArray.h"
#include "dStack.h"
#include "dQueue.h"
#include "List.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <time.h>
#include <set>
using namespace std;
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;

int main() {
	testDequeAddInt();
	testDequePopInt();
	testDequeAddDArray();
	testDequePopDArray();
	testSetAddInt();
	testSetPopInt();
	testSetAddDArray();
	testSetPopDArray();
	testSetFindInt();
	testSetFindDArray();
}