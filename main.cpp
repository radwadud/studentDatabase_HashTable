
#include <iostream>
#include "hashTest.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
    Hash student;
    
    //Data Input
    student.insert(101, 3.4, "Computer Science");
    student.insert(102, 3.0, "Business");
    student.insert(103, 4.0, "Physics");
    student.insert(104, 2.7, "English");
    student.insert(105, 2.9, "Business");
    student.insert(106, 3.8, "English");
    student.insert(107, 3.1, "Computer Science");
    student.insert(108, 3.3, "English");
    student.insert(109, 2.8, "Physics");
    student.insert(110, 3.4, "Computer Science");
    student.insert(111, 3.0, "Physics");
    student.insert(112, 3.1, "English");
    student.insert(113, 1.9, "Business");
    student.insert(114, 3.9, "Computer Science");
    student.insert(125, 3.2, "Business");
    student.insert(126, 3.4, "Computer Science");
    student.insert(127, 3.0, "Business");
    student.insert(128, 4.0, "Physics");
    student.insert(129, 2.7, "English");
    student.insert(130, 2.9, "Business");
    student.insert(131, 3.8, "English");
    student.insert(132, 3.1, "Computer Science");
    student.insert(133, 3.3, "English");
    student.insert(134, 2.8, "Physics");
    student.insert(135, 3.4, "Computer Science");

    
    //print function
    student.printData();
    cout << "Searching for student inside a bucket..." << endl;
    //search function
    student.lookup(135);
    cout << "---------------------" << endl;
    cout << "Searching another student..." << endl;
    student.lookup(109);
    cout << "=====================" << endl;
    //delete function
    student.deleteData(135);
    cout << "=====================" << endl;
    //search after delete
    cout << "Searching for deleted student" << endl;
    student.lookup(135);

    
    return 0;
}
