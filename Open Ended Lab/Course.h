#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;
class Teacher;

class Course
{
private:
	int courseCode;
	string coursename;
	Teacher*teacher;
	vector<Student*> studentenroll;
public:
	void addStudent(Student* student);
	void removeStudent(Student* student);
	void viewStudents();
	string getcoursename();
};

