#include "Classroll.h"


// Implemnetation file
// By: Gianluca Venditti 
//Date: October 15th, 2021

ClassRoll::ClassRoll(string initialName, string initialCourseName, int initialMaxStudents)
{
	if (initialMaxStudents > SIZE || initialMaxStudents < 0)
	{
		maxStudents = 25; // setting a default value

		cout << "Error, wrong input";
	}
	else
	{
		maxStudents = initialMaxStudents;
	}

	courseName = initialCourseName; 

	ifstream fin(initialName);
	if (!fin.is_open())
	{
		cout << "error opening student.dat file ";
		system("pause");
		exit(-1);
	}

	int length;
	for (length = 0; length < maxStudents; length++)
	{

		getline(fin, students[length].studentName);
		if (fin.eof())
			break;
		fin >> students[length].assignmentTotal;
		fin >> students[length].testTotal;
		fin >> students[length].letterGrade;
		fin.ignore(80, '\n');
	}
	noStudents = length;
}

void ClassRoll::writeStudents(ostream& fout) const
{
	fout << left << setw(30) << "Student Name" << setw(20) << right << "Assignment Total" <<
		setw(20) << right << "Test Total" << setw(20) << "Grade" << endl << endl;


	for (int row = 0; row < noStudents; row++)
	{
		fout << setw(20) << left << students[row].studentName;

		for (int col = 0; col < 1; col++)
		{
			fout << setw(20) << right << students[row].assignmentTotal;
			fout << setw(25) << right << students[row].testTotal;
		}
		fout << setw(25) << right << students[row].letterGrade;
		fout << endl;
	}

	fout << "\n\n\n\n";
	fout << "Total Number of students is " << noStudents << endl;
}

int ClassRoll::searchStudent(string studentName) const
{

	int index = 0; 

	for (index; index < noStudents; index++)
	{
		if (students[index].studentName == studentName)
		{
			break; 
		}
	}

	return index; 
}

void ClassRoll::showGrade(string studentName) const
{
	int index = searchStudent(studentName);

	if (index == noStudents)
	{
		cout << "Error! Cannot find the student! " << endl; 
	}
	else
	{
		cout << "Student's Grade: " << students[index].letterGrade; 
	}
}

void ClassRoll::changeGrade(string studentName, char newGrade)
{
		newGrade = toupper(newGrade);
		int index = searchStudent(studentName);

		if (index == noStudents)
		{
			cout << "student grade was not found!" << endl; 
		}
		else
		{
			if (students[index].letterGrade == newGrade)
			{
				cout << "student grade did not change!" << endl; 
			}
			else
			{
				switch (newGrade)
				{
				case 'A': case 'B':  case 'C':  case 'D': case 'F':
				{
					students[index].letterGrade = newGrade;
					cout << "The grade for the student has been changed!" << endl;
				}
				default:
					cout << "Grade does not exist" << endl;
				}
			}
		
		}
}