#include <iostream>		
using namespace std;
#define size 10
//class aqueue
//{
//    int *arr;
//    int front;
//    int rear;
//public:
//    aqueue() {
//        arr = new int[size];
//        front = -1;
//        rear = -1;
//    }
//    void enqueue(int val)
//    {
//       
//        rear++;
//        if (rear >=size)
//        {
//            cout << "Full Queue";
//            rear = size - 1;
//            return;
//        }
//        if (rear == front == -1)
//        {
//            cout << "Empty Queue";
//          
//            return;
//        }
//        else
//        {
//            arr[rear] = val;
//            if (front == -1)
//            {
//                front=0;
//            }
//        }
//        ;
//    }
//    int dequeue()
//    {
//        if (!Isfull() && !IsEmpty())
//        {
//            front++;
//            int v = arr[front];
//            return v;
//        }
//    }
//    int peek()
//    {
//        return arr[front];
//    }
//    bool Isfull()
//    {
//        if (rear>=size)
//        {
//            cout << "\nFull\n";
//            return true;
//        }
//        else
//            return false;
//    }
//    bool IsEmpty()
//    {
//        if (front ==-1 && rear==-1)
//        {
//            cout << "\nEmpty\n";
//            return true;
//        }
//        else
//            return false;
//    }
//
//    void display()
//    {
//        cout << "\n";
//        for (int i = front; i < rear; i++)
//        {
//            cout << arr[i] << " ";
//        }
//    }
//};

class Task
{
public:
	int id;
	int execT;
	Task *next;
};
class queue
{
public:
	Task *head;
	Task *tail;
public:
	queue()
	{
		head = NULL;
		tail = NULL;
	}
	void enqueue(Task* p)
	{
		Task* temp = new Task;
		temp->id = p->id;
		temp->execT = p->execT;
		temp->next = NULL;
		if (head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
			return;
		}

		temp->next = head;
		head = temp;
		temp = NULL;
		delete temp;
	}
	Task* peek()
	{
		return head;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}

	Task*  edequeue()
	{
		Task* const t = tail;
		Task* p = head;
		Task* s=NULL;
		while (p->next!=NULL)
		{	
			s = p;
			p = p->next;
		}
		s->next = NULL;
		delete p;
		tail = s;
		return t;	
	}
	void dequeue(Task *t)
	{
		Task* temp;
		if (head->execT=t->execT)
		{
			edequeue();
		}
		else
		{
			Task* current=head;
			while (current->next != NULL)
			{
				//if yes, we need to delete the current->next node
				if (current->next->execT == t->execT)
				{
					temp = current->next;
					//node will be disconnected from the linked list.
					current->next = current->next->next;
					free(temp);
					break;
				}
				//Otherwise, move the current node and proceed
				else
					current = current->next;
			}
		}
	}
	void display()
	{
		Task* p;
		p = head;
		cout << "\n";
		while (p != NULL)
		{
			cout <<"\nID is :" << p->id << "\nExecution time: "<<p->execT<<"\n";
			p = p->next;
		}
	}
	void roundRobin()
	{
		queue q1;
		int qt;
		cout << "Enter Quantum\n";
		cin >> qt;

		int d1;
		cout << "how many tasks number\n";
		cin >> d1;
		Task* p = new Task;
		for (int i = 0; i < d1; i++)
		{
			int et;
			cout << "Enter execution time\n";
			cin >> et;

			p->id = i + 1;
			p->execT = et;

			q1.enqueue(p);
		}
		Task* t = q1.head;
		
		while (t!=NULL)
		{
			t->execT = t->execT - qt;
			if (t->execT > 0)
			{
				cout << "\nIddd is : " << t->id << "Remainint Time is : " << t->execT;
				q1.enqueue(t);
				q1.dequeue(t);
				
			}
			else
			{
				cout << "\nId is : " << t->id << " Time is : " << t->execT;
				q1.dequeue(t);
			}

		}

	}


};
int main()
{
	//queue a;
	//for (int i = 0; i < 10; i++)
	//	a.enqueue(i, i);
	//a.display();
	//a.dequeue();
	//a.dequeue();
	//a.dequeue();
	//a.display();

	queue a;
	a.roundRobin();



}

