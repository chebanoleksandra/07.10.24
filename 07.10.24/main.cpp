#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack obj1;
    obj1.Push(1);
    obj1.Push(2);
    obj1.Push(3);
    int size = obj1.length();
    for (int i = 0; i < size; i++)
    {
        cout << obj1.Pop() << " ";

    }
    if (obj1.length() == 0)
    {
        cout << endl << "Stack is empty" << endl;
    }


}