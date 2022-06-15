
#include"doubly circular.cpp"
#include <iostream>
using namespace std;
int main()
{
	doublylinkedlist obj;
	for (int i = 1; i <=10; i++)
		obj.add_to_end(i);
	cout << "INITIAL LIST IS\n\n";
	obj.display();

cout << "\nIS soterd: " << obj.Issorted(obj.head) << "\n";
cout << "\nmiddle element is  :"<<obj.returnmiddle(obj.head)<<"\n";

	obj.reverse();

	obj.display();


	cout << "\nADDED 100  AT START and 200 at last by funtions: \n";
	obj.add_to_head(100);
	obj.add_to_end(200);
	obj.display();
	cout << "\nIS soterd: " << obj.Issorted(obj.head) << "\n";
	cout << "\nDELETED 100  AT START and 200 at last by funtions: \n";
	obj.deletehead();
	obj.deletetail();
	obj.display();


}