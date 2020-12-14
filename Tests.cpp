#include "dArray.h"
#include "dStack.h"
#include "dQueue.h"
#include "Tests.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <deque>
using namespace std;

bool testChange(int b[], int size, int newelement, int number) {
	dArray testArray(b, size);
	testArray.changeElement(newelement, number);
	if (testArray.getPoint()[number] == newelement) {
		return true;
	}
	else {
		return false;
	}

}

bool testAdd(int b[], int size, int addedelement) {
	dArray testArray(b, size);
	testArray.setElement(addedelement);
	int sizee = testArray.getSize();
	if (testArray.getPoint()[size] == addedelement) {
		return 1;
	}
	else {
		return 0;
	}
}

bool testDelete(int b[], int size, int delelemnum) {
	dArray testArray(b, size);
	int sizep = testArray.getSize();
	testArray.deleteElement(delelemnum);
	int sizea = testArray.getSize();
	if (sizep == sizea) {
		return 0;
	}
	else {
		return 1;
	}
}

bool testRavno(dArray one, dArray two) {
	one = two;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != two.getPoint()[i]) {
			return 0;
		}
	}
	return 1;
}

bool testPlus(dArray one, dArray two) {
	dArray temp = one + two;
	for (int i = 0; i < one.getSize(); i++) {
		if (temp.getPoint()[i] != one.getPoint()[i]) {
			return 0;
		}
	}
	for (int i = one.getSize(); i < one.getSize() + two.getSize(); i++) {
		if (temp.getPoint()[i] != two.getPoint()[i - one.getSize()]) {
			return 0;
		}
	}
	return 1;
}

bool testMinus(dArray one, int number) {
	dArray temp = one;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] == number) {
			one - number;
			if (one.getPoint()[i] == number || one.getSize() == temp.getSize()) {
				return 0;
			}
		}
	}
	return 1;
}

bool testPlusplus(dArray one, int number) {
	dArray temp = one;
	one + number;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] + number) {
			return 0;
		}
	}
	return 1;
}

bool testInc(dArray one) {
	dArray temp = one;
	one++;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] + 1) {
			return 0;
		}
	}
	return 1;
}

bool testDec(dArray one) {
	dArray temp = one;
	one--;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] - 1) {
			return 0;
		}
	}
	return 1;
}

void testIndex(dArray one, int index) {
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	dArray temp(a, 10);
	try
	{
		one[index];
		std::cout << "Test [] successful" << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Test [] failed. Error: " << ex.what() << std::endl;
	}
}

bool testStream() {
	int b[5] = { 1,2,3,4,5 };
	dArray temp(b, 5);
	stringstream stream("");
	stream << temp;
	if (stream.str() == "Size: 5\nArray: 1 2 3 4 5 \n") {
		return 1;
	}
	else {
		return 0;
	}
}

bool testTextfile(dArray one, dArray two) {
	dArray temp1 = one;
	dArray temp2 = two;
	ofstream f1("text.txt");
	if (!f1) {
		cout << "File open error " << endl;
		return 1;
	}
	f1 << two << one;
	f1.close();

	ifstream f("text.txt");
	if (!f) {
		cout << "File open error " << endl;
		return 1;
	}
	f >> two >> one;
	f.close();
	if (temp1 == one && temp2 == two) {
		return 1;
	}
	else {
		return 0;
	}
}

bool testDatfile(dArray two) {
	dArray temp2 = two;
	ofstream in("asdasd.dat", ios::binary | ios::app);
	if (!in) {
		cout << "File open error " << endl;
		return 1;
	}
	two.write(in);
	in.close();
	ifstream out("asdasd.dat", ios::binary | ios::app);
	if (!out) {
		cout << "File open error " << endl;
		return 1;
	}
	two.read(out);
	out.close();
	if (temp2 == two) {
		return 1;
	}
	else {
		return 0;
	}
}

bool testPush() {
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

bool testEmpty() {
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
bool testStackDel() {
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
bool testQueueDel() {
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
bool testFront() {
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
bool testBack() {
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
bool testPeek() {
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

void testDequeAddInt() {
	int a[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
	}

	deque<int> d;

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.push_front(a[i]);
	}

	timeFunk = clock() - timeFunk;
	cout << "Time of deque push for int: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testDequePopInt() {
	int a[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
	}

	deque<int> d;

	for (int i = 0; i < 1000; i++) {
		d.push_front(a[i]);
	}

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.pop_front();
	}
	timeFunk = clock() - timeFunk;
	cout << "Time of deque pop for int: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testDequeAddDArray() {
	dArray* a = new dArray[1000];
	dArray temp;
	for (int i = 0; i < 1000; i++) {
		temp.setElement(i);
		a[i] = temp;
	}

	deque<dArray> d;

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.push_front(a[i]);
	}

	timeFunk = clock() - timeFunk;
	cout << "Time of deque push for dArray: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testDequePopDArray() {
	dArray* a = new dArray[1000];
	dArray temp;
	for (int i = 0; i < 1000; i++) {
		temp.setElement(i);
		a[i] = temp;
	}

	deque<dArray> d;

	for (int i = 0; i < 1000; i++) {
		d.push_front(a[i]);
	}

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.pop_front();
	}
	timeFunk = clock() - timeFunk;
	cout << "Time of deque pop for Darray: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetAddInt() {
	int a[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
	}

	set<int> d;

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	timeFunk = clock() - timeFunk;
	cout << "Time of set push for int: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetPopInt() {
	int a[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
	}

	set<int> d;


	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	set<int>::const_iterator it;
	it = d.begin();

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.erase(it);
		it = d.begin();
	}
	timeFunk = clock() - timeFunk;
	cout << "Time of set pop for int: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetAddDArray() {
	dArray* a = new dArray[1000];
	dArray temp;
	for (int i = 0; i < 1000; i++) {
		temp.setElement(i);
		a[i] = temp;
	}

	set<dArray> d;

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	timeFunk = clock() - timeFunk;
	cout << "Time of set push for dArray: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetPopDArray() {
	dArray* a = new dArray[1000];
	dArray temp;
	for (int i = 0; i < 1000; i++) {
		temp.setElement(i);
		a[i] = temp;
	}

	set<dArray> d;


	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	set<dArray>::const_iterator it;
	it = d.begin();

	clock_t timeFunk = clock();

	for (int i = 0; i < 1000; i++) {
		d.erase(it);
		it = d.begin();
	}
	timeFunk = clock() - timeFunk;
	cout << "Time of set pop for Darray: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetFindInt() {
	int a[1000];
	for (int i = 0; i < 1000; i++) {
		a[i] = i;
	}

	set<int> d;


	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	clock_t timeFunk = clock();

	d.find(500);

	timeFunk = clock() - timeFunk;
	cout << "Time of set find for int: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}

void testSetFindDArray() {
	dArray* a = new dArray[1000];
	dArray temp;
	for (int i = 0; i < 1000; i++) {
		temp.setElement(i);
		a[i] = temp;
	}

	set<dArray> d;


	for (int i = 0; i < 1000; i++) {
		d.insert(a[i]);
	}

	clock_t timeFunk = clock();

	d.find(a[500]);

	timeFunk = clock() - timeFunk;
	cout << "Time of set find for Darray: " << (double)timeFunk / CLOCKS_PER_SEC << " seconds" << endl;
}