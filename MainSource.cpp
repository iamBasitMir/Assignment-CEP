#include "inputModule.h"
#include "outputModule.h"
inputModule obj;

int main()
{
    StudentbyDays_Day Student_Data;
    stack<int> Laptops_Stack;
    obj.InputFileRead();
    Student_Data = obj.Days;
    Laptops_Stack = obj.Laptops_Stack;
    outputModule output(Student_Data, Laptops_Stack, obj.TA_Array);
    
    return 0;
}