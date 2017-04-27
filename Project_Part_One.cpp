//Created on: 4/24/2017
//last edited: 4/45/2017
//last compiled: 4/25/2017
//Created By Reilly Q. Curran and Amna Tariq

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int evaluate_postfix(string sExp);
int strToInt(string op);

int main()//tests the evaluate_postfix function with four test cases
{
	string s1 = "10 20 + 20 - ";
	string s2 = "30 2 10 * - ";
	string s3 = "30 20 10 - -";
	string s4 = "30 20 - 10 - ";
	string s5 = "15 3 / 10 * ";
	string s6 = "50 50 5 / + ";
	cout << s1 << " = " << evaluate_postfix(s1) << endl; // should give 10
	cout << s2 << " = " << evaluate_postfix(s2) << endl; // should give 10
	cout << s3 << " = " << evaluate_postfix(s3) << endl; // should give 20
	cout << s4 << " = " << evaluate_postfix(s4) << endl; // should give 0
	cout << s5 << " = " << evaluate_postfix(s5) << endl; // should give 50
	cout << s6 << " = " << evaluate_postfix(s6) << endl; // should give 60

	return 0;
}

int evaluate_postfix(string sExp)
{
	//********************************************************************
	stack<int> postFix; // holds the numbers while they are operated on
	string op[5]; //string fragments go here
	int val[3]; //stores the numbers once they have been converted
	string operators[2]; //holds the string fragments that are not converted, which are definately operators
	int valIndex = 0; //used while assigning numbers to the integer array
	int opIndex = 0; //used while assigning operators to the string array
	int a; //used to calculate result
	int b; //used to calculate result
	int result; //value that is pushed to stack once the previous values have been operated on and popped
	stringstream ss(sExp); //splits the origional string
	//********************************************************************
	
	//string fragments are assigned to their slots to be sorted in a moment
	ss >> op[0];
	ss >> op[1];
	ss >> op[2];
	ss >> op[3];
	ss >> op[4];

	for (int i = 0; i < 5; i++)
	{
		if (op[i] == "+" || op[i] == "-" || op[i] == "*" || op[i] == "/") // op[i] is an operator
		{
			operators[opIndex] = op[i];
			opIndex++;
		}

		else // op[i] is not an operator (op[i] is a number)
		{
			val[valIndex] = strToInt(op[i]);
			valIndex++;
		}
	}

	//if the first two numbers are operated on first
	if (op[2] == "+" || op[2] == "-" || op[2] == "*" || op[2] == "/") 
	{
		postFix.push(val[0]);
		postFix.push(val[1]);

		if (operators[0] == "+")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = a + b;
			postFix.push(result);
		}

		else if (operators[0] == "-")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = b - a;
			postFix.push(result);
		}

		else if (operators[0] == "*")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = a * b;
			postFix.push(result);
		}

		else if (operators[0] == "/")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = b / a;
			postFix.push(result);
		}

		if (operators[1] == "+")
		{
			result = val[2] + postFix.top();
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "-")
		{
			result =  postFix.top() - val[2];
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "*")
		{
			result = val[2] * postFix.top();
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "/")
		{
			result =  postFix.top() / val[2];
			postFix.pop();
			postFix.push(result);
		}

	}

	//if the latter two numbers are operated on first
	if (op[3] == "+" || op[3] == "-" || op[3] == "*" || op[3] == "/")
	{
		postFix.push(val[1]);
		postFix.push(val[2]);

		if (operators[0] == "+")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = a + b;
			postFix.push(result);
		}

		else if (operators[0] == "-")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = b - a;
			postFix.push(result);
		}

		else if (operators[0] == "*")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = a * b;
			postFix.push(result);
		}

		else if (operators[0] == "/")
		{
			a = postFix.top();
			postFix.pop();
			b = postFix.top();
			postFix.pop();
			result = b / a;
			postFix.push(result);
		}

		if (operators[1] == "+")
		{
			result = val[0] + postFix.top();
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "-")
		{
			result =  val[0] - postFix.top();
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "*")
		{
			result = val[0] * postFix.top();
			postFix.pop();
			postFix.push(result);
		}

		else if (operators[1] == "/")
		{
			result =  val[0] / postFix.top();
			postFix.pop();
			postFix.push(result);
		}

	}
	
	return postFix.top();
}

// converts strings to integers
int strToInt(string op) 
{
	int i = 0;
	stringstream number(op);
	number >> i;
	return i;
}