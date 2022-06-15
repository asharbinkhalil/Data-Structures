#include <iostream>
using namespace std;
class stack
{
	int top;
	int arr[10];
public:
	stack()
	{
		top = -1;
		arr[1] = NULL;
	}
	void push(int val)
	{
		top++;
		if (!Isfull())
			arr[top] = val;
		else
		{
			top--;
			cout << "STACK IS FULL";
		}
	}
	int pop()
	{
		if (Isempty())
		{
			cout << "ARRAY IS EMPTY";
			return 0;
		}
		
		else
		{
			int x = arr[top];
			arr[top] = NULL;
			--top;
			return x;
		}
	}
	int peek()
	{
		if (Isempty())
		{
			cout << "ARRAY IS EMPTY";
			return 0;
		}

		else
		{
			int x = arr[top];
			return x;
		}
	}
	void insertbottom(int val)
	{
		if (Isempty())
		{
			push(val);
		}

		else if(!Isfull())

		{
			++top;
			for (int i = 0; i <= top; i++)
			{
				arr[i +] = arr[i];
			}
			arr[0] = val;
		}
	}
	void display()
	{
		cout << "\n";
		if (top == -1)
		{
			cout << "ARRAY IS EMPTY";
			return;
		}
		for (int i = top; i >0; i--)
			cout << arr[i];
	}
	bool Isfull()
	{
		if (top == 10)
			return 1;
		else
			return 0;
	}
	bool Isempty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void recurse()
	{
		if (top!=-1)
		{
			int a = peek();
			pop();
			recurse();
			insertbottom(a);
		}
	}
};
int main()
{
	stack s;
	for (int i = 0; i < 10; i++)
		s.insertbottom(i);
	s.display();
	//s.recurse();
	//s.display();
	return 0;
}
