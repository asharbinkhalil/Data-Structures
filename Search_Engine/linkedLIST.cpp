#include<iostream>
using namespace std;

class node {
public:
	string data;
	node* next;
};
class linkedlist
{
public:
	node* head;

	linkedlist()
	{
		head = NULL;
	}
	void add_to_start(string val)
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
	void display()
	{
		display_reverse(head);

	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void display_reverse(node* h)
	{
		static int ct = 1;
		if (h != NULL)
		{
			display_reverse(h->next);
			cout <<"\t\t\t\t\tLink: "<<ct << h->data << "\n";
			ct++;
		}
		if(h==NULL)
			ct = 1;
	}
	void deletefromstart()
	{
		node* p;
		p = head;
		head = p->next;
		p = NULL;
		delete p;

	}
	void delete_a_value(string val)
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
	void removeDuplicates()
	{
		node* ptr1, * ptr2, * dup;
		ptr1 = head;

		/* Pick elements one by one */
		while (ptr1 != NULL && ptr1->next != NULL) {
			ptr2 = ptr1;

			/* Compare the picked element with rest
			   of the elements */
			while (ptr2->next != NULL) {
				/* If duplicate then delete it */
				if (ptr1->data == ptr2->next->data) {
					/* sequence of steps is important here */
					dup = ptr2->next;
					ptr2->next = ptr2->next->next;
					delete (dup);
				}
				else /* This is tricky */
					ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	}


};