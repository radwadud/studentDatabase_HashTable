/*
 hashtable.h
 
 CSCE 2110
 Homework 1
 
 Rad Wadud
 ID# 10925989
 Email: radwadud@my.unt.edu
 
 */


#include <iostream>
using std::string;

// Class for the hash table
class Hash
{
private:
    static const int tableSize = 20;
    //Data structure
    struct data{
        int studentId;
        double gpa;
        string major;
        data *next;
    };
    data *hashTable[tableSize];

public:
    Hash();
    int hashIndex(int idStudent);
    void insert(int idStudent, double studentGPA, string studentMajor);
    int itemInBucket(int index);
    void printData();
    void lookup(int idStudent);
    void deleteData(int idStudent);

};

