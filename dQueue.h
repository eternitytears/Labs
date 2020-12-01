#pragma once
#include "dArray.h"

class dQueue : public dArray {
public:
	dQueue();
	void push(int a);
	bool empty();
	void del();
	int front();
	int back();
	int peek(int ind);
};