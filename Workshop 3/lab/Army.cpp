/*
*****************************************************************************
						  Workshop - #3 (P1)
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
#include <iomanip>
#include <cstring> 
#include <cstdio> 
#include "Army.h" 

using namespace std;

namespace sdds
{
	void Army::setEmpty()
	{
		nationality[0] = '\0';
		numberOfUnits = 0;
	}

	void Army::createArmy(const char* country, double pow, int  troops)
	{
		if ((country != nullptr && strlen(country) > 0) && (pow > 0) && (troops > 0))
		{
			strncpy(nationality, country, MAX_NAME_LEN);
			nationality[MAX_NAME_LEN] = '\0';
			power = pow;
			numberOfUnits = troops;
		}
		else
		{
			setEmpty();
		}
	}

	void Army::updateUnits(int troops) {
		numberOfUnits = numberOfUnits + troops;
		power = (power + ((double)(0.25) * troops));
	}
	const char* Army::checkNationality() const {
		return nationality;

	}
	int Army::checkCapacity() const
	{
		return numberOfUnits;
	}
	double Army::checkPower() const
	{
		return power;
	}
	bool Army::isEmpty() const
	{
		if (nationality[0] == '\0' && numberOfUnits == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Army::isStrongerThan(const Army& army)const
	{
		bool stronger = false;
		double p1 = checkPower();
		double p2 = army.checkPower();
		if (p1 > p2)
		{
			stronger = true;
			return stronger;
		}
		else
		{
			return stronger;
		}
	}
	void battle(Army& arm1, Army& arm2)
	{
		cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
		if (!arm1.isEmpty() && !arm2.isEmpty()) {
			if (arm1.isStrongerThan(arm2))
			{
				cout << arm1.checkNationality() << " is " << "victorious!" << endl;
				arm2.updateUnits(-1 * arm2.checkCapacity() / 2);
			}
			else
			{
				cout << arm2.checkNationality() << " is " << "victorious!" << endl;
				arm1.updateUnits(-1 * arm1.checkCapacity() / 2);
			}
		}
	}
	void displayDetails(const Army* armies, int size)
	{
		cout << "Armies reporting to battle: " << endl;
		cout << fixed << setprecision(1);
		for (int i = 0; i < size; i++) {
			if (!armies[i].isEmpty())
			{
				cout << "Nationality: " << armies[i].checkNationality() << ", " << "Units Count: " << armies[i].checkCapacity() << ", " << "Power left: " << armies[i].checkPower() << endl;
			}
		}
	}
}


