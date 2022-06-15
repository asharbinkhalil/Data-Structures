#include <iostream>
using namespace std;
class nodee
{
public:
	int data;
	nodee* next;
};
class queue
{
public:
	nodee* head;
	nodee* tail;
	int count;
	queue()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}
private:
	void enqueue(int data)
	{
		nodee* temp = new nodee;
		temp->data = data;
		temp->next = NULL;
		if (head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
			return;
		}

		temp->next = head;
		head = temp;
		
	}
	int peek()
	{
		return tail->data;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	void dequeue()
	{
		nodee* p= head;
		nodee* c = head;
		while (c->next != NULL)
		{
			p = c;
			c = c->next;
		}
		p->next = NULL;
		tail = p;
		delete c;
		c = NULL;
	}

public:
	void display()
	{
		nodee* p;
		p = head;
		while (p != NULL)
		{
			cout << p->data;
			p = p->next;
		}
		cout << "\n";
	}
	void push(int val)
	{
		enqueue(val);
		count++;
	}
	void pop()
	{
		queue a;
	
		count--;

		for(int i=0; i<count; i++)
		{
			int val = peek();
			dequeue();
			a.enqueue(val);
		}
		dequeue();
		for (int i = 0; i < count; i++)
		{
			int val = a.peek();
			a.dequeue();
			enqueue(val);
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
private:
	void push(int val)
	{
		node* temp = new node;
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
	void display_reverse(node* h)
	{
		if (h != NULL)
		{
			display_reverse(h->next);
			cout << h->data;
		}
	}
	
	bool IsEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
public:
	void display()
	{
		node* p = head;
		//	display_reverse(p);
		while (p != NULL)

		{
			cout << p->data;
			p = p->next;
		}
		cout << "\n";
	}
	void enqueue(int val)
	{
		push(val);
	}
	void dequeue()
	{
		cout << peek();
	}
};

int main()
{
	/*queue s;
	for (int i = 1; i < 6; i++)
	{
		s.push(i);
	}
	s.display();
	s.pop();
	s.display();*/

	lastack s;
	for (int i = 1; i < 6; i++)
	{
		s.enqueue(i);
	}
	s.display();
	s.dequeue();
	s.display();
	
}
