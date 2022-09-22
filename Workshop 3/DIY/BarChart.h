
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

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#include "Bar.h"

namespace sdds
{
	class BarChart
	{
		char* m_title;
		Bar* b;
		char holdFillCharacter;

		int sizeOfBars = 0;
		int trackOfNumber = 0;

		bool isValid () const; // to check if bars are in valid state
		void setEmpty();
		public:
		void init(const char* title, int noOfSampels, char fill); // initilaises the chart
		void add(const char* bar_title, int value); // set the next available bar in a dynamic array 
		void draw()const; // 
		void deallocate(); // deallocated the memory 
	};
}
#endif // !SDDS_BARCHART_H
