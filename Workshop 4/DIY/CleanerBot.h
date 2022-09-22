/*
*****************************************************************************
						  Workshop - #4 (P2)
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


#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H

namespace sdds
{
	class CleanerBot
	{
		//indicates the robot's current location
		char* m_location{};

		//holds the robot's remaining battery percentage
		double m_battery;

		//holds the robot's number of brushes
		int m_brush;

		//indicated whether the robot is active or not
		bool m_active;

	public:

		// constructor
		// default constructor
		CleanerBot();

		//  to initialize the robot information 
		CleanerBot(const char* location, double battery, int brush, bool active);

		// destructor
		//handle any potential memory leak.
		~CleanerBot();

		void set(const char* location, double battery, int brush, bool active);

		void setLocation(const char *location);

		void setActive(bool active);

		const char *getLocation() const; // no effect on location
		double getBattery() const;


		int getBrush() const;
		bool isActive() const;
		bool isValid() const;
		void display() const;

	};

	// stand alone function
	int report(CleanerBot* bot, short num_bots);
}
#endif // !SDDS_CLEANERBOT_H

