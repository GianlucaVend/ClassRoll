#include "Classroll.h"

// client code
// By: Gianluca Venditti 
//Date: October 15th, 2021
//Purpose: To create a program for a professor who needs to maintain information on each student currently enrolled in a class.

void showCourse(ClassRoll&);

int main()
{
	//ClassRoll student("student.dat", "COMP 333"); 
	//showCourse(student);

	cout << "ClassRoll object examples for student.data file:" << endl << endl;
	ClassRoll comp333("student.data", "OOP C++", 3);
	cout << "Number of students in COMP 333 = " << comp333.getNoStudents() << endl;
	cout << "printing all students in student.data to the screenscreen:\n\n";
	comp333.writeStudents(cout);
	cout << "\nLooking up student T. Jones:\n";
	comp333.showGrade("T. Jones"); //should be in student.data, if not add it
	cout << "\nChange grade for T. Jones to a B\n\n";
	comp333.changeGrade("T. Jones", 'B');
	cout << "show T. Jones grade changed \n";
	comp333.showGrade("T. Jones");
	cout << "\nChange grade for T. Jones to a M\n\n";
	comp333.changeGrade("T. Jones", 'M');
	cout << "show non existant student\n";
	comp333.showGrade("Colin");
	cout << "printing all students in student.data again\n\n";
	comp333.writeStudents(cout);
	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function here for student.data
	showCourse(comp333);
	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	ClassRoll noclass("default.data", "No Class"); //empty file
	cout << "Number of students = " << noclass.getNoStudents() << endl << endl;
	cout << "\n\nbestClass object examples" << endl << endl;
	ClassRoll bestClass("fullclass.data", "poker");
	bestClass.writeStudents(cout);
	cout << "Number of students in " << bestClass.getCourseName()
		<< ": " << bestClass.getNoStudents() << endl << endl;
	bestClass.writeStudents(cout);
	bestClass.showGrade("Superman");
	cout << "write to a file \n";
	ofstream fout("sample.dat");
	if (!fout.is_open())
	{
		cout << "error opening sample.dat file " << endl;
		system("pause");
		exit(1);
	}
	bestClass.writeStudents(fout);
	cout << "\n\ncalling your show course function:";
	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function for bestclass
	showCourse(comp333);

	system("type sample.dat");
	system("pause");


}

void showCourse(ClassRoll& studentObject)
{
	cout << "Object-Oriented Programming using C++" << endl
		<< "Course Code :" << studentObject.getCourseName() << endl
		<< "Number of Students: " << studentObject.getNoStudents() << endl; 
}

/*
ClassRoll object examples for student.data file:

Number of students in COMP 333 = 3
printing all students in student.data to the screenscreen:

Student Name                      Assignment Total          Test Total               Grade

J. Doe                                50                      290                        A
P. Smith                              45                      190                        D
T. Jones                              50                      100                        F




Total Number of students is 3

Looking up student T. Jones:
Student's Grade: F
Change grade for T. Jones to a B

The grade for the student has been changed!
Grade does not exist
show T. Jones grade changed
Student's Grade: B
Change grade for T. Jones to a M

Grade does not exist
show non existant student
Error! Cannot find the student!
printing all students in student.data again

Student Name                      Assignment Total          Test Total               Grade

J. Doe                                50                      290                        A
P. Smith                              45                      190                        D
T. Jones                              50                      100                        B




Total Number of students is 3


calling your show course function:Object-Oriented Programming using C++
Course Code :OOP C++
Number of Students: 3



Empty object examples from default.data file

Number of students = 0



bestClass object examples

Student Name                      Assignment Total          Test Total               Grade

G.Venditti                            60                      290                        A
J. Smith                              45                      190                        D
M. Jones                              50                      100                        F




Total Number of students is 3
Number of students in poker: 3

Student Name                      Assignment Total          Test Total               Grade

G.Venditti                            60                      290                        A
J. Smith                              45                      190                        D
M. Jones                              50                      100                        F




Total Number of students is 3
Error! Cannot find the student!
write to a file


calling your show course function:

calling your show course function:Object-Oriented Programming using C++
Course Code :OOP C++
Number of Students: 3
Student Name                      Assignment Total          Test Total               Grade

G.Venditti                            60                      290                        A
J. Smith                              45                      190                        D
M. Jones                              50                      100                        F




Total Number of students is 3
Press any key to continue . . .
*/