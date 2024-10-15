#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

bool pairMatches(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']');
}

void checkBrackets(const string& str) {
    Stack line;
    for (int i = 0; i < str.length(); i++) {
        char current = str[i];
        if (current == '(' || current == '{' || current == '[') {
            line.Push(i);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (line.length() == 0) {
                cout << "No opening bracket matches a closing one. Index of closing = " << i << endl;
                cout << "Your line before an error: " << str.substr(0, i + 1) << endl;
            }
            else {
                int openingIndex = line.Pop();
                if (!pairMatches(str[openingIndex], current)) {
                    cout << "Bracket types don't match. Index of closing = " << i << endl;
                    cout << "Your line before an error: " << str.substr(0, i + 1) << endl;
                }
            }
        }
    }

    if (line.length() != 0) {
        cout << "No closing bracket matches a opening one. Index of opening = " << line.Top() << endl;
        cout << "Your line before an error: " << str.substr(0, line.Top() + 1) << endl;
    }
    else {
        cout << "Your line is correct!" << endl;
    }
}

int main() {
    string userLine;
    cout << "Input a line, it should end with \'\;\': ";
    getline(cin, userLine);

    if (!userLine.empty() && userLine.back() == ';') {
        userLine.pop_back();
    }

    checkBrackets(userLine);
}