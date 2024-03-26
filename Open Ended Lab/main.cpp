#include<iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Room.h"
#include "Timetable.h"
int main() {
	Student student1(201, "Omer", "omerjawaid0@gmail.com", "2-A");
	Teacher teacher1("Waleed", 201, "Waleed123@gmail.com");
	Room room1;
	Course course1(201, "OOP", &teacher1, &room1);	/*Course(int courseCode, const string & coursename, Teacher * teacher, Room * assignedRoom)*/
	Course course2(202, "DS", &teacher1, &room1);
	course1.addStudent(&student1);
	course1.viewStudents();
	teacher1.assignCourse(&course1);
	teacher1.assignCourse(&course2);
	teacher1.viewCourse(&course1);
	string generationchoice;
	cout << "Welcome to University Timetable System" << endl;

	room1.assignRoom(&course1);
// 	do {
// 		cout << "----------------------------------------" << endl
// 			<< "How would you like to generate timetable: " << endl
// 			<< "1) Teacher wise timetable" << endl
// 			<< "2) Section wise timetable" << endl
// 			<< "3) Student wise time table" << endl
// 			<< "4) Room wise and Lab wise timetable" << endl
// 			<< "5) By queries?" << endl
// 			<< "6) Exit!" << endl
// 			<< "Enter your choice in numbers: ";
// 		cin >> generationchoice;

// 		if (generationchoice == "1")
// 		{
// 		}
// 		else if (generationchoice == "2")
// 		{
// 		}
// 		else if (generationchoice == "3")
// 		{
// 		}
// 		else if (generationchoice == "4")
// 		{
// 		}
// 		else if (generationchoice == "5")
// 		{
// 		}
// 		else if (generationchoice == "6")
// 		{
// 			return 0;
// 		}
// 		else
// 			cout << "Invalid choice" << endl;
// 	} while (generationchoice != "6");
return 0;
 }