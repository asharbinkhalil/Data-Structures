#include<iostream>
using namespace std;
class  Contacts
{
public:

	string firstname;
	string lastname;
	string phno;
	string emailaddress;
	Contacts()
	{
		firstname = "";
		lastname = "";
		phno = "";
		emailaddress = "";
	}
	void addContact()
	{
		cout << "ENTER FIST NAME: ";
		cin >> firstname;
		cout << "ENTER SCND NAME: ";
		cin >> lastname;
	}

};