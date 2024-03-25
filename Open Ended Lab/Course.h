#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;
class Teacher;
class Room;

class Course
{
private:
	int courseCode;
	string coursename;
	Room* assignedRoom;
	string startTime, endTime;
public:
	Teacher* teacher;
	vector<Student*> studentenroll;
	Course(int courseCode, const string& coursename, Teacher* teacher, Room* assignedRoom)
		: courseCode(courseCode), coursename(coursename), teacher(teacher), assignedRoom(assignedRoom) {}
	void addStudent(Student* student);
	void removeStudent(Student* student);
	void viewStudents ()const;
	string getcoursename ()const;
	int getcoursecode()const;
	Teacher* getteacher()const;
	Room* getAssignedRoom()const;
	vector<Student*> getEnrolledStudents()const;
};

