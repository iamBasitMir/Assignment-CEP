#ifndef StudentbyDays_h
#define StudentbyDays_h
#include "Student.h"

typedef struct StudentbyDays
{
    Student* StudentsInfo;
    int Size;
} StudentbyDays;

typedef struct Day 
{
    StudentbyDays Monday;
} StudentbyDays_Day;

#endif 