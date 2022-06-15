// doubly circular.cpp : This file contains the 'main' function. Program execution begins and end


#include"Node.cpp"
#include <iostream>
using namespace std;
class doublylinkedlist
{
public:

    dnode* head;
    dnode* tail;


    doublylinkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void add_to_head(int d)
    {
        dnode* temp = new dnode;
        temp->data = d;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;

        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        tail->next = head;
        head->prev = tail;
    }
    void add_to_end(int val)
    {
        dnode* temp = new dnode;
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        tail->next = head;
        head->prev = tail;
    }
    void deletehead()
    {
        dnode* t = head;
        head = head->next;
        head->prev = NULL;
        t->next = NULL;
        delete t;
        t = NULL;
        tail->next = head;
        head->prev = tail;

    }
    void deletetail()
    {
        dnode* t = tail;
        tail = tail->prev;
        tail->next = NULL;
        t->prev = NULL;
        delete t;
        t = NULL;
        tail->next = head;
        head->prev = tail;
    }
    void deletenode(dnode* t)
    {

        if (t->prev == NULL)
        {
            deletehead();
            return;
        }
        if (t->next == NULL)
        {
            deletetail();
            return;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;

        tail->next = head;
        head->prev = tail;
    }
    void insert_at_pos(int l, int val)
    {
        if (l == 1)
        {
            add_to_head(val);
            return;
        }
        dnode* temp;
        temp = new dnode;
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;
        dnode* p = head, * c = head;
        for (int i = 1; i < l; i++)
        {
            p = c;
            c = c->next;
        }
        p->next = temp;
        temp->prev = p;
        temp->next = c;
        c->prev = temp;

        tail->next = head;
        head->prev = tail;

    }
    bool Issorted( dnode *h)
    {
        if (h == NULL)
            return true;

        for (dnode* t = h; t->next != tail; t = t->next)
            if (t->data > t->next->data)
                return false;
        return true;
    }
    void reverse() {
   
        dnode* p, * s;
        p = head;
        s = p->next;
        p->next= NULL;
        p->prev= s;
        while (s != head) {
            s->prev = s->next;
            s->next= p;
            p = s;
            s = s->prev;
        }
        tail = head;
        head = p;
        cout << "List Reversed" << endl;
    }
    void display()
    {

        cout << "SEEDHI: ";
        dnode* p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != tail);
        cout << p->data;

        cout << "\nULTI: ";
        dnode* s = tail;
        do
        {
            cout << s->data << " ";
            s = s->prev;
        } while (s != head);
        cout << s->data;
        cout << "\n";
    }
    int returnmiddle(dnode *h)
    {
        int c = length() / 2;
        for (int i = 0l;i < c-1; i++)
        {
            h = h->next;
        }
        return h->data;
    }
    int length()
    {
        int l = 1;
        dnode* t = head->next;
        while (t!=head)
        {
            l++;
            t = t->next;
        }
        return l;
    }

};
