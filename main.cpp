#include "dArray.h"
#include "dStack.h"
#include "dQueue.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;

void testInsert() {
	try
	{
		List temp;
		dArray one;
		temp.insert(1, one);
		if (temp.getData(1) == one) {
			cout << "Insert test successful" << endl;
		}
		else {
			throw exception("Insert test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testDel() {
	try
	{
		List temp;
		dArray one(2), two(3), three(4);
		temp.insert(1, one);
		temp.insert(2, two);
		temp.insert(3, three);
		temp.del(2);
		if (temp.getData(2) == three) {
			cout << "Del test successful" << endl;
		}
		else {
			throw exception("Del test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void testDelAll() {
	try
	{
		List temp;
		dArray one(2), two(3), three(4);
		temp.insert(1, one);
		temp.insert(2, two);
		temp.insert(3, three);
		temp.delAll();
		if (temp.empty() == 1) {
			cout << "Del all test successful" << endl;
		}
		else {
			throw exception("Del all test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int main() {
	testDel();
	testDelAll();
	testInsert();
}