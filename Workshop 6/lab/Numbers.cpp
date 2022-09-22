/*
*****************************************************************************
						  Workshop - #6 (P1)
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
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds
{


   Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false;
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   bool Numbers::isEmpty() const {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   // Copy Constructor
   Numbers::Numbers(const Numbers& obj) {
      setEmpty();
      m_isOriginal = false;
      *this = obj;
   }

   // Copy Assignment Operator
   Numbers& Numbers::operator=(const Numbers& obj)
   {
      if (this != &obj)
      {
         delete[] m_numbers;
         delete[] m_filename;
         m_numbers = new double[obj.m_numCount];
         m_filename = new char[strlen(obj.m_filename) + 1];
         strcpy(m_filename, obj.m_filename);
         m_numCount = obj.m_numCount;
         for (int i = 0; i < m_numCount; i++)
         {
            m_numbers[i] = obj.m_numbers[i];
         }
         sort();
      }
      return *this;
   }

   // Number Count
   int Numbers::numberCount() const {
      char ch{};
      int count = 1;

      //Create an instance of ifstream to open the data file name.
      ifstream fin;
      fin.open(m_filename);

      //While the ifstream object has not failed keep reading single characters from the file

      //Count the number of newline characters in an integer variable
      while (fin.get(ch) && (count += ch == '\n'));

      //Return the number of counted newlines
      return count - 1;
   }

   // Load
   bool Numbers::load() {
      int i{};
      if (m_numCount) 
      {
         m_numbers = new double[m_numCount];
         ifstream fin;
         fin.open(m_filename);
         while (fin >> m_numbers[i] && (++i));
      }
      return i == m_numCount;
   }

   // Save
   void Numbers::save() {
      if (m_isOriginal && !isEmpty()) 
      {
         ofstream fin(m_filename);
         for (int i = 0; i < m_numCount; fin << m_numbers[i] << std::endl, i++);
      }
   }

   Numbers& Numbers::operator+=(double value)
   {
      if (!isEmpty())
      {
         //Create a temporary local double pointerand allocate memory with the increased size
         double* tempPointer = new double[m_numCount + 1];

         
         for (int i = 0; i < m_numCount; tempPointer[i] = m_numbers[i], i++)

         //Update the size of the data to the new size
         tempPointer[m_numCount] = value;

         // delete the original allocated memory
         delete[] m_numbers;

         //Set the original data pointer to point to newly allocated memory
         m_numbers = tempPointer;
         m_numCount++;
         sort();
      }
      return *this;
   }

   std::ostream& Numbers::display(std::ostream& ostr) const
   {
      if (!isEmpty())
      {
         ostr << "=========================" << std::endl;

         if (m_isOriginal)
            ostr << m_filename;
         else
            ostr << "***COPY***";
         ostr << std::endl << m_numbers[0];

         for (int i = 1; i < m_numCount; ostr << ", " << m_numbers[i], i++);

         ostr << std::endl << "-------------------------" << std::endl;

         ostr << "Total of " << m_numCount << " number(s)" << std::endl;

         ostr << "Largest number:  " << max() << std::endl;
         ostr << "Smallest number: " << min() << std::endl;
         ostr << "Average :        " << average() << std::endl;
         ostr << "=========================";
      }
      else
      {
         ostr << "Empty list";
      }
      return ostr;
   }

   ostream& operator<<(ostream& ostr, const Numbers& N)
   {

      //call the display function of N and return it
      return N.display(ostr);
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
      double result{};

      //read a double value using istr
      istr >> result;

      //add the double value to N using += operator
      N += result;
      return istr;
   }
}
