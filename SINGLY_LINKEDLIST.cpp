#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int val)
	{
		data = val;
		next = NULL;
	}
	int getdata()
	{
		return data;
	}
	node* getnext()
	{
		return next;
	}
	void setdata(int val)
	{
		data = val;
	}
	void setnext(node* n)
	{
		next = n;

	}

};

class linkedlist
{
	node* head;
public:
	linkedlist()
	{
		head = NULL;
	}
	node* gethead(){
		return head;
	}
	void sethead(node* h)
	{
		head = h;
	}
	void add_to_start(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			temp->next = head;		//giving first node address to temp->next
			head = temp;			// moving head to temp (i mean at start)
		}
		temp = NULL;		//we have taken our objective fro temp now make it NULL first
		delete temp;	//then delete it . NULL and then delete so there isn;t any dangling pointer
	}
	void add_to_end(int val)
	{
		node* temp=new node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			node* p;
			p = head;
			while (p->next != NULL)   //traversing  pointer to head till NULL(last node)
			{
				p = p->next;
			}
			p->next = temp;      //adding temp(pointer to node) at last;
			temp->next = NULL;     //making last ->next NULL
		}
		temp = NULL;  //we have taken our objective fro temp now make it NULL first
		delete temp;  //then delete it . NULL and then delete so there isn;t any dangling pointer
	}
	void add_at_location(int loc, int val)
	{
		node* temp=new node;
		temp->next = NULL;
		temp->data = val;
		node* p;
		p = head;
		node* c;
		c = head->next;
		for (int i = 1; i < loc-2; i++)
		{
			p = c;
			c = c->next;
		}
		p->next = temp;
		temp->next = c;
	}
	void add_after_value(int val, int nval  )
	{
		node* temp = new node;
		temp->data = nval;
		temp->next = NULL;
		if (head == NULL)
			cout << "list is empty: ";
		else
		{
			node* p;
			p = head;
			node* c;
			while (p->next != NULL && p->data != val)
			{
				p = p->next;
			}
			c = p->next;
			temp->next = c;
			p->next = temp;
			temp = NULL;
			delete temp;

		}
	}

	void display()
	{
		
		if (head == NULL)
			cout << "Empty";
		else
		{
			node* n = head;
			cout << "LIST IS :    ";
			while (n!=NULL)
			{
				cout<< n->data << " ";
				n = n->next;
			}
			cout << "\n";
		}

	}
	void delete_list()
	{
		delete head;
	}
	void delete_at_start()
	{
		node *p;
		p = head;
		head = p->next;
		p = NULL;
		delete p;
	}
	void delete_at_end()
	{
		node* p;
		p = head;
		node* c;
		c = head;
		while (c->next != NULL)
		{
			p = c;
			c = c->next;
		}
		p->next = NULL;
		delete c;
		c = NULL;

	}
	void delete_a_value(int val)
	{
		if(head->data==val)
		{
			node* p;
			p = head;
			head = p->next;
			p = NULL;
			delete p;
		}
		else 
		{
			node* p = head, * c = head;
			while (c->next != NULL && c->data != val)
			{
				p = c;
				c = c->next;
			}
			p->next = c->next;
			delete c;
			c = NULL;
		}
	}
	void delete_a_location(int loc)
	{
		if (loc == 1)
		{
			node* p;
			p = head;
			head = p->next;
			p = NULL;
			delete p;
		}
		else
		{
			node* p;
			p = head;
			node* c;
			c = head;
			for (int i = 1; i < loc; i++)
			{
				p = c;
				c = c->next;
			}
			p->next = c->next;
			delete c;
			c = NULL;
		}
	}
};
int main()
{
	linkedlist obj;
	cout << "\n\n\n";
	for(int i=6; i>=1; i--)
		obj.add_to_start(i);
	cout << "INITIAL LIST HAS BEEN CREATED: \n";
	obj.display();
	

	cout << "ELEMENT IS ADDED AT LAST : \n";
	obj.add_to_end(9);
	obj.display();
	obj.add_at_location(2,2);
	cout << "ELEMENT 2 ADDED AT location 2  : \n";
	obj.display();
	cout << "ELEMENT 4 ADDED AFTER value 3  : \n";
	obj.add_after_value(3, 4);
	obj.display();
	cout << "ELEMENT IS DELETED AT START : \n";
	obj.delete_at_start();
	obj.display();
	cout << "ELEMENT IS DELETED AT LAST : \n";
	obj.delete_at_end();
	obj.display();
	cout << "ELEMENT 2 DELETED MANUALY : \n";
	obj.delete_a_value(2);
	obj.display();
	cout << "LOCATION 3 DELETED MANUALY : \n";
	obj.delete_a_location(3);
	obj.display();
	return 0;
}
