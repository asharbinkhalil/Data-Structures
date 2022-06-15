/*
Consider a scenario of Contacts Database, in which all information of user contacts will be
stored. In the given scenario you have to implement your database of contacts using the Generic
Arraylist you have created in Task 1.
Steps to Follow:
Step 1:
In first step you have to create Contact class with the following attributes;
● First Name
● Last Name
● Phone Number
● Email Address
Add mutator and accessor methods for all given attributes
Step 2:
You have to create a menu consisting of the following functionalities;
1. Add a new contact
2. Display all contacts
3. Display specific contact
4. Delete a contact
5. Quit*/
#include <iostream>
using namespace std;
template<class T2>
class ArrayList
{
public:
	T2* arr;
	int curr;
	int size;
	ArrayList()
	{
		arr = new T2[10];
		curr = 0;
		size = 10;
	}
	void add(T2 data)
	{
		if (isfull())
		{
			arr = increaseSize();
			arr[curr] = data;
		}
		arr[curr] = data;
		curr++;
	}
	T2* increaseSize()
	{
		T2* newarr;
		newarr = new T2[size + 10];
		for (int i = 0; i < size; i++)
		{
			newarr[i] = arr[i];
		}
		size = size + 10;
		return newarr;
	}
	bool isfull()
	{
		if (curr == size - 1)
			return true;
		else
			return false;
	}
	void display()
	{
		for (int i = 0; i < curr; i++)
		{
			cout << arr[i];
		}
	}
	void remove(T2 a)
	{
		for (int i = 0; i < curr; i++)
		{
			if (arr[i] == a)
			{
				for (int j = i; i < curr - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
			}
		}
	}
};





