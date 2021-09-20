/*
David Ankory 206780066
Workshop in C ++
Exercise 9 Question 2
The h and cpp file includes the names and the algoritems of the functions and their definition
*/
#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue
{
	//Forces the inheriting departments to implement these methods
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
	virtual int size() = 0;
};
