#pragma once
#include <string>
#include <vector>
#include "Course.h"

using namespace std;
class Student
{
private:
	int studentID;
	string name,email,section;
	
	
public:
	vector<Course*>coursesEnrolled;
	Student(int ID, string na, string mail,string sec) :studentID(ID), name(na), email(mail), section(sec) {
		cout << "Student constructor called" << endl;
	};
	void enrollCourse(Course*course) ;
	void dropCourse(Course*course) ;
	void viewCourses(Course*course);
	string getstudentname();
	string getsection()const;
};