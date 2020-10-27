#include "dArray.h"
int dArray::statcurrentelement = 1;
int dArray::statindex = 0;
int dArray::statsize = 101;

bool testravno(dArray one, dArray two){
	one = two;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != two.getPoint()[i]) {
			return 0;
		}
	}
	return 1;
}

bool testplus(dArray one, dArray two) {
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

bool testminus(dArray one, int number) {
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

bool testplusplus(dArray one, int number) {
	dArray temp = one;
	one + number;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] + number) {
			return 0;
		}
	}
	return 1;
}

bool testinc(dArray one) {
	dArray temp = one;
	one++;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] + 1) {
			return 0;
		}
	}
	return 1;
}

bool testdec(dArray one) {
	dArray temp = one;
	one--;
	for (int i = 0; i < one.getSize(); i++) {
		if (one.getPoint()[i] != temp.getPoint()[i] - 1) {
			return 0;
		}
	}
	return 1;
}

void testindex(dArray one, int index) {
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	dArray temp(a, 10);
	try
	{
		one[index];
		std::cout << "Test [] successful" << std::endl;
	}
	catch (const std::exception & ex)
	{
		std::cout << "Test [] failed. Error: " << ex.what() << std::endl;
	}
}

int main() {
	int a[2] = { 3,2 };
	int b[8] = { 3,4,5,6,7,8,9,10 };
	int c[5] = { 1,2,3,4,5 };
	dArray one(a, 2);
	dArray two(b, 8);

	if (testravno(one, two) == 1) {
		std::cout << "Test = successful" << std::endl;
	}
	else {
		std::cout << "Test = failed" << std::endl;
	}
	
	if (testplus(one, two) == 1) {
		std::cout << "Test + successful" << std::endl;
	}
	else {
		std::cout << "Test + failed" << std::endl;
	}

	if (testminus(two, 6) == 1) {
		std::cout << "Test - successful" << std::endl;
	}
	else {
		std::cout << "Test - failed" << std::endl;
	}

	if (testplusplus(one, 6) == 1) {
		std::cout << "Test + successful" << std::endl;
	}
	else {
		std::cout << "Test + failed" << std::endl;
	}

	if (testinc(two) == 1) {
		std::cout << "Test ++ successful" << std::endl;
	}
	else {
		std::cout << "Test ++ failed" << std::endl;
	}

	if (testdec(two) == 1) {
		std::cout << "Test -- successful" << std::endl;
	}
	else {
		std::cout << "Test -- failed" << std::endl;
	}
	
	testindex(one, 10);
}