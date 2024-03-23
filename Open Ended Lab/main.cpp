#include<iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Room.h"
#include "Timetable.h"
int main() {
	Student student1(201, "Omer", "omerjawaid0@gmail.com","2-A");
	Teacher teacher1("Waleed", 201, "Waleed123@gmail.com");
	Room room1("202", 50);
	Course course1(201, "OOP", &teacher1, &room1);	/*Course(int courseCode, const string & coursename, Teacher * teacher, Room * assignedRoom)*/
	Course course2(202, "DS", &teacher1, &room1);
	course1.addStudent(&student1);
	course1.viewStudents();
	teacher1.assignCourse(&course1);
	teacher1.assignCourse(&course2);
	teacher1.viewCourse(&course1);
	}