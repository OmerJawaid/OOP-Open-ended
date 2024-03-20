#pragma once
class Teacher
{
private:
	int teacherID;
	string name,email;
	vector<Course*> coursesTaught;
public:
	Teacher(string& name, int& id, string email) : teacherID(id), name(name), email(email){}
	void assignCourse(Course* course);
	void removeCourse(Course* course);
	void viewCourse(Course* course);
};
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
	for (auto view = coursesTaught.begin(); view != coursesTaught.end(); view++)
	{
		cout << "Courses Taught by : " << name << "is " << endl;
		for (auto corname = coursesTaught.begin(); corname != coursesTaught.end(); corname++)
		{
			cout << course->getcoursename() << endl;
		}
	}
}