#include"outputModule.h"

outputModule::outputModule(StudentbyDays_Day Days, stack<int> Laptops, teachingAssistantArray TAs)
{
    sDays = Days;
    Laptop_Stack = Laptops;
    TA_Array = TAs;
    presentTA.Size = 0;
    presentTA.Point = new TA[TAs.Size];
    timeindex = 0;
    Output();
}
//gets and assign one TA in accordance with TimeFormat. 
void outputModule::getTeachingAssistants()
{
    if (presentTA.Size != TA_Array.Size)
    {
        int n;
        for (n = 0; n < TA_Array.Size; n++)
        {
            if (TA_Array.Point[n].endTimes[0] != 0)
            {
                if (timeindex == TA_Array.Point[n].startTimes[0])
                {
                    presentTA.Size = presentTA.Size + 1;
                    presentTA.Point[n] = TA_Array.Point[n];
                    cout << TimeFormat(timeindex) << " " << presentTA.Point[n].name << " has began lab hours.\n";
                }
            }
        }
    }
}
//gets all students from Monday and add them into the queue.
void outputModule::getStudents()
{
    StudentbyDays Monday = sDays.Monday;

    if (timeindex == 0)
    {
        int n;
        for (n = 0; n < Monday.Size; n++)
        {
            Student_Queue.push(Monday.StudentsInfo[n]);
        }
    }
}
//getting the particular present student out of the queue and adding to laptop Queue.
void outputModule::studentsLaptopQueue()
{
    if (!Student_Queue.empty())
    {
        Student present = Student_Queue.front();
        if (present.enterTime == timeindex)
        {
            //getting the particular present student out of the queue.
            Student_Queue.pop();
            cout << TimeFormat(timeindex) << " " << present.firstName << " " << present.lastName << " " << " has arrived in TA#007\n";
            // add student to laptop queue
            Laptop_Queue.push(present);
        }
    }
}
//Assign laptop To particular present student.
void outputModule::AssignStudents_Laptop()
{
    // assign laptop To Student
    if (!Laptop_Queue.empty())
    {
        Student present = Laptop_Queue.front();
        if (timeindex == present.timelimit + 2)
        {
            present.laptopSerialNum = Laptop_Stack.top();
            Laptop_Stack.pop();
            cout << TimeFormat(timeindex) << " " << present.firstName << " " << present.lastName << " has borrowed laptop " << present.laptopSerialNum << " and moved to TA line\n";
            present.timelimit = present.timelimit + 2;
            Laptop_Queue.pop();
            //adding student who borrowed the laptop into TAs Queue. 
            TeachingAssistant_Queue.push(present);
        }
    }
}
//Assign teaching assistant To particular present student.
void outputModule::AssignTA_Student()
{
    if (!TeachingAssistant_Queue.empty())
    {
        Student present_Student = TeachingAssistant_Queue.front();
        TA present_TA;
        int n;
        for (n = 0; n < presentTA.Size; n++)
        {
            TA temp = presentTA.Point[n];
            if (!temp.isStudentWithTA())
            {
                present_TA = temp;
                presentTA.Point[n].withTA = present_Student;

                // assigned current time to current student so student can be deassigned from TA
                TeachingAssistant_Queue.front().timelimit = timeindex;
                cout << TimeFormat(timeindex) << " " << present_Student.firstName << " " << present_Student.lastName << " is getting help from " << present_TA.name << '\n';
            }
        }
    }
}
//UnAssigning teaching assistant To particular present student.
void outputModule::UnAssignTA_Student()
{
    if (!TeachingAssistant_Queue.empty())
    {
        Student present_Student = TeachingAssistant_Queue.front();
        if (timeindex == present_Student.timelimit + 5)
        {
            int n;
            for (n = 0; n < presentTA.Size; n++)
            {
                TA present_TA = presentTA.Point[n];
                if (present_TA.withTA.firstName == present_Student.firstName)
                {
                    presentTA.Point[n].withTA = Student();
                }
            }
            TeachingAssistant_Queue.pop();
            present_Student.numAnswered = present_Student.numAnswered + 1;
            present_Student.timelimit = present_Student.timelimit + 5;
            if (present_Student.numQuestions > present_Student.numAnswered)
            {
                cout << TimeFormat(timeindex) << " " << present_Student.firstName << " " << present_Student.lastName << " has one more question answered and gotten back in line.\n";
                TeachingAssistant_Queue.push(present_Student);
            }
            else
            {
                cout << TimeFormat(timeindex) << " " << present_Student.firstName << " " << present_Student.lastName << " has no more questions and went home.\n";
            }
        }
    }
}
//Gets ending time of lab.
void outputModule::LabEndingTime(int& fulltime, int limit)
{
    if (timeindex == 0)
    {
        int completetime = 0;
        int t;
        for (t = 0; t < presentTA.Size; t++)
        {
            if (completetime <= presentTA.Point[t].endTimes[limit]) completetime = presentTA.Point[t].endTimes[limit];
        }
        fulltime = completetime;
        int TAEndTime;
        TAEndTime = completetime;
    }
}
//Lab time where teaching assistant leaves the lab.
void outputModule::TALabEnding()
{
    if (presentTA.Size != 0)
    {
        int n;
        for (n = 0; n < presentTA.Size; n++)
        {
            if (timeindex == presentTA.Point[n].endTimes[0])
            {
                // TA is leaving the lab.
                presentTA.Size -= 1;
                cout << TimeFormat(timeindex) << " " << presentTA.Point[n].name << " has  finished lab hours." << endl;
                if (n == 0)
                {
                    presentTA.Point[0] = presentTA.Point[1];
                }
            }
        }
    }

}


