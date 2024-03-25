#pragma once
#include<iostream>
#include<map>
#include<vector>
#include"Course.h"
#include"Teacher.h"
using namespace std;
class Timetable
{
public:
	vector<Time*> times;
	void declareTimes() {
		times.emplace_back("8:30", "9:25");
		times.emplace_back("9:30", "10:25");
		times.emplace_back("10:30", "11:25");
		times.emplace_back("11:30", "12:25");
		times.emplace_back("12:30", "1:25");
		times.emplace_back("1:30", "2:25");
	}
	void teacherTimetable() {
		map<string, vector<Course*>> courses;
		Room* room1=new Room("4-01",50);
		Teacher* teacher1 = new Teacher("Waleed", 201, "Waleed123@gmail.com");
		Teacher* teacher2 = new Teacher("Tamim", 200, "Tamim@gmail.com");
		Teacher* teacher3 = new Teacher("Ds wali mam", 150, "ds@gmail.com");
		Course* course1 = new Course(403, "OOP", teacher1, room1);			/*Course(int courseCode, const string & coursename, Teacher * teacher, Room * assignedRoom)*/
		courses["Monday"].push_back(course1);
		courses["Monday"].push_back(course1);
		courses["Tuesday"].push_back(course1);
		for (auto & course : courses) {
			std::cout << "Day: " << course.first << ", Teachers: ";
			for (const auto & course : course.second) {
				cout << course->teacher->getName() << " ";
			}
			cout << endl;
		}
	};
	void studentTimetable();
	void sectionTimetabel();
	void roomTimetable();
};

