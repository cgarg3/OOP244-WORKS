#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

	//postfix++ operator overload to increase the number of chapters by one.
	Book& Book::operator++(int) {
		m_num_chapters = m_num_chapters + 1;
		return *this;
	}

	// pending
	//A private member function called add_chapter which receives a pointer to a chapter and adds the chapter to the array of chapters for the book.It returns an integer which is the number of chapters after the new chapter is been added.Make sure you use the postfix++ operator you implemented above.

	Book& Book::add_chapter(const Chapter*) {

		return operator++;
	}

	// pending
	//A public member function called display which takes a reference to a ostream objectand returns a reference to an ostream object.This function is going to print a book object according to the provided sample output.You are required to properly use overloads implemented in the Chapter module.


	//An int type cast operator: It will return the number of chapters of a book object.
	Book:: operator int() const {
		return m_num_chapters;
	}

	//pending
	//A bool type cast operator: It will return true if titleand author, and num_chapters are non - empty and there is at least one chapter with number of pages greater than zero.Note that you will need to implement a getter member function on num_pages for the chapter class, in order to satisfy the last part of the given condition.

	Book:: operator bool() const {
		bool result = false;
		if (title != nullptr && author != nullptr && m_num_chapters > 0 && m_num_pages > 0)
		{
			result = true;
		}
		return result;
	}

	//A double type cast operator: It will return the book price.
	Book::operator double() const {
		return m_price;
	}

	//A const char* type cast operator: It will return title of the book
	Book::operator const char* () const {
		return m_title;
	}

	// pending
	//A logical not operator overload: return true if any of the conditions mentioned for the bool operator overload are not true.

	Book::void operator ! (void) {
		bool result = false;
		if(operator bool())
		{
			result = true;
		}
		return result;
	}

	//pending
	//A += operator overload: to allow adding a chapter to a book.Make sure you reuse code through the add_chapter member function you implemented above.
	Book& operator+= (int add_chapter) {
		if ()
		{

		}
	}

	// pending
	//A -= operator overload to apply a dollar value discount to the book price.For example if mybook is a Book object with a price tag of $100.50, then this operation mybook -= 10.5; will result in the mybook price to be lowed to $90.


	// pending
	//An insertion operator overload: to allow printing of a book object to the output console.Make sure you properly reuse the display member function you implemented above.


}
