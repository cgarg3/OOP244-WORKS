/*
*****************************************************************************
						  Workshop - #4 (P1)
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
#include "Car.h"
using namespace std;
namespace sdds
{
	void Car::resetInfo()
	{
		 m_type = nullptr;
		 m_brand = nullptr;
		 m_model = nullptr;
		 m_year = 0;
		 m_code = 0;
		 m_price = 0;
	}

	Car::Car()
	{
		resetInfo();
	}

	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type && brand && model && year >= 1990 && code >= 100 && price > 0)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			 m_year = year;
			 m_code = code;
			 m_price = price;
		}
		else
		{
			resetInfo();
		}
	}

	void Car::dellocate()
	{
		delete[] m_type;
		m_type = nullptr;

		delete[] m_brand;
		m_brand = nullptr;

		delete[] m_model;
		m_model = nullptr;
	}

	Car::~Car()
	{
		dellocate();
	}

	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		dellocate();
		if (type && brand && model && year >= 1990 && code >= 100 && price > 0)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			 m_year = year;
			 m_code = code;
			 m_price = price;
		}
		else
		{
			resetInfo();
		}
		return *this;
	}

	void Car::printInfo() const
	{
		cout << "| " << left << setw(11) << m_type;
		cout << "| " << left << setw(17) << m_brand;
		cout << "| " << left << setw(17) << m_model;
		cout << "| " << left << setw(5) << m_year;
		cout << "| " << right << setw(4) << m_code;
		cout << " | " << right << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;
	}

	bool Car::isValid() const
	{
		bool result = false;
		if (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_price > 0)
		{
			result = true;
		}
		return result;
	}

	bool Car::isSimilarTo(const Car& car) const
	{
		bool result = false;
		if (m_type == car.m_type && m_brand == car.m_brand && m_model == car.m_model && m_year == car.m_year)
		{
			result = true;
		}
		return result;
	}

	bool has_similar(const Car car[], const int num_cars)
	{
		bool result = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					result = true;
				}
			}
		}
		return result;
	}

	bool has_invalid(const Car car[], const int num_cars)
	{
		bool result = false;
		for (int i = 0; i < num_cars; i++)
		{
			if (!car[i].isValid())
			{
				result = true;
			}
		}
		return result;
	}
	void print(const Car car[], const int num_cars)
	{
		int i = 0;
		for (i = 0; i < num_cars; i++)
		{
			if (car[i].isValid())
			{
				car[i].printInfo();
			}
		}
	}
};