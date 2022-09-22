/*
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);
        void summary(); // Print a book summary
    };
  

}
#endif
*/


// This code has bad formatting that is not acceptable for
// midterm test, format it correctly and submit it
// in your mockup test
//
// The code must be indented properly
// with one statement in each line
//
// You can use visual studio or any other IDE to automatically
// format the code
//?Before doing this make sure your editor is not using?tab
// character in the text editor:

//For example:
//?In visual studio do the following from the Main menu:
//?Select: Tools/options
//?In the left menu expand:
//?Text Editor/"C/C++"/Tabs
//?and setup the options as follows:
//?Indenting: Smart
//?Tab size: 3
//?Indent Size: 3
//?select: Insert Spaces.
//
//?The other IDE's have the similar process, however you
// must figure it out yourself
//
//?When you are developing your code in Visual studio
// from scratch to automatically format your code?do
// the following from main menu:
//
//?In Main menu select: Edit/Advanced/Format Document
//?Or
//?Press Ctrl+K and then Ctrl+D
//
//?And then copy and paste the code in your Test.

