#include <iostream>
using namespace std;
template <class X>
class stack
{
	X* arr;
	int topp;
	int capacity;

public:
	stack(); 
	void push(X);
	X pop();
	X top();
	int size();
	bool empty();
	bool isFull();
};
template <class X>
stack<X>::stack()
{
	arr = new X[100];
	capacity = 100;
	topp = -1;
}
template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		cout << "STACK FULL\n";
		return;
	}
	arr[++topp] = x;
}
template <class X>
X stack<X>::pop()
{
	if (empty())
	{
		cout << "STACK EMPTY";
		exit(EXIT_FAILURE);
	}
	return arr[topp--];
}
template <class X>
X stack<X>::top()
{
	if (!empty()) {
		return arr[topp];
	}
	else {
		exit(EXIT_FAILURE);
	}
}
template <class X>
int stack<X>::size() {
	return topp + 1;
}
template <class X>
bool stack<X>::empty() {
	return topp == -1;               
}
template <class X>
bool stack<X>::isFull() {
	return topp == capacity - 1;     
}

int calculate(int a, int b, char c)
{
	int result = 1;

	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return b - a;
	case '/':
		return b / a;
	case '*':
		return a * b;
	case '%':
		return b % a;
	case '^':
	{
		while (a != 0)
		{
				result *= b;
				--a;
		}
			return result;
	}
	default:
		break;
	}

	
}
int evaluate(const char* input)
{
	stack<int> s;
	int result = 0, resul = 0;
	for (int i = 0; i<strlen(input); i++)
	{
		char ch = input[i];
		if (ch >= '0' && ch <= '9')
			result = result * 10 + (input[i] - '0');
		else if (input[i] == ' ')
		{
			s.push(result);
			result = 0;
		}
		else {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			resul = calculate(a, b, ch);
			s.push(resul);
			i++;
		}
		
	}
	return s.top();

}
int stackPrec(char input)
{
	switch (input) {
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
	case '^':
		return 4;
	case '%':
		return 6;
	case '(':
		return 0;
	}
}
int newPrec(char input)
{
	switch (input) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '^':
	case '/':
		return 3;
	case '%':
		return 5;
	case '(':
		return 100;
	}
}
char* infi(char* input)
{
	//changing bracket into one bracket
		for (int i = 0; i < strlen(input); i++)
		{
			if (input[i] == '{' || input[i] == '[')
				input[i] = '(';

			if (input[i] == '}' || input[i] == ']')
				input[i] = ')';
		}
	
	stack<char> s, p;
	int i = 0, c = 0;
	for (i = 0; input[i] != '\0'; i++)
	{
		// if character an operand
				if (input[i] >= '0' && input[i] <= '9' || input[i] >= 65 && input[i] <= 90 || input[i] >= 97 && input[i] <= 122)
					p.push(input[i]);

				else if (input[i] == '(')
							s.push(input[i]);
				

						// if input is an operator, push
				else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '%' || input[i] == '/' || input[i] == '^')
				{
							if (p.top() != ' ')
								p.push(' ');
							//If  precedence is greater than precedence  of the character on top, push


							if (s.empty() || newPrec(input[i]) > stackPrec(s.top()))
							{
								s.push(input[i]);
							}
							else
							{
								//If its precedence  is lower or equal then pop from stack and push in temp stack while precedence of top
								//char is more than the precedence  of the input character.
								while (!s.empty() && newPrec(input[i]) < stackPrec(s.top())) 
								{
										p.push(s.top());
										p.push(' ');
										s.pop();
								}
								s.push(input[i]);

							}
				}

			// condition for opening bracket
			else if (input[i] == ')' )
			{
					
					while (s.top() != '(')
					{
						p.push(' ');
						p.push(s.top());
						s.pop();
							// if opening bracket not present
								if (s.empty())
								{
									cout << "\t\t\t\t\tINVLID EXPRESION\n";
									exit(1);
								}
					}
				// pop the opening bracket.
				s.pop();
			}
		}



	// pop the remaining operators
	while (!s.empty()) {
		if (s.top() == '(') {
			cout << "\n\t\t\t\t\tINVLID EXPRESION\n";
			exit(1);
		}
		p.push(' ');
		p.push(s.top());
		s.pop();
	}

	char* str = new char[p.size()];
	int x = p.size() - 1;
	str[p.size()] = '\0';
	while (!p.empty())
	{
		str[x] = p.top();
		p.pop();
		x--;
	}

	return str;
}
char* rv(char* s)
{
	int i = 0, len = 0, temp = 0;
	len = strlen(s);
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}

	return s;

}
void prefix(char* input)
{
	input = rv(input);
	
	for (int i = 0;i< strlen(input); i++)
	{
		if (input[i] == '(' )
			input[i] = '|';

		if (input[i] == ')')
			input[i] = '(';
	}
	for (int i = 0;  i < strlen(input); i++)
	{
		if (input[i] == '|')
			input[i] = ')';
	}
	char* s = infi(input);
	s = rv(s);
	cout << s;


}

