/*

								 ------------------- ASHAR KHALIL ----------------------
								 --------------------  20K-1724 ------------------------
								 ---------------- DATA STRUCTURES (A) ------------------
								 ------------------ Assignment-01 ----------------------

*/

#include <iostream>
using namespace std;
//class
class Polynomial
{ public:
	class term   //nested term class in polynomial
	{
	public:
		double coeff;
		double exp;
		term* next;
	};
	term* head;
	int size;
	Polynomial()
	{
		head = NULL;
		size = 0;
	}
	void Input()
	{
		Polynomial* p = new Polynomial;
		cout << "\t\t\t\tENTER NUMBER OF TERMS YOU WANT TO ENTERED:  ";
		cin >> p->size;
		p->head = new term;
		int count = 0;
		double firstexp = 0;

		double dexp = 0;
		while (p->size != 0)
		{
			double expp, ceff;
			cout << "\n\t\t\t\tENTER COEFFIECIENT OF TERM " << p->size << " : ";
			cin >> ceff;
			cout << "\t\t\t\tENTER EXPONENT OF TERM " << p->size << " : ";
			cin >> expp;

			if (count == 0)
			{
				add_to_end(ceff, expp);
				dexp = expp;
			}

			if (count > 0)
			{
				add_to_end(ceff, expp);
			}

			if (count > 0)
			{
				term* n = head;
				while (n->exp != expp)
				{
					n = n->next;
				}
				if (n->next != NULL)
				{
					n->coeff = n->coeff + ceff;
					delete_at_end();
				}
			}
			count++;
			p->size--;
		}
		sortpolynomial(); //sorting polynomial at last
	}
	void Output()
	{
		int count = 0;
		if (head == NULL)
			cout << "Empty";
		else
		{
			term* n = head;
			while (n != NULL)
			{
				if (n->coeff > 0 && count > 0)
					cout << "+";

				cout << n->coeff;


				if (n->exp == 1)
				{
					cout << "n";
				}
				else if (n->exp != 0)
				{

					cout << "n^" << n->exp;
				}
				n = n->next;
				count++;
			}
			cout << "\n";
		}

	}
	Polynomial* Add(Polynomial* p)
	{
		Polynomial temp; //making a temporray polynomila object and then we will return it after saving results of addition in it
		term* m = p->head;
		term* h = head;
		int c = 1;
		while (m != NULL || h != NULL)
		{
			if (m->exp == h->exp)
			{
				temp.add_to_end(m->coeff + h->coeff, m->exp);
				h = h->next;
				m = m->next;
			}
			else if (m->exp > h->exp)
			{
				temp.add_to_end(m->coeff, m->exp);
				m = m->next;
			}
			else
			{
				temp.add_to_end(h->coeff, m->exp);
				h = h->next;
			}
		}
		temp.sortpolynomial();   //new polynomial was made by add to end so we will sort it
		return &temp;
	}
	Polynomial* Multiply(Polynomial* p)
	{

		Polynomial temp;
		term* ptr1 = p->head, * ptr2 = head, * ptr3 = head;

		while (ptr1 != NULL) {
			while (ptr2 != NULL) {
				double coeff, expp;

				coeff = ptr1->coeff * ptr2->coeff;

				expp = ptr1->exp + ptr2->exp;

				temp.add_to_end(coeff, expp);//makeing new polynmial one by one

				ptr2 = ptr2->next; //moving ptr2 forward
			}

			ptr2 = ptr3; //making 2nd polynomial point again to start

			ptr1 = ptr1->next; //moving  ptr1 forward
		}
		addsameexp(&temp);   //new polynomial is not in simplified form so adding same exponenet
		temp.sortpolynomial();
		return &temp;
	}
	double evaluate(double m)
	{
		double sum = 0;
		if (head == NULL)
			cout << "Empty";
		else
		{
			term* n = head;
			while (n != NULL)
			{
				sum = sum + n->coeff * pow(m, n->exp);
				n = n->next;
			}
			return sum;
		}
	}
	Polynomial& operator*(Polynomial& p)
	{
		Polynomial* temp;
		temp = Multiply(&p);
		return *temp;
	}
	Polynomial& operator+(Polynomial& p)
	{
		Polynomial* temp;
		temp = Add(&p);
		return *temp;
	}

