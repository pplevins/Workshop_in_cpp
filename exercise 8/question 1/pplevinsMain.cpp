/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 8 Question 1
The program inputs an infix string and claculates it using a template stackVector */

#include "StackVector.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//infix To Postfix function
string infixToPostfix(string infix)
{
	string str; //empty string
	StackVector<char> stk(infix.size()); //stack for chars
	char spacing = ' ';
	char ch = 0;

	int i = 0;
	while (i != infix.length())
	{
		char ch = infix[i];
		if (ch == '(') //4.1 - if it's Left opening bracket
			stk.push(ch);
		else if (ch == ')') //4.2 - if it's right closing bracket
		{
			//as long the top of the stack is not '('
			while (stk.top() != '(')
			{
				str += stk.pop(); //pop the values from the stack to the string
				str += ' ';
			}
			stk.pop(); //poping the left opening bracket
		}

		//4.3 - if it's a calculation operator
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			//poping fron the stack until we hit the bracket
			while ((!stk.isEmpty() && stk.top() != '(')) {
				str += stk.pop(); //adding the values to the string
				str += ' ';
			}
			stk.push(ch);
		}
		
		//4.4 - if it's a number
		else if (ch >= '0' && ch <= '9')
		{
			str += ch; //adding the number to the string

			//check if the next char in the string is a number
			while (i + 1 != infix.length() && infix[i + 1] >= '0' && infix[i + 1] <= '9')
				str += infix[++i];
			str += ' ';
		}
		i++; //4.5 - go to the next char
	}

	while (!stk.isEmpty()) //5 - until the stack is empty, adding all the chars to the sting
	{
		str += stk.pop();
		str += ' ';
	}
	return str;
}

//calculate the postfix
int calcPostfix(string postfix)
{
	StackVector<int> stk(postfix.size()); //empty stack for ints

	int i = 0;
	while (i < postfix.length())
	{
		char ch = postfix[i];
		if (ch >= '0' && ch <= '9')
		{
			string st; //string for the numbers
			st += ch;

			//if it's a number, adding it to the second string
			while (i + 1 != postfix.length() && postfix[i + 1] >= '0' && postfix[i + 1] <= '9')
			{
				st += postfix[i + 1];
				i++;
			}
			stk.push(stoi(st)); //pushing the numbers string to the stack
		}

		else if (ch != ' ')
		{
			int operand1 = stk.pop();
			int operand2 = stk.pop();

			if (ch == '+')
				stk.push(operand1 + operand2);
			else if (ch == '-')
				stk.push(operand2 - operand1);
			else if (ch == '*')
				stk.push(operand1 * operand2);
			else if (ch == '/')
				stk.push(operand2 / operand1);
		}
		i++;
	}
	return stk.pop(); //the result is waiting in the top of the stack
}

int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}

/*Run sample:

enter an infix expression as a string
(5+3)*((20/10)+(8-6))
in postfix form: 5 3 + 20 10 / 8 6 - + *
calculated value: 32
*/