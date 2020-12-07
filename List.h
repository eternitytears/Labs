#pragma once
#include <iostream>
#include "dArray.h"
using namespace std;

struct Elem
{
	dArray data;
	Elem *next, *prev;
};

class List {
	int count;
	Elem *head, *tail;
public:
	List();
	~List();
	void insert(int pos, dArray data);
	void printAll();
	void print(int pos);
	void delAll();
	void del(int pos);
	bool empty();
	dArray getData(int pos);
};