/*
*****************************************************************************
						  Workshop - #2 (P1)
Full Name  : CHIRAG GARG
Student ID#: 143180214
Email      : CGARG3@MYSENECA.CA
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include "BirthDate.h"

using namespace std;
namespace sdds
{
	int numberOfEmployees{};
	Employees* emp;
	int foundMonth;
	FILE* fptr;

	bool beginSearch(const char* filename) {
		bool ok = false;
		fptr = fopen(filename, "r");
		if (fptr)
		{
			cout << "Birthdate search program" << endl;
			return true;
		}
		else
		{
			cout << "Data file" << filename << "not found!" << endl;
			return ok;
		}
	}

	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}

	bool load(Employees& employ)
	{
		char name[128];

		// actual length of the employee name using the strlen functionand then add one to the length

		// read the and the grade into the corresponding variables of the Student Reference.

		if (read(name) && readMonth(employ.emp_month) && readDate(employ.emp_date) && readYear(employ.emp_year))
		{
			employ.employee_name = new char[strlen(name)+1];
			strcpy(employ.employee_name, name);
			return true;
		}
		else {
			return false;
		}
	}
	// read the employee name
	bool read(char* employee_name) {
		return fscanf(fptr, "%[^,],", employee_name) == 1;
	}

	// reads the birth month 
	bool readMonth(int& emp_month) {
		return fscanf(fptr, "%d/", &emp_month) == 1;
	}

	// reads the birth year
	bool readYear(int& emp_year) {
		return fscanf(fptr, "%d\n", &emp_year) == 1;
	}

	// reads the birth date
	bool readDate(int& emp_date) {
		return fscanf(fptr, "%d/", &emp_date) == 1;
	}

	bool readBirthDate(int month) {
		int numberOfMatch = 0;
		int i = 0;
		bool ok = false;
		int j = 0;
		int totalNumberOfEmployees = 0;
		foundMonth = month;
		if (month == 0) // if no record is matched , will return false
		{
			return ok;
		}
		else
		{
			numberOfEmployees = noOfRecords(); // this sets the value of employees to store their records
			// allocating  a dynamic array of employee to the number of the records in the file.

			emp = new Employees[numberOfEmployees];
			for (i = 0; i < numberOfEmployees; i++)
			{
				totalNumberOfEmployees += load(emp[i]);
			}
			// will set the totalNumberOfEmployees to the numberOfEmployee
			numberOfEmployees = totalNumberOfEmployees;

			for (j = 0; j < numberOfEmployees; j++)
			{
				// this will scan and read the birth recoord
				fscanf(fptr, "%d/", &month);

				if (emp[j].emp_month == month)
				{
				// if input entered matches the file record, increement in the numberOfMatch
				numberOfMatch++;
				}
			}
			// time to display the number of records found 
			cout << numberOfMatch << " birthdates found:" << endl;

			ok = true;
		}
		return ok;
	}
	void sort() {
		int i = 0, j = 0;
		Employees m_year;
		for (i = numberOfEmployees - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (emp[j].emp_year > emp[j + 1].emp_year)
				{
					m_year = emp[j];
					emp[j] = emp[j + 1];
					emp[j + 1] = m_year;
				}
			}
		}
	}

	void displayBirthdays() {
		int i = 0;
		int j = 0;

		for (i = 0; i < numberOfEmployees; i++)
		{
			if (emp[i].emp_month == foundMonth)
			{
				cout << ++j << ") "; // to display the serial list of the record found
				cout << emp[i].employee_name << ":" << endl; // as per the given sample:  2) Savana Morgan 1942-11-28
				cout << emp[i].emp_year << "-" << emp[i].emp_month << "-" << emp[i].emp_date << endl;
				cout << "===================================" << endl;
			}
		}
	}

	void deallocate()
	{
		int i = 0;
		for (i = 0; i < numberOfEmployees; i++)
		{
			delete[] emp[i].employee_name; // deallocate the whole memory
			emp[i].employee_name = nullptr;
		}
		delete[] emp; // deallocate the whole student array
		emp = nullptr;
	}

	void endSearch() {
		if (fptr)
		{
			fclose(fptr);
		}
		cout << "Birthdate Search Program Closed." << endl;
	}

}
