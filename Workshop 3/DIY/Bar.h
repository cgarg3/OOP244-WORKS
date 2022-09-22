
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

#ifndef  SDDS_BAR_H
#define  SDDS_BAR_H
namespace sdds
{
	const int MAX_TITLE = 20;
	class Bar
	{
		char title [MAX_TITLE + 1];
		char fillCharacter;
		int valueOfBar = -1;
	
	public:
		void setEmpty();
		void set(const char *heading , char fill, int value);
		bool isEmpty() const;
		void draw() const;

	};

}
#endif // ! SDDS_BAR_H
