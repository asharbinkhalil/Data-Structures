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
public:
	node* head;

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
		for (int i = 1; i < loc-1; i++)
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
			node* c=head->next;
			while (p->next != NULL && p->data != val)
			{
				p = c;
				c = c->next;
			}
			c = p->next;
			temp->next = c;
			p->next = temp;
			temp = NULL;
			delete temp;
		}
	}
	void add_before_value(int val, int nval)
	{
		node* temp = new node;
		temp->data = nval;
		temp->next = NULL;
		int count = 1;
		if (head == NULL)
			cout << "list is empty: ";
		else
		{
			node* p;
			p = head;
			node* c = head->next;
			while (p->next != NULL && p->data != val)
			{
				p = c;
				c = c->next;
				count++;
			}
			cout << "||||" << count<<"||||";
			add_at_location(count, nval);
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
	void display_reverse(node * h)
	{
		if(h!=NULL)
		{
			display_reverse(h->next);
			cout << h->data;
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
	int listlength()
	{
		node* p = head;
		int c=0;
		while (p != NULL)
		{
			c++;
			p = p->next;
		}
		return c;
	}
	void removedupplcate()
	{
		node* p;
		p = head;
		node* s=NULL;
	
		while (p!=NULL)
		{
			s = p->next;
			while (s != NULL)
			{
				if (p->data == s->data)
					delete_a_value(p->data);
				s = s->next;
				
			}
			p = p->next;
		}
	}

	node* getnode(int i)
	{
		int c = 0;
		node* p = head;
		while (p!=NULL)
		{
			if (c == i)
			{
				return p;
			}
			c++;
			p = p->next;
		}
	}
	void reverse_list()
	{
		/*int c=0;
		c= listlength();
		for (int i = 0; i <= c / 2; i++)
		{
			int* a = &(getnode(i)->data);
			int* b = &(getnode(c - i)->data);
			cout << a << "\t" << b << endl;
			swap(a, b);
		}*/
		node* curr;
		curr = head;
		node* prev = NULL, * next = NULL;
		while (curr!=NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;


	}
	void swap(int*& a, int*& b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	void my_swap(node* node_1, node* node_2)
	{
		int temp = node_1->data;
		node_1->data = node_2->data;
		node_2->data = temp;
	}

	void bubble_sort()
	{
		int swapped;

		node* lPtr; // left pointer will always point to the start of the list
		node* rPrt = NULL; // right pointer will always point to the end of the list
		do
		{
			swapped = 0;
			lPtr = head;
			while (lPtr->next != rPrt)
			{
				if (lPtr->data > lPtr->next->data)
				{
					my_swap(lPtr, lPtr->next);
					swapped = 1;
				}
				lPtr = lPtr->next;
			}
			//as the largest element is at the end of the list, assign that to rPtr as there is no need to
			//check already sorted list
			rPrt = lPtr;

		} while (swapped);
	}
};
int main()
{
	linkedlist obj;
	cout << "\n\n\n";
	for(int i=0; i<6; i++)
		obj.add_to_start(i);

	cout << "ELEMENT IS ADDED AT LAST : \n";
	obj.add_to_end(9);
	obj.display();
	obj.add_at_location(2, 2);
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
	obj.display_reverse(obj.head);
	cout << "INITIAL LIST HAS BEEN CREATED: \n";
	obj.display();
	//for (int i = 0; i < 6; i++)
	//	obj.add_to_start(i);
	//cout << "\nADDED MORE ITEMS IN LIST: \n";
	//obj.display();
	//cout << "\nREMOVED DUPLICATES ITEMS IN LIST: \n";
	//obj.removedupplcate();
	//obj.display();
	cout << "\nSORTED THE LIST: \n";
	obj.bubble_sort();
	obj.display();
	cout << "\REVERSED THE LIST: \n";
	obj.reverse_list();
	obj.display();
	obj.display();




	return 0;
} 
