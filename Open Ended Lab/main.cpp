#include<iostream>
#include<map>
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Room.h"
#include "Timetable.h"
#include "Section.h"
#include "Time.h"
int main() {
	Student student1(201, "Omer", "omerjawaid0@gmail.com", "2-A");
	Teacher* teacher1 = new Teacher("Waleed", 201, "Waleed123@gmail.com");
	Room room1("202", 50);
	Course course1(201, "OOP", teacher1, &room1);	/*Course(int courseCode, const string & coursename, Teacher * teacher, Room * assignedRoom)*/
	Course course2(202, "DS", teacher1, &room1);
	course1.addStudent(&student1);
	course1.viewStudents();
	teacher1->assignCourse(&course1);
	teacher1->assignCourse(&course2);
	teacher1->viewCourse(&course1);
	Timetable timetable1;
	string generationchoice;
	vector<Teacher*> teachers = { teacher1 };
	cout << "Welcome to University Timetable System" << endl;
	do {
		cout << "----------------------------------------" << endl
			<< "How would you like to generate timetable: " << endl
			<< "1) Teacher wise timetable" << endl
			<< "2) Section wise timetable" << endl
			<< "3) Student wise time table" << endl
			<< "4) Room wise and Lab wise timetable" << endl
			<< "5) By queries?" << endl
			<< "6) Exit!" << endl
			<< "Enter your choice in numbers: ";
		cin >> generationchoice;

		if (generationchoice == "1")
		{
			timetable1.teacherTimetable();
		}
		else if (generationchoice == "2")
		{
		}
		else if (generationchoice == "3")
		{
			timetable1.studentTimetable();
		}
		else if (generationchoice == "4")
		{
			timetable1.roomTimetable();
		}
		else if (generationchoice == "5")
		{
			string query;
			do {
				cout << "Who is teaching on this day and time?" << endl
					<< "What is timetable for this day?" << endl
					<< "Enter your query: ";
				cin >> query;
				if (query == "1")
				{
					string day, time;
					cout << "Enter day and time: ";
					cin >> day >> time;
					timetable1.whoIsTeachingAt(day, time);
				}
				else if (query == "2")
				{
					string day;
					cout << "Enter day: ";
					cin >> day;
					timetable1.getTimeTableForDay(day);

				}
				else
					cout << "Invalid query! Try Again" << endl;
			} while (query != "1" && query != "2");
		}
		else if (generationchoice == "6")
		{
			return 0;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
	} while (generationchoice != "6");
}