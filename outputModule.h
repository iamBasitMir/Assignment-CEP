#ifndef OutputSystem_h
#define OutputSystem_h
#include "Student.h"
#include "StudentbyDays.h"
#include "TeachingAssistant.h"
#include <stack>
#include <queue>
#include <string>

class outputModule
{
private:
    queue<Student> Student_Queue;
    queue<Student> TeachingAssistant_Queue;
    stack<int> Laptop_Stack;
    queue<Student> Laptop_Queue;
    StudentbyDays_Day sDays;
    teachingAssistantArray TA_Array;
    teachingAssistantArray presentTA;
    int timeindex;
    int nSemester_Programs;
public:
    outputModule(StudentbyDays_Day Days, stack<int> Laptops, teachingAssistantArray TAs);
    void Output()
    {
        cout << "*************\n";
        cout << "Program 1:\n";
        cout << "*************\n";
        for (timeindex = 0; timeindex <= 240; timeindex++)
        {
            getTeachingAssistants();
            getStudents();
            studentsLaptopQueue();
            AssignStudents_Laptop();
            AssignTA_Student();
            UnAssignTA_Student();
            TALabEnding();
            //LabSummary(timeindex, nSemester_Programs);
        }
    }
    string TimeFormat(int Time)
    {
        int Hours = 0;
        int Minutes = 0;
        string TimeFormat = "", hour, min;

        if (Time != 0) 
        {
            //means time start at 12:00 PM as time < 60.
            if (Time < 60)
            {
                Hours = 12;
                Minutes = Time;
            }
            else 
            {
                while (Time > 60)
                {
                    Time = Time - 60;
                    //means time start at 0 meaning as 12:00 PM as time.
                    if (Hours == 12)
                    {
                        Hours = 0;
                    }
                    Hours++;
                }
                Minutes = Time;
            }
        }
        else 
        {
            Hours = 12;
            Minutes = 00;
        }

        if (Hours < 10) 
        {
            hour = "0" + to_string(Hours);
        }
        else 
        {
            hour = to_string(Hours);
        }

        if (Minutes < 10) 
        {
            min = "0" + to_string(Minutes);
        }
        else 
        {
            min = to_string(Minutes);
        }

        if (Minutes == 0) 
        {
            TimeFormat = hour + ":00" + " PM:";
        }
        else 
        {
            TimeFormat = hour + ":" + min + " PM:";
        }
        return TimeFormat;
    }
    void getTeachingAssistants();
    void getStudents();
    void studentsLaptopQueue();
    void AssignStudents_Laptop();
    void AssignTA_Student();
    void UnAssignTA_Student();
    void LabEndingTime(int& fulltime, int num);
    void TALabEnding();
}; 
#endif













