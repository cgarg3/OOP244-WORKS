/*
*****************************************************************************
						  Workshop - #3 (P2)
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
#include <iostream>
#include "Bar.h"
using namespace std;
namespace sdds
{
	void Bar::setEmpty()
	{
		// setting it to a safe empty state
		title[0] = '\0';
		valueOfBar = -1;
		fillCharacter = '\0';
	}

	void Bar::set(const char* heading, char fill, int value)
	{
		if (heading && heading[0] && fill && value > 0 && value <= 100)
		{
			strncpy(title, heading, 20);
			fillCharacter = fill;
			valueOfBar = value;
		}
		else
		{
			setEmpty();
		}
	}

	bool Bar::isEmpty() const
	{
		if (valueOfBar > 0 && valueOfBar < 100)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Bar::draw() const
	{
		{
			cout.width(20);
			cout.setf(ios::left);
			cout.fill('.');
			cout << title << "|";
			cout.unsetf(ios::left);
			cout.width(valueOfBar / 2);
			cout.fill(fillCharacter);
			cout << fillCharacter << endl;
		}
	}
}