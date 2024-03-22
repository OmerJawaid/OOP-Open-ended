#pragma once
#include <string>
#include <vector>

using namespace std;
class Course;

class Teacher
{
private:
	int teacherID;
	string name,email;
	vector<Course*> coursesTaught;
public:
	Teacher(std::string n, int ID, std::string em);
	void assignCourse(Course* course);
	void removeCourse(Course* course);
	void viewCourse(Course* course);
};
