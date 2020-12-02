#include "List.h"
#include "dArray.h"
#include <iostream>
using namespace std;

List::List() {
	head = tail = NULL;
	count = 0;
}

List::~List() {
	delAll();
}

void List::insert(int pos, dArray data) {
	try
	{
		if (pos < 1 || pos > count + 1) {
			throw exception("Wrong position");
		}
		Elem* temp = new Elem;
		if (head == NULL || tail == NULL) {
			temp->next = temp;
			temp->prev = temp;
			temp->data = data;
			head = tail = temp;
			count++;
			return;
		}
		if (pos == 1 && head != NULL && tail != NULL) {
			temp->next = tail;
			temp->data = data;
			temp->prev = head;
			head->next = temp;
			tail->prev = temp;
			head = temp;
			count++;
			return;
		}
		if (pos == count + 1) {
			temp->next = tail;
			temp->data = data;
			temp->prev = head;
			tail->prev = temp;
			head->next = temp;
			tail = temp;
			count++;
			return;
		}
		int i = 1;
		Elem* Ins = head;
		while (i < pos) {
			Ins = Ins->prev;
			i++;
		}
		Elem* NextIns = Ins->next;
		NextIns->prev = temp;
		temp->next = NextIns;
		temp->prev = Ins;
		Ins->next = temp;
		temp->data = data;
		count++;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void List::printAll()
{
	try
	{
		if (count == 0) {
			throw exception("List is empty");
		}
		Elem* temp = head;
		for (int i = 1; i < count; i++)
		{
			cout << temp->data;
			temp = temp->prev;
		}

		cout << temp->data;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void List::print(int pos) {
	Elem* temp;
	temp = head;
	int i = 1;

	while (i < pos)
	{

		temp = temp->prev;
		i++;
	}
	cout << temp->data << endl;
}

void List::delAll()
{
	while (count != 0)
		del(1);
}

void List::del(int pos) {
	try
	{
		if (pos < 1 || pos > count + 1) {
			throw exception("Wrong position");
		}
		if (count == 1) {
			Elem* del = head;
			delete del;
			count--;
			return;
		}
		if (pos == 1) {
			Elem* del = head;
			Elem* prevdel = del->prev;
			Elem* nextdel = del->next;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = prevdel;
			delete del;
			count--;
			return;
		}
		if (pos == count + 1) {
			Elem* del = tail;
			Elem* nextdel = del->next;
			Elem* prevdel = del->prev;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = nextdel;
			delete del;
			count--;
			return;
		}
		int i = 1;
		Elem* del = head;
		while (i < pos) {
			del = del->prev;
			i++;
		}
		Elem* prevdel = del->prev;
		Elem* nextdel = del->next;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		delete del;
		count--;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

bool List::empty() {
	if (count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

dArray List::getData(int pos) {
		Elem* temp;
		temp = head;
		int i = 1;

		while (i < pos)
		{

			temp = temp->prev;
			i++;
		}
		return temp->data;
}