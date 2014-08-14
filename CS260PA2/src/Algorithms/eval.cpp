/*
 * eval.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: dave
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prefix_eval(string prefix);
int prefix_eval(string prefix, int & pos);
int postfix_eval(string postfix);

const int CHAR_OFFSET = 48;

int main()
{
	cout << "========Postfix tests========" << endl;
	string exp = "789++";
	int correct = 24;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << postfix_eval(exp) << endl;
	cout << endl;

	exp = "23*11++";
	correct = 8;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << postfix_eval(exp) << endl;
	cout << endl;

	exp = "63/83-*";
	correct = 10;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << postfix_eval(exp) << endl;
	cout << endl;

	cout << "========Prefix tests========" << endl;
	exp = "/+86-43";
	correct = 14;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << prefix_eval(exp) << endl;
	cout << endl;

	exp = "++*4856";
	correct = 43;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << prefix_eval(exp) << endl;
	cout << endl;

	exp = "*-53-86";
	correct = 4;
	cout << "CORRECT: " << exp << " = " << correct << endl;
	cout << "RESULT: " << exp << " = " << prefix_eval(exp) << endl;
	cout << endl;


	return 0;
}

int prefix_eval(string prefix, int & pos)
{
	char c = prefix.at(pos);
	int res = 0;
	pos++;

	if (!isdigit(c))
	{
		int x = prefix_eval(prefix, pos);
		int y = prefix_eval(prefix, pos);

		switch(c)
		{
		case '+':
			res = x+y;
			break;
		case '-':
			res = x-y;
			break;
		case '/':
			res = x/y;
			break;
		case '*':
			res = x*y;
			break;

		}
	}
	else
		res = c - '0';

	return res;

}

int prefix_eval(string prefix) // Wrapper
{
	int pos = 0;
	return prefix_eval(prefix, pos);

}

int postfix_eval(string postfix)
{
	stack<int> s;
	int res = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		char c = postfix[i];
		if (!isdigit(c))
		{
			int y = s.top();
			s.pop();
			int x = (int)s.top();
			s.pop();

			switch (c)
			{
			case '+':
				res = x+y;
				break;
			case '-':
				res = x-y;
				break;
			case '/':
				res = x/y;
				break;
			case '*':
				res = x*y;
				break;
			}
			s.push(res);

		}
		else
			s.push(c - '0');
	}
	res = s.top();
	s.pop();

	return res;
}


