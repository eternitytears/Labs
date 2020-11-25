#include "dArray.h"
#include "dStack.h"
#include "dQueue.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool testpush() {
	dStack tmp;
	try
	{
		tmp.push(1);
		if (tmp.peek(0) != 1) {
			throw exception("Push test failed");
		}
		else {
			cout << "Push test successful" << endl;
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

bool testempty() {
	dStack tmp;
	try
	{
		if (tmp.empty() == 1) {
			tmp.push(1);
			if (tmp.empty() == 0) {
				cout << "Empty test successful" << endl;
			}
		}
		else {
			throw exception("Empty test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

}
bool teststackdel() {
	dStack one;
	one.push(1);
	one.push(2);
	try
	{
		int s = one.getSize();
		one.del();
		if (one.top() == 1 && s == one.getSize() + 1) {
			cout << "Delete test successful" << endl;
		}
		else {
			throw exception("Delete test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
bool testqueuedel() {
	dQueue one;
	one.push(1);
	one.push(2);
	try
	{
		int s = one.getSize();
		one.del();
		if (one.front() == 2 && one.getSize() + 1 == s) {
			cout << "Delete test successful" << endl;
		}
		else {
			throw exception("Delete test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
bool testfront() {
	dQueue one;
	one.push(1);
	one.push(2);
	try
	{
		if (one.front() == 1) {
			cout << "Front test successful" << endl;
		}
		else {
			throw exception("Front test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
bool testback() {
	dQueue one;
	one.push(1);
	one.push(2);
	try
	{
		if (one.back() == 2) {
			cout << "Back test successful" << endl;
		}
		else {
			throw exception("Back test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
bool testpeek() {
	dQueue one;
	one.push(1);
	one.push(2);
	one.push(3);
	try
	{
		if (one.peek(1) == 2) {
			cout << "Peek test successful" << endl;
		}
		else {
			throw exception("Peel test failed");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}