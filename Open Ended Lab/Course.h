#pragma once
class Course
{
private:
	int courseCode;
	string coursename;
	Teacher*teacher;
	vector<Student*> studentenroll;
public:
	void addStudent() {
	
	}
	void removeStudent(){}
	void viewStudents(){}
	string getcoursename() {
		return coursename;
	}
};

