
#include <iostream>
using namespace std;
#include"NODE.cpp"
class doublylinkedlist
{
    doublynode *head;
    doublynode *tail;
public:

    doublylinkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void add_to_start(int val)
    {
        doublynode *temp=new doublynode;
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
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void add_to_end(int val)
    {
        doublynode* temp = new doublynode;
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

    }
    void deletehead()
    {
        doublynode* t=head;
        head=head->next;
        head->prev = NULL;
        t->next = NULL;
        delete t;
        t = NULL;
    }
    void deletetail()
    {
        doublynode* t=tail;
        tail = tail->prev;
        tail->next = NULL;
        t->prev = NULL;
        delete t;
        t = NULL;

    }
    void deletenode(doublynode* t)
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
    }
  
    void swapnodesbyindex(int f, int se)
    {
        int count = 1;
        doublynode* p = head;

        while (count!=f)
        {
            p = p->next;
            count++;
        }
        int count2 = 1;
        std::cout << count;
        doublynode* s = head;
        /*
        while (count2 != se)
        {
            s = s->next;
            count2++;
        }*/
        cout << "\nSWAPED values " << p->data << " " << s->data << " ||\n";
        doublynode* temp = p;
        p = s->prev->next;
        p->prev = s->prev;
        s = temp->prev->next;
        s->prev = temp->prev;
        cout << "\nSWAPED values " << p->data << " " << s->data << " ||\n";

    }
    void swapnodes(doublynode *&f, doublynode  *&s)
    {
        cout << "\nSWAPED values " << f->data << " " << s->data << " ||\n";
        doublynode* temp = f;
        f = s->prev->next;
        f->prev = s->prev;
        s = temp->prev->next;
        s->prev =temp->prev;
        cout << "\nSWAPED values " << f->data << " " << s->data << " ||\n";
        
    }
    void removedupplcate()
    {
        doublynode* p;
        p = head;
        doublynode* s = NULL;

        while (p != NULL)
        {

            s = p->next;
            while (s != NULL)
            {
                if (p->data == s->data)
                {
                    doublynode* temp = s->next;
                    deletenode(s);
                    s = temp;
                }
                else
                    
                s = s->next;
            }
            p = p->next;

        }
    }
    void deletebyval(int val)
    {
        doublynode* p = head, * c = head,*t=tail;
        if (p->data == val)
        {
            deletehead();
            return;
        }
        if (t->data == val)
        {
            deletetail();
            return;
        }
       
        while (c->next != NULL && c->data != val)
        {
            p = c;
            c = c->next;
        }
        p->next = c->next;
        c->next->prev = p;
        delete c;
        c = NULL;

    }
    void insert_at_pos(int l,int val)
    {
        doublynode* temp;
        temp = new doublynode;
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;
        doublynode* p=head, * c=head;
        for (int i = 1; i < l; i++)
        {
            p = c;
            c = c->next;
        }
        p->next=temp;
        temp->prev = p;
        temp->next = c;
        c->prev = temp;
    }
    void insert_after_val(int pval, int val)
    {
        doublynode* temp;
        temp = new doublynode;
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;
        doublynode* p = head, * c=head;
        while ( p!=NULL && p->data!=pval )
        {
            p = p->next;
        }
        c = p->next;
        p->next = temp;
        temp->prev = p;
        temp->next = c;
        c->prev = temp;
        temp = NULL;
        delete temp;
    }
    void display()
    {
        cout << "LINKED LIST FROM HEAD TO TAIL: ";
        doublynode* temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout << "\n";
        cout << "LINKED LIST FROM TAIL TO HEAD: ";
        doublynode* temp1;
        temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }
    void func()
    {
        doublynode* p,*s;
        p = head;
        s = p->next;
        int count = 0;
        while (count <3)
        {
            p = s;
            s = s->next;
            count++;
        }
        cout << "\nSWAP values " << p->data <<" " << s->data << " ||\n";
        swapnodes(p,s);

    }
    
};
