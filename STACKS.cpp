#include <iostream>
using namespace std;
#include<stack>
class astack
{
	int top;
	int arr[10];
public:
	astack()
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
			cout << "astack IS FULL";
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
	void insert_at_bottom(int x)
	{
		if (Isempty())
		{
			push(x);
		}
		else {
			int a = peek();
				pop();
			insert_at_bottom(x);
			push(a);
		}
	}
	void recurse()
	{
		if (top!=-1)
		{
			int a = peek();
			pop();
			recurse();
			insert_at_bottom(a);
		}
	}
};

class node
{
public:
	int data;
	node* next;
};
class lastack {
public:
	node* head;
public:
	lastack()
	{
		head = NULL;
	}
	void insert_after(int val, int nval)
	{
		node* temp = new node;
		temp->data = nval;
		temp->next = NULL;
		if (head == NULL)
			push(nval);
		else
		{
			node* p;
			p = head;
			node* c=NULL;
			while (p != NULL && p->data != val)
			{
				p = p->next;
			}
			c = p->next;
			p->next = temp;
			temp->next = c;
			temp = NULL;
			delete temp;
		}
	}
	void push(int val)
	{
	node* temp=new node;
	temp->data = val;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	temp = NULL;
	delete temp;
}
	void pop() {
		node* p;
		p = head;
		head = p->next;
		p = NULL;
		delete p;
	}
	int peek()
	{
		return head->data;
	}
	void display_reverse(node *h)
	{
		if (h != NULL)
		{
			display_reverse(h->next);
			cout << h->data;
		}
	}
	void display()
	{
		node* p = head;
	//	display_reverse(p);
		while (p!=NULL)
		
		{
			cout << "\n" << p->data;
			p = p->next;
		}
	}
	/*Implement a simple function that initializes empty astack. Then it takes multiple integers from a user as input and at each
time when you take input, push the integer into that particular astack in a such a way that astack should be always sorted in descending order from bottom to top
after each push function.

Note: Don’t violate rules of astack while applying sorting algorithm directly. You can only push pop from the top.
*/
	void func()
	{
		lastack ls,g;
		
		ls.push(1);
		int temp = 9;

		while (temp!=0)
		{
			cin >> temp;
			if(temp>=ls.peek())
			ls.push(temp);
			else
			{
					while(!ls.IsEmpty() && ls.peek()>temp )
				{
					g.push(ls.peek());
					ls.pop();
				}
					ls.push(temp);
			}
		}
		ls.display(); cout << "a";
		g.display();
		
	}
	bool IsEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void infi(string infix)
	{
		stack<char> op, pr;
		int i = 0, c = 0;
		for (i = 0; infix[i] != '\0'; i++)
		{
			if (infix[i] == '(' )
			{
				pr.push(infix[i]); 
			}
			if (infix[i] == '*' || infix[i] == '+' || infix[i] == '/' || infix[i] == '-')
			{if(pr.top()=='(' || pr.top() == '(')

				op.push(infix[i]);
				c = 1;
			}
			if (infix[i] == '0' || infix[i] == '1' || infix[i] == '2' || infix[i] == '3' || infix[i] == '4' || infix[i] == '5' || infix[i] == '6' || infix[i] == '7' || infix[i] == '8' || infix[i] == '9')
				op.push(infix[i]);

			if (c == 1)
			{
				while (pr.top() !='(')
				{
					pr.pop();
				}
			}
		}




		while (!op.empty())
		{ 
			cout << op.top();
			op.pop();
		}
		while (!pr.empty())
		{
			cout << pr.top();
			pr.pop();
		}

	}
};

int main()
{
	lastack s;
	//for (int i = 10; i > 0; i--)
	//	s.push(i);

	//s.display();
	////s.insert_after(5, 1);
	//s.func();
	//cout << "\n";
	//s.display();
//	s.infi("asharaaa");
	s.func();
	//s.infi("((3+4)*(5/6-7))");
	return 0;
}