#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Book.h"
#include "Publication.h"
#include "Lib.h"
using namespace std;

namespace sdds {
   //Constructor
   Book::Book() : Publication() {
      m_authorName = nullptr;
   }

   // The rule of three
   Book::Book(const Book& book) : Publication(book) {
      *this = book;
   }
   Book& Book::operator=(const Book& book) {
      Publication::operator=(book);
      if (m_authorName) {
         deallocate();
      }

      // Deep copying
      if (book.m_authorName != nullptr) {
         m_authorName = new char[strlen(book.m_authorName) + 1];
         strcpy(m_authorName, book.m_authorName);
      }
      return *this;
   }
   Book::~Book() {
      deallocate();
   }
   void Book::deallocate() {
      delete[] m_authorName;
      m_authorName = nullptr;
   }



   void Book::set(int member_id) {
      Publication::set(member_id);
      Publication::resetDate();
   }

   char Book::type()const {
      return 'B';
   }

   Book::operator bool() const {
      return m_authorName != nullptr && Publication::operator bool();
   }

   ostream& Book::write(ostream& os) const {
      Publication::write(os);
      if (conIO(os)) {
         char tmp_authorName[SDDS_AUTHOR_WIDTH + 1]{};
         strncpy(tmp_authorName, m_authorName, SDDS_AUTHOR_WIDTH);
         os << " ";
         os.width(SDDS_AUTHOR_WIDTH);
         os.setf(ios::left);
         os.fill(' ');
         os << tmp_authorName << " |";
         os.unsetf(ios::left);
      }
      else {
         os << "\t" << m_authorName;
      }
      return os;
   }

   istream& Book::read(istream& istr) {
      // Create temp variables
      char tmp_authorName[256 + 1]{};
      Publication::read(istr);

      if (m_authorName) {
         deallocate();
      }

      if (conIO(istr)) {
         istr.ignore();
         cout << "Author: ";
      }
      else {
         istr.ignore(1000, '\t');
      }
      istr.get(tmp_authorName, 256);

      if (istr) {
         m_authorName = new char[strlen(tmp_authorName) + 1];
         strcpy(m_authorName, tmp_authorName);
      }
      return istr;
   }
}