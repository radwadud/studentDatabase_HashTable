/*
 hashTable.cpp
 
 CSCE 2110
 Homework 1
 
 Rad Wadud
 ID# 10925989
 Email: radwadud@my.unt.edu
 
 */


#include <iostream>
#include "hashTest.h"
using std::cout;
using std::endl;
using std::string;

//Constructor
Hash::Hash()
{
    int i;
    for (i = 0; i < tableSize; i++)
    {
        hashTable[i] = new data;
        hashTable[i]->studentId = 0;
        hashTable[i]->gpa = 0;
        hashTable[i]->major = "empty";
        hashTable[i]->next = NULL;
    }
}

//Taking student id and generating an index or key value for hash table
int Hash::hashIndex(int studentId)
{
    int hash = 0;
    int index;
    int i;
//NOTE:
//On this for loop, I have multipiled number 3,
//and ran it 5 time so that i can get the data
//more spread out. Otherwise i get more than
//2 conflicts and more empty buckets.
    for (i = 0; i < 5; i++)
    {
        hash = (hash + studentId) * 3;
    }
    
    index = hash % tableSize;
    return index;
}

//adding the values
void Hash::insert(int idStudent, double studentGPA, string studentMajor)
{
    int index;
    index = hashIndex(idStudent);

    if (hashTable[index]->studentId == 0) //checking if the bucket is empty
    {
        hashTable[index]->studentId = idStudent;
        hashTable[index]->gpa = studentGPA;
        hashTable[index]->major = studentMajor;
    }
    //if bucket is not empty move to the next node
    else
    {
        //pointing to new node
        data* point = hashTable[index];
        data* n = new data;
        n->studentId = idStudent;
        n->gpa = studentGPA;
        n->major = studentMajor;
        n->next = NULL;
        while (point->next != NULL)
        {
            point = point->next;
        }
        point->next = n;
    }
}

//checking for number of conclicts in a bucket
int Hash::itemInBucket(int index)
{
    int number = 0;
    
    if (hashTable[index]->studentId == 0)
    {
        return number;
    }
    else
    {
        number++;
        data *point = hashTable[index];
        while (point->next != NULL)
        {
            number++;
            point = point->next;
        }
    }
    return number;
}

//Printing the data
void Hash::printData()
{
    int number;
    int i, j;
    cout << "Hash Table: " << endl;
    for (i = 0; i < tableSize; i++)
    {
        number = itemInBucket(i);
        /*
        cout << "Key=\t" << i << endl;
        cout << "ID:\t\t" << hashTable[i]->studentId << endl;
        cout << "GPA:\t" << hashTable[i]-> gpa << endl;
        cout << "Major:\t" <<hashTable[i]->major << endl;
        cout << "# items= " << number << endl;
        cout << "____________________" << endl;
         */
        cout << i+1 << ":";
        if (number > 0)
        {
            for(j = 0; j < number; j++)
            cout << "\tO";
        }
        cout << "\n";
    }
}

//Searching for an individual student
void Hash::lookup(int idStudent)
{
    int index = hashIndex(idStudent);
    bool foundID = false;
    double foundGPA = 0;
    string foundMajor;
    data *point = hashTable[index];
    
    while(point != NULL)
    {
        if(point->studentId == idStudent)
        {
            foundID = true;
            foundGPA = point->gpa;
            foundMajor = point->major;
        }
        point = point->next;
    }
    
    if(foundID == true)
    {
        cout << "Id: " << idStudent <<endl;
        cout << "GPA: " << foundGPA <<endl;
        cout << "Major: " << foundMajor <<endl;
    }
    else
        cout << "Not Found!" << endl;
}

//Delete Student data
void Hash::deleteData(int idStudent)
{
    int index = hashIndex(idStudent);
    data* deletePointer;
    data* pointerOne;
    data* pointerTwo;
    
    //bucket list is epmty
    if(hashTable[index]->studentId == 0)
    {
        cout << "ID: " << idStudent << "Not Found!" << endl;
    }
    
    //bucket has only one item
    else if(hashTable[index]->studentId == idStudent && hashTable[index]->next == NULL)
    {
        hashTable[index]->studentId = 0;
        hashTable[index]->gpa = 0;
        hashTable[index]->major = "empty";
        
        cout << "ID: " << idStudent << " Deleted" << endl;
    }
    
    //bucket has more than one but matches the 1st item
    else if (hashTable[index]->studentId == idStudent)
    {
        deletePointer = hashTable[index];
        hashTable[index] = hashTable[index]->next;  //next item becomes the 1st item
        delete deletePointer;
        
        cout << "ID: " << idStudent << " Deleted" << endl;
    }
    //bucket has more than one but matches the 2nd item
    else
    {
        pointerOne = hashTable[index]->next;
        pointerTwo = hashTable[index];
        while (pointerOne != NULL && pointerOne->studentId != idStudent)
        {
            pointerTwo = pointerOne;
            pointerOne = pointerOne->next;
        }
        
        if (pointerOne == NULL)
        {
            cout << "ID: " << idStudent << "Not Found!" << endl;
        }
        
        else
        {
            deletePointer = pointerOne;
            pointerOne = pointerOne->next;
            pointerTwo->next = pointerOne;
            delete deletePointer;
            
            cout << "ID: " <<idStudent << " Deleted" << endl;
        }
    }
}










