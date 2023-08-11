/*
	Name: Abubaker
	Roll Number: 21i1379
	Sec: H
	*/

//UnComment Code For Checking Each Question Thanks
//-------------------------------------Question 01 -----------------------------------------//
/*
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct Stack {
public:
	string myString;
	Stack* que;

	// Constructor
	Stack(string n)
	{
		this->myString = n;
		this->que = NULL;
	}
};
class Queue {
	Stack* top;

public:
	Queue();
	void push(string);
	bool isEmpty();
	string peek();
	void pop();

};
Queue::Queue() {
	top = NULL;
}
void Queue::push(string n)
	{

		Stack* temp = new Stack(n);
		if (!temp) {
			return;
		}
		temp->myString = n;
		temp->que = top;
		top = temp;
	}
bool Queue::isEmpty()
{
	return top == NULL;
}
string Queue::peek()
	{
		if (!isEmpty())
			return top->myString;
		return "\0";
	}
void Queue::pop()
	{
		Stack* temp;
		if (top == NULL) {
			return;
		}
		else {
			temp = top;
			top = top->que;
			delete temp;
		}
	}
//Expression Implementations
class myclass {

public:
	bool checkCharacter(char);
	int getPriority(char);
	bool isOperator(char);
	bool isOperator1(string);
	string infixToPrefix(string);
	string infixToPostfix(string);
	string PostfixToInfix(string);
	string PrefixToInfix(string);
	int getPriority1(string);

};
bool myclass::isOperator1(string character)
{

	bool flag1 = false;
	flag1 = (!isalpha(character[0]) && !isdigit(character[0]));
	return flag1;
}
bool myclass::isOperator(char character)
{
	
	bool flag1 = false;
	flag1 = (!isalpha(character) && !isdigit(character));
	return flag1;
}
int myclass::getPriority1(string character)
{

	if (character == "-" || character == "+")
		return 10;
	else if (((character != "-") && (character != "+")) && (character == "*" || character == "/"))
		return 20;
	else if ((((character != "-") && (character != "+")) && (character != "*" && character != "/")) && (character == "^") || (character == "$"))
		return 30;
	else
		return -1;
}
int myclass::getPriority(char character)
{

	if (character == '-' || character == '+')
		return 10;
	else if (((character != '-') && (character != '+')) && (character == '*' || character == '/'))
		return 20;
	else if ((((character != '-') && (character != '+')) && (character != '*' && character != '/')) && (character == '^') || (character == '$'))
		return 30;
	else
		return -1;
}
bool myclass::checkCharacter(char smallChar) {

	bool flag1 = isalpha(smallChar);
	bool flag2 = isdigit(smallChar);
	return (flag1 || flag2);
}
//Expression Convertors
string myclass::infixToPostfix(string infix)
{
	int n1 = 0;
	int n2 = 0;
	Queue ms;
	string output = "\0";
	myclass* pro = NULL;
	char smallChar = '\0';
	int i = 0;
	bool flag = false;
	string temp1 = "\0";
	string var = "\0";
	infix = "(" + infix + ")";
	while (infix[i] != '\0') {
		smallChar = '\0';
		smallChar = infix[i];
		flag = (pro->checkCharacter(smallChar));
		// If the scanned character is an
		// operand, add it to output.
		if (flag)
			output = output + smallChar;

		// If the scanned character is an
		// ‘)’, pop and output from the Queue
		// until an ‘(‘ is encountered.
		else if (smallChar == ')') {
			for (; ms.peek() != "(";) {
				output = output + ms.peek();
				ms.pop();
			}
			// Remove '(' from the Queue
			ms.pop();
		}
		// If the scanned character is an
		// ‘(‘, push it to the Queue.
		else if (smallChar == '(')
			ms.push("(");

		// Operator found
		else
		{

			if (pro->isOperator1(ms.peek()))
			{
				if (smallChar == '^')
				{
					n1 = pro->getPriority1(ms.peek());
					temp1 = smallChar;
					n2 = pro->getPriority1(temp1);
					while (n1 > n2)
					{
						output = output + ms.peek();
						ms.pop();
						n1 = pro->getPriority1(ms.peek());
						n2 = pro->getPriority1(temp1);
					}

				}
				else
				{
					temp1 = smallChar;
					n1 = pro->getPriority1(ms.peek());
					n2 = pro->getPriority1(temp1);
					while (n1 > n2)
					{
						output = output + ms.peek();
						ms.pop();
						n1 = pro->getPriority1(ms.peek());
						n2 = pro->getPriority1(temp1);
					}

				}

				// Push current Operator on Queue
				var = smallChar;
				ms.push(var);
			}
		}
		i++;
	}
	for (; !ms.isEmpty();)
		output = output + ms.peek();
	return output;

}
string myclass::infixToPrefix(string infix)
{

	myclass* obj = NULL;
	char mychar = '\0';
	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	int i = 0;
	while (i < infix.length()) {
		mychar = infix[i];

		if (mychar == '(') {
			infix[i] = ')';
		}
		if (mychar == ')') {
			infix[i] = '(';
		}

		i++;
	}
	string pre = obj->infixToPostfix(infix);
	// Reverse postfix
	reverse(pre.begin(), pre.end());

	return pre;
}
string myclass::PostfixToInfix(string postfix) {

	myclass* obj = NULL;
	Queue ss;
	int i = 0;
	char n = '\0';
	string myString = "\0";
	string operator1 = "\0";
	string operator2 = "\0";
	while (i < postfix.length()) {
		n = postfix[i];
		if (!obj->isOperator(n)) {
			string number(1, postfix[i]);
			ss.push(number);
		}

		else if (true) {

			operator1 = ss.peek();
			ss.pop();
			operator2 = ss.peek();
			myString = operator2;
			myString += n;
			myString += operator1;
			ss.pop();
			ss.push(myString);
		}
		i++;
	}
	return ss.peek();
}
string fun(Queue ss, string operator1, string operator2, string pre_exp, char myChar, myclass* obj, string temps, int i) {

	while (i >= 0) {
		myChar = pre_exp[i];
		// check if symbol is operator
		if (obj->isOperator(myChar)) {

			// pop two operands from Queue
			operator1 = ss.peek();
			ss.pop();
			operator2 = ss.peek();
			ss.pop();

			// concatenate the operands and operator
			temps += operator1;
			temps += myChar;
			temps += operator2;

			// Push string temp back to Queue

			ss.push(temps);
		}

		// if symbol is an operand
		else
			// push the operand to the Queue
			ss.push(string(1, myChar));
		i--;
	}
	
	cout << endl << endl;
	// Queue now contains the Infix expression
	return ss.peek();
}
string myclass::PrefixToInfix(string pre_exp) {

	Queue ss;
	myclass* obj = NULL;
	char myChar = '\0';
	string temps = "\0";
	// length of expression
	int i = pre_exp.size() - 1;
	// reading from right to left
	string operator1 = "\0";
	string operator2 = "\0";
	return fun(ss, operator1, operator2, pre_exp, myChar, obj, temps, i);
}
int main() {

	myclass* obj = NULL;
	//Pushing All Tags Into Stack
	Queue q;
	fstream file;

	string name = "123.txt";
	string output = "\0";
	file.open(name.c_str());
	string str = "\0";
	string subs;
	ofstream myfile("my_file.txt");


	while (getline(file, str)) {
		istringstream iss(str);
		string word;
		while (iss >> word) {
			if (word == "|post_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\post_exp|" && word != "|\\post_exp|.")
					newtemp += word;
				if (word == "|\\post_exp|.") {
					q.push(word);
					myfile << obj->infixToPostfix(newtemp) + ".";
				}
				else {
					myfile << obj->infixToPostfix(newtemp) + " ";
					q.push(word);
				}

			}
			else if (word == "|pre_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\pre_exp|" && word != "|\\pre_exp|.")
					newtemp += word;
				if (word == "|\\pre_exp|.") {
					myfile << obj->infixToPrefix(newtemp) + ".";
					q.push(word);
				}
				else {
					myfile << obj->infixToPrefix(newtemp) + " ";
					q.push(word);
				}

			}
			else if (word == "|\sol_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\sol_exp|" && word != "|\\sol_exp|.")
					newtemp += word;
				if (word == "|\\sol_exp|.") {
					q.push(word);
					myfile << obj->PostfixToInfix(newtemp) + ".";
				}
				else {
					q.push(word);
					myfile << obj->PostfixToInfix(newtemp) + " ";
				}

			}

			/*else if (word == "|src|") {
				string newtemp = "\0";
				while (iss >> word && word != "|\\src|" && word != "|\\src|.")

				if (word == "|\\src|.")
				else

			}
			*/
