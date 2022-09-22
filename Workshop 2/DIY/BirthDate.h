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

#include <iostream>
#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

namespace sdds
{

	struct Employees
	{
		char* employee_name;
		int emp_year;
		int emp_date;
		int emp_month;
	};


	bool beginSearch(const char* filename);
	int noOfRecords();
	bool load (Employees& employ);
	bool read (char* employee_name);
	bool readMonth(int& emp_month);
	bool readYear(int& emp_year);
	bool readDate(int& emp_date);
	bool readBirthDate (int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();


}
#endif // SDDS_BIRTHDATE_H
