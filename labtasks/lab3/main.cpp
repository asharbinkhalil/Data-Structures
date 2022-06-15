// lab3t1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include"array.cpp"
using namespace std;
int main()
{
	twodarray obj(3,3);
	obj.getarray();
	obj.displayarray();
	int val1;
	val1=obj.checkmarkov();
	cout << val1;
	//obj.checkmagic();
	//cout << obj.checkmarkov();
	//int val;
	//val=obj.checksparse();
	//cout << val;

	return 0;
}