/*
			else if (word == "|pick|" || word == "|pick|." || word == ".|pick|" || word == "|tick|" || word == "|tick|." || word == ".|tick|" || word == "|hick|" || word == "|hick|." || word == ".|hick|" || word == "|\\pick|" || word == "|\\pick|." || word == ".|\\pick|" || word == "|\\tick|" || word == "|\\tick|." || word == ".|\\tick|" || word == "|\\hick|" || word == ".|\\hick|" || word == "|\\hick|.")
				q.push(word);
			else if (word == "|start|" || word == "|priorty|" || word == "|head|" || word == "|\\priorty|" || word == "|\\head|" || word == "|paragraph|" || word == "|\\paragraph|" || word == "|chk|" || word == "|\\chk|" || word == "|\\start|")
				q.push(word);
			else if ((word == "|tab|" || word == "|\\tab|") || word == "|tab||\\tab|") {
				myfile << "\t";
				q.push(word);
			}
			else {
				myfile << word + " ";
			}
		}
		myfile << "\n";
	}
	file.close();

}
*/

//-------------------------------------Question 02 -----------------------------------------//
/*
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct Stack {
public:
	string myString;
	Stack* front;

	// Constructor
	Stack(string n)
	{
		this->myString = n;
		this->front = NULL;
	}
};
class Queue {
	Stack* rear;


public:
	Queue();
	void push(string);
	bool isEmpty();
	string peek();
	string pop();

};
Queue::Queue() {

	rear = NULL;

}
void Queue::push(string n)
{
	Stack* temp = new Stack(n);
	if (!temp) {
		return;
	}


	temp->myString = n;
	temp->front = rear;
	rear = temp;
}
bool Queue::isEmpty()
{
	return rear == NULL;
}
string Queue::peek()
{
	if (!isEmpty())
		return rear->myString;
	else
		exit(1);
}
string Queue::pop()
{
	Stack* temp;
	string var = "\0";
	if (rear == NULL) {
		return "\0";
	}
	else {
		temp = rear;
		var = temp->myString;
		rear = rear->front;
		delete temp;
		return var;
	}
}
//Expression Implementations
class myclass {

public:
	bool checkCharacter(char);
	int getPriority(char);
	bool isOperator(char);
	bool isOperator1(string);
	string infixToPrefix(string);
	string infixToPostfix(string);
	string PostfixToInfix(string);
	string PrefixToInfix(string);
	int getPriority1(string);

};
bool myclass::isOperator1(string character)
{

	bool flag1 = false;
	flag1 = (!isalpha(character[0]) && !isdigit(character[0]));
	return flag1;
}
bool myclass::isOperator(char character)
{

	bool flag1 = false;
	flag1 = (!isalpha(character) && !isdigit(character));
	return flag1;
}
int myclass::getPriority1(string character)
{

	if (character == "-" || character == "+")
		return 10;
	else if (((character != "-") && (character != "+")) && (character == "*" || character == "/"))
		return 20;
	else if ((((character != "-") && (character != "+")) && (character != "*" && character != "/")) && (character == "^") || (character == "$"))
		return 30;
	else
		return -1;
}
int myclass::getPriority(char character)
{

	if (character == '-' || character == '+')
		return 10;
	else if (((character != '-') && (character != '+')) && (character == '*' || character == '/'))
		return 20;
	else if ((((character != '-') && (character != '+')) && (character != '*' && character != '/')) && (character == '^') || (character == '$'))
		return 30;
	else
		return -1;
}
bool myclass::checkCharacter(char smallChar) {

	bool flag1 = isalpha(smallChar);
	bool flag2 = isdigit(smallChar);
	return (flag1 || flag2);
}
//Expression Convertors
string myclass::infixToPostfix(string infix)
{
	int n1 = 0;
	int n2 = 0;
	Queue ms;
	string output = "\0";
	myclass* pro = NULL;
	char smallChar = '\0';
	int i = 0;
	bool flag = false;
	string temp1 = "\0";
	string var = "\0";
	infix = "(" + infix + ")";
	while (infix[i] != '\0') {
		smallChar = '\0';
		smallChar = infix[i];
		flag = (pro->checkCharacter(smallChar));
		// If the scanned character is an
		// operand, add it to output.
		if (flag)
			output = output + smallChar;

		else if (smallChar == ')') {
			while (ms.peek() != "(") {
				output = output + ms.peek();
				ms.pop();
			}
			// Remove '(' from the Queue
			ms.pop();
		}
		// If the scanned character is an
		// ‘(‘, push it to the Queue.
		else if (smallChar == '(')
			ms.push("(");

		// Operator found
		else
		{

			if (pro->isOperator1(ms.peek()))
			{
				if (smallChar == '^')
				{
					n1 = pro->getPriority1(ms.peek());
					temp1 = smallChar;
					n2 = pro->getPriority1(temp1);
					while (n1 > n2)
					{
						output = output + ms.peek();
						ms.pop();
						n1 = pro->getPriority1(ms.peek());
						n2 = pro->getPriority1(temp1);
					}

				}
				else
				{
					temp1 = smallChar;
					n1 = pro->getPriority1(ms.peek());
					n2 = pro->getPriority1(temp1);
					while (n1 > n2)
					{
						output = output + ms.peek();
						ms.pop();
						n1 = pro->getPriority1(ms.peek());
						n2 = pro->getPriority1(temp1);
					}

				}

				// Push current Operator on Queue
				var = smallChar;
				ms.push(var);
			}
		}
		i++;
	}
	for (; !ms.isEmpty();)
		output = output + ms.peek();
	return output;

}
string myclass::infixToPrefix(string infix)
{

	myclass* obj = NULL;
	char mychar = '\0';
	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	int i = 0;
	while (i < infix.length()) {
		mychar = infix[i];

		if (mychar == '(') {
			infix[i] = ')';
		}
		if (mychar == ')') {
			infix[i] = '(';
		}

		i++;
	}
	string pre = obj->infixToPostfix(infix);
	// Reverse postfix
	reverse(pre.begin(), pre.end());

	return pre;
}
string myclass::PostfixToInfix(string postfix) {

	myclass* obj = NULL;
	Queue ss;
	int i = 0;
	char n = '\0';
	string myString = "\0";
	string operator1 = "\0";
	string operator2 = "\0";
	while (i < postfix.length()) {
		n = postfix[i];
		if (!obj->isOperator(n)) {
			string number(1, postfix[i]);
			ss.push(number);
		}

		else if (true) {

			operator1 = ss.peek();
			ss.pop();
			operator2 = ss.peek();
			myString = operator2;
			myString += n;
			myString += operator1;
			ss.pop();
			ss.push(myString);
		}
		i++;
	}
	return ss.peek();
}
string fun(Queue ss, string operator1, string operator2, string pre_exp, char myChar, myclass* obj, string temps, int i) {

	while (i >= 0) {
		myChar = pre_exp[i];
		// check if symbol is operator
		if (obj->isOperator(myChar)) {

			// pop two operands from Queue
			operator1 = ss.peek();
			ss.pop();
			operator2 = ss.peek();
			ss.pop();

			// concatenate the operands and operator
			temps += operator1;
			temps += myChar;
			temps += operator2;

			// Push string temp back to Queue

			ss.push(temps);
		}

		// if symbol is an operand
		else
			// push the operand to the Queue
			ss.push(string(1, myChar));
		i--;
	}

	cout << endl << endl;
	// Queue now contains the Infix expression
	return ss.peek();
}
string myclass::PrefixToInfix(string pre_exp) {

	Queue ss;
	myclass* obj = NULL;
	char myChar = '\0';
	string temps = "\0";
	// length of expression
	int i = pre_exp.size() - 1;
	// reading from right to left
	string operator1 = "\0";
	string operator2 = "\0";
	return fun(ss, operator1, operator2, pre_exp, myChar, obj, temps, i);
}
bool validSyntax() {
	string name1 = "123.txt";
	fstream file1;
	file1.open(name1.c_str());
	string str1 = "\0";
	string subs;
	ofstream myfile("my_file.txt");

	string word;
	Queue q;

	// it is not hard code it's just all different type of Tags

	string check = "\0";
	string check1 = "\0";
	string check2 = "\0";
	string check3 = "\0";
	string check4 = "\0";
	string check5 = "\0";
	string check6 = "\0";
	string check7 = "\0";
	string check8 = "\0";
	string check9 = "\0";
	string check10 = "\0";
	string check11 = "\0";
	string check12 = "\0";
	bool result = false;
	bool result1 = false;
	bool result2 = false;
	bool result3 = false;
	bool result4 = false;
	bool result5 = false;
	bool result6 = false;
	bool result7 = false;
	bool result8 = false;
	bool result9 = false;
	bool result10 = false;
	bool result11 = false;
	bool result12 = false;

	while (getline(file1, str1)) {

		istringstream iss(str1);

		while (iss >> word) {

			if (word == "|post_exp|")
				q.push("|post_exp|");

			if ((word == "|\\post_exp|.") || word == ("|\\post_exp|"))
				check = q.pop();

			if (((word == "|\\post_exp|.") || ("|\\post_exp|")) && check == "|post_exp|")
				result = true;
			else
				result = false;

			if (word == "|pre_exp|")
				q.push("|pre_exp|");

			if ((word == "|\\pre_exp|.") || word == ("|\\pre_exp|"))
				check1 = q.pop();

			if ((word == "|\\pre_exp|.") || ("|\\pre_exp|") && check1 == "|pre_exp|") {
				result1 = true;
			}
			else
				result1 = false;

			if (word == "|sol_exp|")
				q.push("|sol_exp|");

			if (word == "|\\sol_exp|." || word == "|\\sol_exp|") {
				check2 = q.pop();
			}
			if ((word == "|\\sol_exp|.") || ("|\\sol_exp|") && check2 == "|sol_exp|") {
				result2 = true;
			}
			else
				result2 = false;

			if (word == "|src|")
				q.push("|src|");

			if (word == "|\\src|." || word == "|\\src|") {
				check3 = q.pop();
			}
			if ((word == "|\\src|.") || ("|\\src|") && check3 == "|src|") {
				result3 = true;
			}
			else
				result3 = false;

			if (word == "|paragraph|")
				q.push("|paragraph|");

			if (word == "|\\paragraph|." || word == "|\\paragraph|") {
				check4 = q.pop();
			}
			if ((word == "|\\paragraph|.") || ("|\\paragraph|") && check4 == "|paragraph|") {
				result4 = true;
			}
			else
				result4 = false;


			if (word == "|pick|")
				q.push("|pick|");

			if ((word == "|\\pick|") || word == ("|\\pick|."))
				check5 = q.pop();

			if (((word == "|\\pick|.") || ("|\\pick|")) && check5 == "|pick|")
				result5 = true;
			else
				result5 = false;

			if (word == "|tick|")
				q.push("|tick|");

			if ((word == "|\\tick|") || word == ("|\\tick|."))
				check6 = q.pop();

			if (((word == "|\\tick|.") || ("|\\tick|")) && check6 == "|tick|")
				result6 = true;
			else
				result6 = false;

			if (word == "|hick|")
				q.push("|hick|");

			if ((word == "|\\hick|") || word == ("|\\hick|."))
				check7 = q.pop();

			if (((word == "|\\hick|.") || ("|\\hick|")) && check6 == "|hick|")
				result7 = true;
			else
				result7 = false;


			if (word == "|start|")
				q.push("|start|");

			if ((word == "|\\start|") || word == ("|\\start|."))
				check8 = q.pop();

			if (((word == "|\\start|.") || ("|\\start|")) && check8 == "|start|")
				result8 = true;
			else
				result8 = false;

			if (word == "|priorty|")
				q.push("|priorty|");

			if ((word == "|\\priorty|") || word == ("|\\priorty|."))
				check9 = q.pop();

			if (((word == "|\\priorty|.") || ("|\\priorty|")) && check9 == "|priorty|")
				result9 = true;
			else
				result9 = false;

			if (word == "|head|")
				q.push("|head|");

			if ((word == "|\\head|") || word == ("|\\head|."))
				check10 = q.pop();

			if (((word == "|\\head|.") || ("|\\head|")) && check10 == "|head|")
				result10 = true;
			else
				result10 = false;

			if (word == "|tab|")
				q.push("|tab|");

			if ((word == "|\\tab|") || word == ("|\\tab|."))
				check11 = q.pop();

			if (((word == "|\\tab|.") || ("|\\tab|")) && check11 == "|tab|")
				result11 = true;
			else
				result11 = false;

			if (word == "|chk|")
				q.push("|chk|");

			if ((word == "|\\chk|") || word == ("|\\chk|."))
				check12 = q.pop();

			if (((word == "|\\chk|.") || ("|\\chk|")) && check12 == "|chk|")
				result12 = true;
			else
				result12 = false;


		}
	}
	bool mytemp = true;
	if (!((result) || (result1) || (result2) || (result3) || (result4) || (result5) || (result6) || (result7) || (result8) || (result9) || (result10) || (result11)) && (q.isEmpty())) {
		mytemp = false;
	}
	return mytemp;

}
void checkExpression() {
	myclass* obj = NULL;
	//Pushing All Tags Into Stack
	Queue q;
	fstream file;

	string name = "123.txt";
	string output = "\0";
	file.open(name.c_str());
	string str = "\0";
	string subs;
	ofstream myfile("my_file.txt");



	while (getline(file, str)) {

		istringstream iss(str);
		string word;

		while (iss >> word) {
			bool temp = false;
			int counter = 0;
			if (word == "|post_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\post_exp|" && word != "|\\post_exp|.")
					newtemp += word;
				cout << newtemp << endl;

				for (int i = 0; i < newtemp.length(); i++) {
					if (newtemp[i] == '(' || newtemp[i] == ')') {
						counter++;
						temp = true;
					}
				}
				if (temp) {
					if (!(counter % 2)) {
						if (word == "|\\post_exp|.") {
							q.push(word);
							myfile << obj->infixToPostfix(newtemp) + ".";
						}
						else {
							myfile << obj->infixToPostfix(newtemp) + " ";
							q.push(word);
						}
					}
					else
						myfile << "Expression InvaliD";
				}
				else {
					if (word == "|\\post_exp|.") {
						q.push(word);
						myfile << obj->infixToPostfix(newtemp) + ".";
					}
					else {
						myfile << obj->infixToPostfix(newtemp) + " ";
						q.push(word);
					}
				}
			}


			else if (word == "|pre_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\pre_exp|" && word != "|\\pre_exp|.")
					newtemp += word;
				cout << newtemp << endl;

				for (int i = 0; i < newtemp.length(); i++) {
					if (newtemp[i] == '(' || newtemp[i] == ')') {
						counter++;
						temp = true;
					}
				}
				if (temp) {
					if (!(counter % 2)) {
						if (word == "|\\pre_exp|.") {
							q.push(word);
							myfile << obj->infixToPrefix(newtemp) + ".";
						}
						else {
							myfile << obj->infixToPrefix(newtemp) + " ";
							q.push(word);
						}
					}
					else
						myfile << "Expression InvaliD";
				}
				else {
					if (word == "|\\pre_exp|.") {
						q.push(word);
						myfile << obj->infixToPrefix(newtemp) + ".";
					}
					else {
						myfile << obj->infixToPrefix(newtemp) + " ";
						q.push(word);
					}
				}
			}


			else if (word == "|sol_exp|") {
				q.push(word);
				string newtemp = "\0";
				while (iss >> word && word != "|\\sol_exp|" && word != "|\\sol_exp|.")
					newtemp += word;
				cout << newtemp << endl;

				for (int i = 0; i < newtemp.length(); i++) {
					if (newtemp[i] == '(' || newtemp[i] == ')') {
						counter++;
						temp = true;
					}
				}
				if (temp) {
					if (!(counter % 2)) {
						if (word == "|\\sol_exp|.") {
							q.push(word);
							myfile << obj->PostfixToInfix(newtemp) + ".";
						}
						else {
							myfile << obj->PostfixToInfix(newtemp) + " ";
							q.push(word);
						}
					}
					else
						myfile << "Expression InvaliD";
				}
				else {
					if (word == "|\\sol_exp|.") {
						q.push(word);
						myfile << obj->PostfixToInfix(newtemp) + ".";
					}
					else {
						myfile << obj->PostfixToInfix(newtemp) + " ";
						q.push(word);
					}
				}
			}

			else if (word == "|src|") {


			}
			else if (word == "|pick|" || word == "|pick|." || word == ".|pick|" || word == "|tick|" || word == "|tick|." || word == ".|tick|" || word == "|hick|" || word == "|hick|." || word == ".|hick|" || word == "|\\pick|" || word == "|\\pick|." || word == ".|\\pick|" || word == "|\\tick|" || word == "|\\tick|." || word == ".|\\tick|" || word == "|\\hick|" || word == ".|\\hick|" || word == "|\\hick|.")
				q.push(word);
			else if (word == "|start|" || word == "|priorty|" || word == "|head|" || word == "|\\priorty|" || word == "|\\head|" || word == "|paragraph|" || word == "|\\paragraph|" || word == "|chk|" || word == "|\\chk|" || word == "|\\start|")
				q.push(word);
			else if ((word == "|tab|" || word == "|\\tab|") || word == "|tab||\\tab|") {
				myfile << "\t";
				q.push(word);
			}

			else
				myfile << word + " ";

		}
		myfile << "\n";
	}
	file.close();

}
int main() {

	//Part1
	if (!validSyntax())
		cout << "InvaLid Syntax Of File";
	//Part2
	else
		checkExpression();


}*/

