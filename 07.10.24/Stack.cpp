#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
	:data(nullptr), size(0)
{}

void Stack::Push(int value)
{
	int new_size = size + 1;
	int* new_data = new int[new_size] {};
	if (data != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			new_data[i] = data[i];
		}
	}
	new_data[new_size - 1] = value;
	delete[] data;
	data = new_data;
	size+=1;
}

int Stack::Top()
{
	return data[size - 1];
}

int Stack::Pop()
{
	int result = data[size - 1];
	int new_size = size - 1;
	int* new_data = new int[new_size] {};
	for (int i = 0; i < new_size; i++)
	{
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
	size -= 1;
	return result;
}

//int Stack::Print()
//{
//	if (data == nullptr)
//	{
//		return 0;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		cout << data[i] << ' ';
//	}
//	cout << endl;
//}

int Stack::length()
{
	return size;
}

Stack::~Stack()
{
	delete[] data;
}
