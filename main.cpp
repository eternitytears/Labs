#include "dArray.h"
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;

bool testChange(int b[], int size, int newelement, int number) {
    dArray testArray(b, size);
	testArray.changeelement(newelement, number);
	if (testArray.getPoint()[number] == newelement){
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
	testArray.deleteelement(delelemnum);
	int sizea = testArray.getSize();
	if (sizep == sizea) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int b = 222;
	int numb = 5;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*for (int i = 0; i < 10; i++) {
		std::cin >> a[i];
	}*/
	dArray standartArray;
	dArray customArray(a, 10);
	std::cout << "Array created by default constructor: ";
	standartArray.getArray();
	std::cout << "\nArray created with given parameters: ";
	customArray.getArray();
	customArray.setElement(b);
	std::cout << "\nArray created with given parameters with new element: ";
	customArray.getArray();
	customArray.deleteelement(numb);
	std::cout << "\nArray created with given parameters witout deleted element: ";
	customArray.getArray();
	customArray.changeelement(333, 1);
	std::cout << "\nArray created with given parameters with changed element: ";
	customArray.getArray();
	customArray.searchelement(222);
	std::cout << "\nTest results(1 - successful test, 0 - failed test):";
	std::cout << "\nChange element test: ";
	std::cout << testChange(a, 10, 222, 5);
	std::cout << "\nAdd element test: ";
	std::cout << testAdd(a, 10, 222);
	std::cout << "\nDelete element test: ";
	std::cout << testDelete(a, 10, 2);
	return 0;
}	