	void add_to_end(double cef, double ex)
	{
		term* temp = new term;
		temp->coeff = cef;
		temp->exp = ex;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			term* p;
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
	void sortpolynomial() {
		 term* current = head, * index = NULL;
		double temp;

		if (head == NULL) {
			return;
		}
		else {
			while (current != NULL) {
				index = current->next;

				while (index != NULL) {
					if (current->exp < index->exp) {
						temp = current->exp;
						current->exp = index->exp;
						index->exp = temp;
						double temp1 = current->coeff;
						current->coeff = index->coeff;
						index->coeff = temp1;
					}
					index = index->next;
				}
				current = current->next;
			}
		}
	}
	void delete_at_end()
	{
		term* p;
		p = head;
		term* c;
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
	void addsameexp(Polynomial* s)
	{
		term* p, * q, * dup;
		p = s->head;

		while (p != NULL && p->next != NULL) {
			q = p;
			while (q->next != NULL)
			{
				if (p->exp == q->next->exp)
				{
					p->coeff = p->coeff + q->next->coeff;
					dup = q->next;
					q->next = q->next->next;

					delete (dup);
				}
				else
					q = q->next;
			}
			p = p->next;
		}
	}
	


	void add_at_location(int loc, double cef, double ex)
	{
		if (loc == 1)
		{
			add_to_start(cef, ex);
		}
		else {
			term* temp = new term;
			temp->coeff = cef;
			temp->exp = ex;
			temp->next = NULL;
			term* p;
			p = head;
			term* c;
			c = head->next;
			for (int i = 1; i < loc - 1; i++)
			{
				p = c;
			}
			p->next = temp;
			temp->next = c;
		}
	}
	void add_before_value(double cef, double ex, double exx)
	{
		term* temp = new term;
		temp->coeff = cef;
		temp->exp = ex;
		temp->next = NULL;
		int count = 1;
		if (head == NULL)
			cout << "list is empty: ";
		else
		{
			term* p;
			p = head;
			term* c = head->next;
			while (p->next != NULL && p->exp != exx)
			{
				p = c;
				c = c->next;
				count++;
			}
			add_at_location(count, cef, ex);
		}
	}
	void add_to_start(double cef, double ex)
	{
		term* temp = new term;
		temp->coeff = cef;
		temp->exp = ex;
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
};
int main()
{
	cout << "------------------- ASHAR KHALIL----------------------\n";
	cout << "--------------------  20K - 1724 ---------------------\n";
	cout << "---------------- DATA STRUCTURES(A) ------------------\n";
	cout << "------------------ Assignment - 01 -------------------\n\n\n";
	cout << "                                         --------------------------------------\n";
	cout << "\t\t\t\t\t|         POLYNOMIAL CALCULATOR        |\n\t\t\t\t\t| 1: EVALUATE BY EXPONENT.             |\n";
	cout<<"\t\t\t\t\t| 2: ADDITION OF TWO POLYNOMIALS.      |\n\t\t\t\t\t| 3: MULTIPLICATION OF TWO POLYNOMIALS.|\n";
	cout << "                                         --------------------------------------\n\n\n\n";
	Polynomial obj;
	cout << "\t\t\t\tENTER POLYNOMIAL ONE: \n";
	obj.Input();
	cout << "\t\t\t\tYOU ENTERED: ";
	obj.Output();
	cout << "\n\t\t\t\tENTER AN INTEGER TO EVALUATE POLYNOMIAL ONE: ";
	int num;
	cin >> num;
	cout << "\n\t\t\t\tEVALUATION RESULT is: " << obj.evaluate(num);
	Polynomial obj1;
	cout << "\n\n\t\t\t\tENTER POLYNOMIAL TWO: \n";
	obj1.Input();
	cout << "\t\t\t\tYOU ENTERED: ";
	obj1.Output();
	cout << "\t\t\t\tMULTIPLICATION RESULT of polynmial one and two by FUNCTION :\n\t\t\t\t";
	Polynomial *obj4,obj3;
	obj4=obj.Multiply(&obj1);
	obj4->Output();
	cout << "\t\t\t\tMULTIPLICATION RESULT of polynmial one and two by OPERATOR OVERLOADING* :\n\t\t\t\t";
	obj3 = obj * obj1;
	obj3.Output();
	cout << "\t\t\t\tADDITION RESULT of polynmial one and two by FUNCTION :\n\t\t\t\t";
	obj4=obj.Add(&obj1);
	obj4->Output();
	cout << "\t\t\t\tADDITION RESULT of polynmial one and two by OPERATOR OVERLOADING + :\n\t\t\t\t";
	obj3 = obj + obj1;
	obj3.Output();
	return 0;
}
