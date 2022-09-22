#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
  
   // read functions
   bool read(char *name);
   bool read(int &number);
   bool read(char &grade);

} // namespace sdds
#endif // !SDDS_FILE_H_