static bool isOpeningBrace(char x)
{
	return x == '{' || x == '[' || x == '(';
}
static bool isClosingBrace(char x)
{
	return x == '}' || x == ']' || x == ')';
}

static bool isOperator(char x)
{
	return x == '+' || x == '-' || x == '*' || x == '/'|| x =='%' || x == '^';
}
static bool isOperand(char x)
{
	return x >='0' && x<='9';
}
static bool isValid(char x)
{
	return isOperator(x) || isOperand(x) || isOpeningBrace(x) || isClosingBrace(x); // or x == '!' or x == '<' or x == '>' or x == '.';
}
void validity(char* input)
{
	int x = strlen(input);
	//if first or last is operator thenn invalid
	if (isOperator(input[0]) || isOperator(input[x - 1]))
	{
		cout << "\t\t\t\t\tINVALID EXPRESSION\n";
		exit(1);
	}
	bool y = true;
	for (int i = 0; i < strlen(input); i++)
	{
		if (y == true)  //any char other then allowed 1-9,+,-,*,^,%,/ (){}[]    then invalid
			y=isValid(input[i]);
		else
		{
			cout << "\t\t\t\t\tINVALID EXPRESSION\n";
			exit(1);
		}

		if (isOpeningBrace(input[i]))  // if(2+(3)   etc
		{
			if (isOperator(input[i+1]))
			{
				cout << "\t\t\t\t\tINVALID EXPRESSION\n";
				exit(1);
			}
		}
		if (isOperator(input[i]))
		{
			if (isClosingBrace(input[i + 1]))   //if (2+)  etc
			{
				cout << "\t\t\t\t\tINVALID EXPRESSION\n";
				exit(1);
			}
		}
	}
	
	

	
}
int main()
{
	cout <<							"\t\t\t\t------------------- ASHAR KHALIL----------------------\n";
	cout <<							"\t\t\t\t--------------------  20K - 1724 ---------------------\n";
	cout <<							"\t\t\t\t---------------- DATA STRUCTURES(A) ------------------\n";
	cout <<							"\t\t\t\t------------------ Assignment - 02 -------------------\n\n\n";
	cout << "                                        /--------------------------------------/";
	cout <<								"\n\t\t\t\t\t|       INFIX TO POSTFIX / PREFIX      | ";
	cout <<								"\n\t\t\t\t\t| -> INFIX TO POSTFIX.                 |";
	cout <<							    "\n\t\t\t\t\t| -> INFIX TO PREFIX.                  |";
	cout <<						   		"\n\t\t\t\t\t| -> EVALUATION.                       |"; 
	cout <<								"\n\t\t\t\t\t| -> VALIDATION.                       |\n";
	cout << "                                        /--------------------------------------/\n\n\n\n";
	char arr[100] = "(2-3+4)*(5+66*7)"; 
	cout << "\t\t\t\t\t"<< "Enter INFIX  Expression : ";
	cin.getline(arr, 100);
	validity(arr);
	cout << "\t\t\t\t\t"<< "Entered Expression is :   " << arr << endl;
	cout << "\t\t\t\t\t"<<"Postfix expression is :   "<<infi(arr)<<endl;
	char* ev = infi(arr);
	cout << "\t\t\t\t\t" << "Prefix expression  is :   "; prefix(arr);
	cout << "\n\t\t\t\t\t"<< "Evaluation Answer  is :    " << evaluate(ev);


	cout << endl << endl;
	cout << "\t\t\t\t\t() Code by ASHAR KHALIL " << endl;
	cout << "\t\t\t\t\t() Not for Redistribution or Reuse." << endl << endl;
	cout<<"\t\t\t\t\t         -------END--------\n\n\n\n";
}