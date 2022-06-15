// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Write a class Patient that has following data members Name (string), type
e.g in – patient, outpatient (string), Number of days (int). Write another
class Hospital that has following data members patient Ob.(patient),
meditation-charges (int), daily rate (double) and hospital charges(int).
Make overloaded constructors in both classes.
First, the program should ask if the patient was admitted as an in-patient
or an out-patient. If the patient was an in-patient, the following data
should be entered:
1. The number of days spent in the hospital
2. The daily rate
3. Hospital medication charges
4. Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an out-
patient:
1. Charges for hospital services (lab tests, etc.)
2. Hospital medication charges
The program should use two overloaded functions in hospital class to
calculate the total charges. One of the functions should accept
arguments for the in-patient data (daily rate * hospital charges *
meditation rate *), while the other function accepts arguments for out-
patient information. Both functions should return the total charges. Write
your main function and test the functionality of your application.
*/


#include <iostream>
#include "Patient.h"
#include "Hospital.h"

using namespace std;

int main()
{
	string typee;
	Patient p1;
	Hospital h1;
	cout << "\nEnter PATIENT TYPE: ";
	cin >> p1.type;
	if (p1.type == "in")
	{
		
		cout << "\n Enter NO of DAYS: ";
		h1.getPatient();
		cout << "\n Enter Daily RATE: ";
		cin >> h1.dailyRate;
		cout << "\n Enter Meditation Charges: ";
		cin >> h1.meditationCharges;
		cout << "\n Enter Hospital Charges: ";
		cin >> h1.hospitalCharges;
	}
	if(p1.type == "out")
	{
		cout << "\n Enter Hospital Charges: ";
		cin >> h1.hospitalCharges;
		cout << "\n Enter Meditation Charges: ";
		cin >> h1.meditationCharges;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
