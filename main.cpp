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

void testTemplateDeleteAllForInt() {
	try
	{
		List<int> temp;
		temp.insert(1, 1);
		temp.insert(2, 2);
		temp.insert(3, 3);
		temp.delAll();
		if (temp.empty() == 1) {
			cout << "Del All test for int - OK" << endl;
		}
		else {
			throw exception("Del All test for int - failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateDelForInt() {
	try
	{
		List<int> temp;
		temp.insert(1, 1);
		temp.insert(2, 2);
		temp.insert(3, 3);
		temp.del(2);
		if (temp.getData(2) == 3) {
			cout << "Del test for int - OK" << endl;
		}
		else {
			throw exception("Del test for int failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateInsertForInt() {
	try
	{
		List<int> temp;
		temp.insert(1, 1);
		if (temp.getData(1) == 1) {
			cout << "Insert test for int - OK" << endl;
		}
		else {
			throw exception("Insert test for int failed");
		}

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateDeleteAllForChar() {
	try
	{
		List<char> temp;
		temp.insert(1, 'A');
		temp.insert(2, 'B');
		temp.insert(3, 'C');
		temp.delAll();
		if (temp.empty() == 1) {
			cout << "Del All test for char - OK" << endl;
		}
		else {
			throw exception("Del All test for char failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateDeleteForChar() {
	try
	{
		List<char> temp;
		temp.insert(1, 'A');
		temp.insert(2, 'B');
		temp.insert(3, 'C');
		temp.del(2);
		if (temp.getData(2) == 'C') {
			cout << "Del test for char - OK" << endl;
		}
		else {
			throw exception("Del test for char failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateInsertForChar() {
	try
	{
		List<char> temp;
		temp.insert(1, 'A');
		if (temp.getData(1) == 'A') {
			cout << "Insert test for char - OK" << endl;
		}
		else {
			throw exception("Insert test for char failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateDeleteAllForDArray() {
	try
	{
		List<dArray> temp;
		dArray one(1), two(2), three(3);
		temp.insert(1, one);
		temp.insert(2, two);
		temp.insert(3, three);
		temp.delAll();
		if (temp.empty() == 1) {
			cout << "Del All test for dArray - OK" << endl;
		}
		else {
			throw exception("Del All test for dArray failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateDeleteForDarray() {
	try
	{
		List<dArray> temp;
		dArray one(1), two(2), three(3);
		temp.insert(1, one);
		temp.insert(2, two);
		temp.insert(3, three);
		temp.del(2);
		if (temp.getData(2) == three) {
			cout << "Del test for dArray - OK" << endl;
		}
		else {
			throw exception("Del test for dArray failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testTemplateInsertForDarray() {
	try
	{
		List<dArray> temp;
		dArray one;
		temp.insert(1, one);
		if (temp.getData(1) == one) {
			cout << "Insert test for dArray - OK" << endl;
		}
		else {
			throw exception("Insert test for dArray failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int main() {
	testTemplateDeleteAllForChar();
	testTemplateDeleteForChar();
	testTemplateInsertForChar();

	testTemplateDeleteAllForDArray();
	testTemplateDeleteForDarray();
	testTemplateInsertForDarray();
	
	testTemplateDeleteAllForInt();
	testTemplateDelForInt();
	testTemplateInsertForInt();
}