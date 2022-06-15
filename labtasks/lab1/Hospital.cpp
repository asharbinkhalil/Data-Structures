#include "Hospital.h"
#include "Patient.h"

Hospital::Hospital(Patient p, int a, int b, int c)
{
	this->pobj = p;
	dailyRate = a;
	meditationCharges = b;
	hospitalCharges = c;
}
void Hospital::getPatient()
{
	cin >> pobj.noOfDays;
}
