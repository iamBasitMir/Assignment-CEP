#include "inputModule.h"

void inputModule::InputFileRead()
{
	string name = "input.txt";
	ifstream File(name);
	//Laptop Stack, No of Laptops 
	Laptops_Stack = LaptopStack(File);
	TeachingAssistantsArray(File);

	string next;
	if (File >> next)
	{
		Semester_Programs = stoi(next); //after TA's No of. Programs
		//cout << "No. of Semester Programs: " << Semester_Programs << '\n';
		//cout << '\n';
	}

	int limit = 0;
	Days.Monday.StudentsInfo = StudentsArray(File, limit);
	Days.Monday.Size = limit;
	//cout << "Monday Students Size: " << limit << endl;
}

stack<int> inputModule::LaptopStack(ifstream& File)
{
	string next;
	if (File >> next)
	{
		//stoi is used to convert string to integer
		int nlaptops = stoi(next);
		int n;
		for (n = 0; n < nlaptops; n++)
		{
			File >> next;
			Laptops_Stack.push(stoi(next)); //Changes Made
			//cout << "Laptop No: " << Laptops_Stack.size() << '\n';
			//cout << "Serial Number of Laptop: " << next << '\n';
		}
		//cout << '\n';
		//cout << "Size of Laptop Stack:" << Laptops_Stack.size() << '\n';
		return Laptops_Stack;
	}
}

void inputModule::TeachingAssistantsArray(ifstream& File)
{
	string next;
	if (File >> next)
	{
		int nTAs = stoi(next);
		//cout << "Size of TAs Array: " << nTAs << '\n';
		TA_Array.Size = nTAs;
		TA_Array.Point = new TA[nTAs];
		
		int n;
		for (n = 0; n < nTAs; n++)
		{
			File >> next;
			TA_Array.Point[n].name = next;
			//cout << '\n';
			//cout << "Name of TA: " << '\n';
			//cout << TA_Array.Point[n].name << '\n';
			File >> next;
			TA_Array.Point[n].startTimes[0] = stoi(next);
			//cout << TA_Array.Point[n].startTimes[0] << '\n';
			File >> next;
			TA_Array.Point[n].endTimes[0] = stoi(next);
			//cout << TA_Array.Point[n].endTimes[0] << '\n';
			File >> next;
			TA_Array.Point[n].startTimes[1] = stoi(next);
			//cout << TA_Array.Point[n].startTimes[1] << '\n';
			File >> next;
			TA_Array.Point[n].endTimes[1] = stoi(next);
			//cout << TA_Array.Point[n].endTimes[1] << '\n';
			File >> next;
			TA_Array.Point[n].startTimes[2] = stoi(next);
			//cout << TA_Array.Point[n].startTimes[2] << '\n';
			File >> next;
			TA_Array.Point[n].endTimes[2] = stoi(next);
			//cout << TA_Array.Point[n].endTimes[2] << '\n';
		}
	}
}

Student* inputModule::StudentsArray(ifstream& File, int& size)
{
	string next;
	if (File >> next)
	{
		int nStudents = stoi(next);
		Student* sArray = new Student[nStudents];
		int n;
		for (n = 0; n < nStudents; n++)
		{
			File >> next;
			sArray[n].enterTime = stoi(next);
			sArray[n].timelimit = sArray[n].enterTime;
			File >> next;
			sArray[n].firstName = next;
			File >> next;
			sArray[n].lastName = next;
			File >> next;
			sArray[n].numQuestions = stoi(next);
		}
		size = nStudents;
		return sArray;
	}
	return nullptr;
}


