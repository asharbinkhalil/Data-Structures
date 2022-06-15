#pragma once
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
#include<iostream>
#include "Hospital.h"

using namespace std;
class Patient
{
public:
	string name;
	string type;
	int noOfDays;
};

