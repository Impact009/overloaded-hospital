// Overloaded Hospital.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;

// Function prototypes.
double getTotalCharge(double, double);
double getTotalCharge(double, double, double);

int main()
{
	// Declare variables to store values for the numbers of floors, occupied rooms, unoccupied rooms, and the percentage of rooms that are occupied.
	char reply = 'n', patientType;
	double medicationCharges = 1000, hospitalServices = 3000, totalCharge = 4000;

	// Program information and example.
	cout << "This program computes and displays the charges for a patient's hospital stay.\n"
		 << "For out-patients, this program calculates the total cost of hospital medication\n"
		 << "charges and charges for hospital services (lab tests, etc.). For in-patients,\n"
		 << "this program calculates the cost of staying in the hospital in addition to out-\n"
		 << "patient costs.\n\n"

		 << "For example, if an out-patient's medication charges are $" << medicationCharges << ", and his or her\n"
		 << "charges for hospital services are $" << hospitalServices << ", then patient's total charge is $" << totalCharge << ".\n"
		 << "If an in-patient with those same costs stays for 5 days in the hospital at a\n"
		 << "rate of $2,000 per day, then the total charge for his or her stay is $14,000.\n\n"

	// Ask the user if he or she wants to enter information.
		 << "This program requires the patient's hospital medication charges and charges for\n"
		 << "hospital services. Calculations for in-patients will additionally require the\n"
		 << "number of days spent in the hospital and the daily rate.\n\n"
		 << "Would you like to enter this information? (y/n) ";
	cin  >> reply;

	if (reply == 'y' || reply == 'Y')
	{
		// Clear the screen for calculations.
		system("cls");

		// Ask if the patient was an in-patient or an out-patient.
		cout << "Was the patient an in-patient (i) or an out-patient (o)? (i/o) ";
		cin >> patientType;

		// Input validation.
		while (patientType != 'i' && patientType != 'I' && patientType != 'o' && patientType != 'O')
		{
			cout << "\nError! You did not enter in-patient (i) or out-patient (I).\n"
				 << "Was the patient an in-patient (i) or an out-patient (o)? (i/o) ";
			cin  >> patientType;
		}

		cout << "\nEnter the hospital medication charges: $";
		cin  >> medicationCharges;

		// Input validation.
		while (medicationCharges < 0)
		{
			cout << "\nError! The hospital medication charges cannot be negative!\n" 
				 << "Enter the correct medication charges: $";
			cin  >> medicationCharges;
		}

		cout << "\nEnter the charges for hospital services (lab tests, etc.): $";
		cin  >> hospitalServices;

		// Input validation.
		while (hospitalServices < 0)
		{
			cout << "\nError! The charges for hospital services cannot be negative!\n"
				 << "Enter the correct charges for hospital services (lab tests, etc.): $";
			cin  >> hospitalServices;
		}

		// Calculate out-patient totals.
		totalCharge = getTotalCharge(medicationCharges, hospitalServices);

		if (patientType == 'o' || patientType == 'O')
			cout << "\nThe total charge for the patient's hospital stay is $" << totalCharge << ".\n";

		else if (patientType == 'i' || patientType == 'I')
		{
			// Calculate in-patient totals.
			totalCharge = getTotalCharge(medicationCharges, hospitalServices, totalCharge);

			cout << "\nThe total charge for the patient's hospital stay is $" << totalCharge << ".\n";
		}
	}
	cout << "\nHave a great day!\n\n";
	return 0;
}

// Out-patient function.
double getTotalCharge(double medicationCharges, double hospitalServices)
{
	return medicationCharges + hospitalServices;
}

// In-patient function.
double getTotalCharge(double medicationCharges, double hospitalServices, double totalCharge)
{
	int daysSpent;
	double dailyRate;

	cout << "\nEnter the number of days spent in the hospital: ";
	cin  >> daysSpent;

	// Input validation.
	while (daysSpent < 1)
	{
		cout << "\nError! The number of days spent in the hospital for an outpatient cannot be\n"
			 << "less than 1.\n"
			 << "Enter the correct number of days spent in the hospital: ";
		cin  >> daysSpent;
	}

	cout << "\nEnter the daily rate: $";
	cin  >> dailyRate;

	// Input validation.
	while (dailyRate < 0)
	{
		cout << "\nError! The daily rate cannot be less than $0! Enter the correct daily rate: ";
		cin  >> dailyRate;
	}

	totalCharge = totalCharge + daysSpent * dailyRate;
	return totalCharge;
}