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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CleanerBot.h"

using namespace std;
namespace sdds
{
	CleanerBot::CleanerBot()
	{
		// default values
		m_location = nullptr;		
		m_battery = 0.0;
		m_active = false;
		m_brush = 0;
		
	}


	CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active)
	{
		delete[] m_location;
		m_location = nullptr;

		m_location = new char[strlen(location + 1)];
		strcpy(m_location, location);

		m_battery = battery;
		m_brush = brush;
		m_active = active;
	}


	CleanerBot::~CleanerBot()
	{
		delete[] m_location;
		m_location = nullptr;
	}


	void CleanerBot::set(const char* location, double battery, int brush, bool active)
	{
		delete[] m_location;
		m_location = nullptr;

		m_location = new char[strlen(location + 1)];
		strcpy(m_location, location);

		m_battery = battery;
		m_brush = brush;
		m_active = active;
	}

	void CleanerBot::setLocation(const char* location)
	{
		delete[] m_location;
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
	}

	void CleanerBot::setActive(bool active)
	{
		m_active = active;
	}

	const char* CleanerBot::getLocation() const
	{
		return m_location;
	}

	double CleanerBot::getBattery() const
	{
		return m_battery;
	}

	int CleanerBot::getBrush() const
	{
		return m_brush;
	}

	bool CleanerBot::isActive() const
	{
		
		return m_active;
	}

	bool CleanerBot::isValid() const
	{
		bool result = false;
		if (m_battery > 0 && m_brush > 0)
		{
			result = true;
		}
		return result;
	}

	void CleanerBot::display() const
	{
		cout << "| " << left << setw(11) << getLocation();
		cout << "| " << right << fixed << setprecision(1) << setw(7) << getBattery();
		cout << "| " << right << setw(18) << getBrush();
			if (isActive() == true)
				{
				    cout << " | " << left << setw(7) << "YES" << "|" << endl;
				}
			else
				{ 
				    cout << " | " << left << setw(7) << "NO" << "|" << endl;
				}
	}


	int report(CleanerBot* bot, short num_bots)
	{

		int i = 0;
		int j = 0;
		int numberOfChargedBots = 0;
		CleanerBot m_bot;

            cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;		
		
	
		for (i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}

		}
		
			cout << endl 
			cout << "|====================================================|" << endl;
			cout << "| LOW BATTERY WARNING:                               |" << endl;
			cout << "|====================================================|" << endl;

			for (i = 0; i < num_bots; i++)
			{
				if (bot[i].isValid() && bot[i].getBattery() < 30)
				{
					numberOfChargedBots++;
				}
			}
			cout << "| Number of robots to be charged: " << Charged_Bots << "                  |" << endl;
		      cout << "| Sorting robots based on their available power:     |" << endl;
		      cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		      cout << "|------------+---------+--------------------+--------|" << endl;
	
			for (i = 0; i < num_bots - 1; i++)
			{	
					for (j = i + 1; j < num_bots; j++)
					{
					   if (bot[i].isValid() && bot[j].isValid())
					   {
						if (bot[i].getBattery() < bot[j].getBattery())
						{
							m_bot.set(bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive());
							bot[i].set(bot[j].getLocation(), bot[j].getBattery(), bot[j].getBrush(), bot[j].isActive());
							bot[j].set(m_bot.getLocation(), m_bot.getBattery(), m_bot.getBrush(), m_bot.isActive());
						}
					}
				}
			}

			for (i = 0; i < num_bots; i++)
			{
				if (bot[i].isValid())
				{
					bot[i].display();
				}
			}
			cout << "|====================================================|" << endl;
		}
		return 0;
	}
}