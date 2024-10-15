#pragma once
class Stack
{
	int* data;
	int size;
public:
	Stack();
	void Push(int value);
	int Top();
	int Pop();
	/*int Print();*/
	int length();
	~Stack();
};

