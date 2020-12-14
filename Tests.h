#pragma once
#include "dArray.h"
bool testChange(int b[], int size, int newelement, int number);

bool testAdd(int b[], int size, int addedelement);

bool testDelete(int b[], int size, int delelemnum);

bool testRavno(dArray one, dArray two);

bool testPlus(dArray one, dArray two);

bool testMinus(dArray one, int number);

bool testPlusplus(dArray one, int number);

bool testInc(dArray one);

bool testDec(dArray one);

void testIndex(dArray one, int index);

bool testStream();
bool testTextfile(dArray one, dArray two);

bool testDatfile(dArray two);

bool testPush();

bool testEmpty();
bool testStackDel();
bool testQueueDel();
bool testFront();
bool testBack();
bool testPeek();

void testInsert();

void testDel();

void testDelAll();

void testDequeAddInt();

void testDequePopInt();

void testDequeAddDArray();

void testDequePopDArray();

void testSetAddInt();

void testSetPopInt();

void testSetAddDArray();

void testSetPopDArray();

void testSetFindInt();

void testSetFindDArray();