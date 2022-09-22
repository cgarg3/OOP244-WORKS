#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Lib.h"
#include "Publication.h"

using namespace std;

namespace sdds {
   // Set default
   void Publication::setDefault() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
      resetDate();
   }

   void Publication::deallocate() {
      delete[] m_title;
      m_title = nullptr;
   }

   // Constructor
   Publication::Publication() {
      setDefault();
   }

   // The rule of three
   // Copy overload
   Publication::Publication(const Publication& publication) {
      *this = publication;
   }
   // Copy assignment
   Publication& Publication::operator=(const Publication& publication) {
      set(publication.m_membership);
      setRef(publication.m_libRef);
      strcpy(m_shelfId, publication.m_shelfId);
      m_date = publication.m_date;

      if (m_title) {
         deallocate();
      }

      // Deep copying
      if (publication.m_title != nullptr) {
         m_title = new char[strlen(publication.m_title) + 1];
         strcpy(m_title, publication.m_title);
      }
      else {
         m_title = nullptr;
      }
      return *this;
   }
   // Destruction
   Publication::~Publication() {
      deallocate();
   }

   // ----------------- Methods -----------------------
   // Modifiers
   // Sets the membership attribute to either zero or a five-digit integer.
   void Publication::set(int member_id) {
      m_membership = member_id;
   }

   // Sets the **libRef** attribute value
   void Publication::setRef(int value) {
      m_libRef = value;
   }

   // Sets the date to the current date of the system.
   void Publication::resetDate() {
      m_date = Date();
   }

   // Queries
   //Returns the character 'P' to identify this object as a "Publication object"
   char Publication::type()const {
      return 'P';
   }

   //Returns the date attribute
   Date Publication::checkoutDate()const {
      return m_date;
   }

   //Returns true is the publication is checkout (membership is non-zero)
   bool Publication::onLoan()const {
      return m_membership != 0;
   }

   //Returns true if the argument title appears anywhere in the title of the 
   //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
   bool Publication::operator==(const char* title)const {
      return strstr(m_title, title) != nullptr;
   }

   //Returns the title attribute
   Publication::operator const char* ()const {
      return m_title;
   }

   //Returns the libRef attirbute. 
   int Publication::getRef()const {
      return m_libRef;
   }

   // Streamable pure virtual function
   bool Publication::conIO(ios& io)const {
      return &io == &std::cin || &io == &std::cout;
   }
   ostream& Publication::write(ostream& os) const {
      char tmp_title[SDDS_TITLE_WIDTH + 1]{};
      strncpy(tmp_title, m_title, SDDS_TITLE_WIDTH);

      if (conIO(os)) {
         os << "| " << m_shelfId << " | ";
         os.width(30);
         os.setf(ios::left);
         os.fill('.');
         os << tmp_title << " | ";
         os.unsetf(ios::left);
         m_membership != 0 ? os << m_membership : os << " N/A ";
         os << " | " << m_date << " |";
      }
      else {
         os << type() << "\t";
         os << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t"; // removed a \t
         m_membership != 0 ? os << m_membership : os << "0"; // changed N/A to 0
         os << "\t" << m_date;
      }
      return os;
   }
   istream& Publication::read(istream& istr) {
      // Create temp variables
      char tmp_title[256 + 1]{};
      char tmp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
      int tmp_libRef = -1;
      int tmp_membership = 0;
      Date tmp_date{};

      if (m_title) {
         deallocate();
      }
      setDefault();

      if (conIO(istr)) {
         std::cout << "Shelf No: ";
         istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1);

         if (strlen(tmp_shelfId) != SDDS_SHELF_ID_LEN) {
            istr.setstate(std::ios::failbit);
         }
         std::cout << "Title: ";
         istr.getline(tmp_title, 256);

         std::cout << "Date: ";
         istr >> tmp_date;
      }
      else {
         istr >> tmp_libRef;
         istr.ignore();
         istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
         istr.getline(tmp_title, 256, '\t');
         istr >> tmp_membership;
         istr.ignore();
         istr >> tmp_date;
      }

      if (!tmp_date) {
         istr.setstate(ios::failbit);
      }

      if (istr) {
         m_title = new char[strlen(tmp_title) + 1];
         strcpy(m_title, tmp_title);
         strcpy(m_shelfId, tmp_shelfId);
         m_membership = tmp_membership;
         m_date = tmp_date;
         m_libRef = tmp_libRef;
      }

      return istr;
   }
   Publication::operator bool() const {
      bool done = false;
      if (m_title != nullptr && m_shelfId[0] != '\0') {
         return true;
      }
      return done;
   }
}