#include "Student.h"
#ifndef TeachingAssistant_h
#define TeachingAssistant_h

typedef struct teachingAssistant 
{
    string name; 
    int startTimes[3]; 
    int endTimes[3];
    int minute;
    
    Student withTA;
    bool isStudentWithTA() 
    {
        if (withTA.firstName == "") 
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
} TA;

typedef struct teachingAssistantArray
{
    TA* Point;
    int Size;
} TAArray;

#endif 