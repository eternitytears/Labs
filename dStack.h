	#pragma once
#include "dArray.h"
#include <iostream>
using namespace std;
class dStack: public dArray {
public:
	dStack();
	void push(int a);
	bool empty();
	void del();
	int top();
	int peek(int ind);
};