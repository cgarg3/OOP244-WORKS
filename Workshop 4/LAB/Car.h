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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <cstdio>
#include <iostream>
#include <cctype>
namespace sdds
{
	class Car
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		// setting it to null value
		void resetInfo();
		void dellocate();

	public:
		// constructors
		Car();
		Car(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1 );

		// destructor
		~Car();

		// setting up the info of the car 
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);

		// displaying the car data
		void printInfo() const;

		// all M.V have valid values as per valid car M.V values
		bool isValid() const;

		// values should be equal 
		bool isSimilarTo(const Car& car) const;
	};

	// Global functions
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}

#endif // SDDS_CAR_H
