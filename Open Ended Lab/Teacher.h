#pragma once
class Teacher
{
private:
	int teacherID;
	string name,email;
	vector<string> coursesTaught;
public:
	void assignCourse();
	void removeCourse();
	void viewCourse();
};
void Teacher::assignCourse(){}
void Teacher::removeCourse(){}
void Teacher::viewCourse(){}

