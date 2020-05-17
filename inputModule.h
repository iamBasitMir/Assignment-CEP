#include "StudentbyDays.h"
#include "TeachingAssistant.h"
#include <fstream>
#include <stack>
#include <cstdlib>

class inputModule
{
private:
    stack<int> LaptopStack(ifstream& inFile);
    void TeachingAssistantsArray(ifstream& inFile);
    Student* StudentsArray(ifstream& inFile, int& size);
public:
    //constructor
    inputModule()
    {
    } 
    void InputFileRead();
    stack<int> Laptops_Stack;
    TAArray TA_Array;
    StudentbyDays_Day Days;
    int Semester_Programs; 
};
