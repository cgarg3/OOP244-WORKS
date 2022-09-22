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
#include "BarChart.h"
using namespace std;
namespace sdds
{
	bool BarChart::isValid() const
	{
		
			bool result = true;

			int i = 0;
			int number = 0;
			if (m_title != NULL)
			{
				for (i = 0; i < trackOfNumber; i++)
				{
					if (b[i].isEmpty() == true)
					{
						number++;
					}
				}
			}
			if (number == trackOfNumber)
			{
				result = true;
			}
			return result;
	}

	void  BarChart::setEmpty()
	{
		holdFillCharacter = '\0';
		m_title[0] = '\0';
		b = nullptr;
		sizeOfBars = -1;
		trackOfNumber = -1;
	}

	void BarChart::init(const char* title, int noOfSampels, char fill)
	{
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		holdFillCharacter = fill;
		trackOfNumber = noOfSampels;
		sizeOfBars = 0;
		b = new Bar[trackOfNumber];
	}

	void BarChart::add(const char* bar_title, int value)
	{
		if (sizeOfBars < trackOfNumber)
		{
			b[sizeOfBars].set(bar_title, holdFillCharacter, value);
			sizeOfBars++;
		}
	}

	void BarChart::draw() const
	{
		int i;
		if (isValid() && (trackOfNumber == sizeOfBars))
		{
			cout << m_title << endl;
			cout.width(71);
			cout.fill('-');
			cout << '-' << endl;
			for (i = 0; i < trackOfNumber; i++)
			{
				b[i].draw();
			}
			cout.width(71);
			cout.fill('-');
			cout << '-' << endl;
		}
		else
		{
			cout << "Invalid Chart!" << endl;
		}
	}

	void BarChart::deallocate()
	{
		delete[] m_title;
		m_title = nullptr;

		delete[]  b;
		b = nullptr;
	}
}
