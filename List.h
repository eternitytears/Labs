#pragma once
#include <iostream>
#include "dArray.h"
using namespace std;

template <typename T> struct
Elem
{
	T data;
	Elem<T> *next, *prev;
};

template <typename T> 
class List {
	int count;
	Elem<T>* head, * tail;
public:
	List() {
		head = tail = NULL;
		count = 0;
	}
	~List() {
		delAll();
	}
	void insert(int pos, T data) {
		try
		{
			if (pos < 1 || pos > count + 1) {
				throw exception("Wrong position");
			}
			Elem<T>* temp = new Elem<T>;
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
			Elem<T>* Ins = head;
			while (i < pos) {
				Ins = Ins->prev;
				i++;
			}
			Elem<T>* NextIns = Ins->next;
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
	void printAll() {
		try
		{
			if (count == 0) {
				throw exception("List is empty");
			}
			Elem<T>* temp = head;
			for (int i = 1; i < count; i++)
			{
				cout << temp->data << endl;
				temp = temp->prev;
			}

			cout << temp->data << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	void print(int pos) {
		Elem<T>* temp;
		temp = head;
		int i = 1;

		while (i < pos)
		{

			temp = temp->prev << endl;
			i++;
		}
		cout << temp->data << endl;
	}
	void delAll() {
		while (count != 0)
			del(1);
	}
	void del(int pos) {
		try
		{
			if (pos < 1 || pos > count + 1) {
				throw exception("Wrong position");
			}
			if (count == 1) {
				Elem<T>* del = head;
				delete del;
				count--;
				return;
			}
			if (pos == 1) {
				Elem<T>* del = head;
				Elem<T>* prevdel = del->prev;
				Elem<T>* nextdel = del->next;
				prevdel->next = nextdel;
				nextdel->prev = prevdel;
				head = prevdel;
				delete del;
				count--;
				return;
			}
			if (pos == count + 1) {
				Elem<T>* del = tail;
				Elem<T>* nextdel = del->next;
				Elem<T>* prevdel = del->prev;
				prevdel->next = nextdel;
				nextdel->prev = prevdel;
				head = nextdel;
				delete del;
				count--;
				return;
			}
			int i = 1;
			Elem<T>* del = head;
			while (i < pos) {
				del = del->prev;
				i++;
			}
			Elem<T>* prevdel = del->prev;
			Elem<T>* nextdel = del->next;
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
	bool empty() {
		if (count == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	T getData(int pos) {
		Elem<T>* temp;
		temp = head;
		int i = 1;

		while (i < pos)
		{

			temp = temp->prev;
			i++;
		}
		return temp->data;
	}
};