#include"Teacher.h"
#include"Course.h"
using namespace std;

Teacher::Teacher(std::string n, int ID, std::string em): name(n), teacherID(ID), email(em) {}

void Teacher::assignCourse(Course* course)
{
	coursesTaught.push_back(course);
}
void Teacher::removeCourse(Course* course)
{
	for (auto c = coursesTaught.begin(); c != coursesTaught.end(); c++)
	{
		if (*c = course)
		{
			coursesTaught.erase(c);
		}
	}
}
void Teacher::viewCourse(Course* course)
{
	cout << "Courses Taught by \a" << name << " are :" << endl;
	for (auto view = coursesTaught.begin(); view != coursesTaught.end(); view++)
	{
		cout << (*view)->getcoursename() << endl;
	}
}