//-------------------------------------Question 03 -----------------------------------------//

#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class priorityQueue {

public:
	int data;
	int pri;
	int length;
	priorityQueue();
	void enqueue(int, int);
	int peek();
	void dequeue();

};
priorityQueue pr[4];
priorityQueue::priorityQueue() {

	data = 0;
	pri = 0;
	length = -1;

}
void priorityQueue::enqueue(int data, int pri)
{

	length++;
	pr[length].data = data;
	pr[length].pri = pri;
}
void check(int highestpri, int i, int& num) {
	highestpri = pr[i].pri;
	num = i;
}
int priorityQueue::peek()
{
	int i = 0;
	int highestpri = 0;
	int num = -1;
	while (i <= length) {

		if (highestpri == pr[i].pri) {
			if (num > -1) {
				if (pr[num].data < pr[i].data) {
					check(highestpri, i, num);
				}
			}
		}
		else if ( pr[i].pri > highestpri ) {
			highestpri = pr[i].pri;
			num = i;
		}
		i++;
	}
	return num;
}
void priorityQueue::dequeue()
{

	int i = peek();
	while (i < length) {
		pr[i] = pr[i + 1];
		i++;
	}
	length--;
}
void lRU() {
	int totalfiles = 7;

	int* arry = new int[4];
	for (int i = 0; i < 4; i++) {
		arry[i] = 0;
	}
	priorityQueue s;
	// Create a text string, which is used to output the text file
	int counter = 0;
	for (int i = 1; i < 5; i++) {
		string line = "\0";
		string temp = to_string(i);
		temp += ".txt";
		// Read from the text file
		bool flag = false;
		ifstream MyReadFile(temp);
		while (getline(MyReadFile, line))
		{
			if (flag)
				break;
			istringstream iss(line);
			string word;
			iss >> word;
			if (word == "|priorty|") {
				getline(MyReadFile, line);
				istringstream iss(line);
				iss >> word;
				int data = stoi(word);
				arry[counter] = data;
				break;
				flag = true;
			}
		}
		MyReadFile.close();
		counter++;
	}
	int totalFault = 0;
	int name = 1;
	for (int i = 0; i < 4; i++) {
		s.enqueue(name, arry[i]);
		name++;
		totalFault++;
	}
	int* arrs = new int[4];
	for (int i = 0; i < 4; i++) {
		int  num = s.peek();
		arrs[i] = pr[num].data;
		s.dequeue();


	}

	int* arr = new int[2];
	arr[0] = 0;
	arr[1] = 0;
	int count = 0;
	for (int i = 5; i < 7; i++) {

		string line = "\0";
		string temp = to_string(i);
		temp += ".txt";
		// Read from the text file
		bool flag = false;
		ifstream MyReadFile(temp);
		while (getline(MyReadFile, line))
		{
			if (flag)
				break;
			istringstream iss(line);
			string word;
			iss >> word;
			if (word == "|priorty|") {
				getline(MyReadFile, line);
				istringstream iss(line);
				iss >> word;
				int data = stoi(word);
				arr[count] = data;
				s.enqueue(i, data);
				break;
				flag = true;
			}
		}

		MyReadFile.close();
		count++;
	}
	int totalhit = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (arrs[i] == arr[j]) {
				totalhit++;
			}
		}
	}

	totalFault = totalfiles - totalhit;
	cout << "ToTal Faults : " << totalFault << endl;
	cout << "Total Hit : " << totalhit;
}
int main() {

	lRU();
}
