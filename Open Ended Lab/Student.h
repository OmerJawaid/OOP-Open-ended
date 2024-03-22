#pragma once
#include<iostream>
#include<vector>
#include"Course.h"
using namespace std;

class Student
{
private:
	int studentID;
	string name,email;
	vector<Course*>coursesEnrolled;
	
public:
	Student(int ID, string na, string mail) :studentID(ID), name(na), email(mail) {
		cout << "Student constructor called" << endl;
	};
	void enrollCourse(Course*course) ;
	void dropCourse(Course*course) ;
	void viewCourses(Course*course);
	string getstudentname() {
		return name;
	}
};
void Student::enrollCourse(Course*course) {
	coursesEnrolled.push_back(course);
}
void Student::dropCourse(Course*course){
	for (auto cor = coursesEnrolled.begin(); cor != coursesEnrolled.end(); cor++)
		if (*cor == course)
			coursesEnrolled.erase(cor);
}
void Student::viewCourses(Course*course){
	cout << "Courses Enrolled: ";
	for (auto i : coursesEnrolled)
	{
		cout << course->getcoursename()<<endl;
	}
}


