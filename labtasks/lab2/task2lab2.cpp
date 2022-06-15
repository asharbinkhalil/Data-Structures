// task2lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include"ArrayList.cpp"
#include"Contacts.cpp"
using namespace std;
int main()
{
	cout << " menu consisting of the following functionalities \nAdd a new contact\n";
		cout<<"Display all contacts\n	 Display specific contact\n	 Delete a contact\n	 Quit";
	ArrayList<Contacts> arrobj;
	cout << "\nEnter 2 contacts\n";
	for (int i = 0; i < 2; i++)
	{

		Contacts ct;
		ct.addContact();
		arrobj.add(ct);
	}

}



