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
	Teacher*teacher;
	vector<Student*> studentenroll;
	Room* assignedRoom;
public:
	Course(int courseCode, string& coursename) {};
	void addStudent(Student* student);
	void removeStudent(Student* student);
	void viewStudents ()const;
	string getcoursename ()const;
	int getcoursecode()const;
	Teacher* getteacher()const;
	Room* getAssignedRoom()const;
	vector<Student*> getEnrolledStudents()const;
};

