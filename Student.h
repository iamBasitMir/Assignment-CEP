#include <iostream>
#include <stdio.h>
#include <string>
#ifndef Student_h
#define Student_h
using namespace std;

typedef struct DataStructuresStudent 
{
    string firstName;
    string lastName;
    int enterTime;
    int numQuestions;
    int numAnswered = 0;
    int laptopSerialNum;
    int timelimit;
    bool withTA = false;
} Student;

#endif 