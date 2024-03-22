#pragma once
class Course
{
private:
	int courseCode;
	string coursename;
	Teacher*teacher;
	vector<Student*> studentenroll;
public:
	void addStudent(Student*student) {
		studentenroll.push_back(student);
	}
	void removeStudent(Student*student){
		for (auto en = studentenroll.begin(); en != studentenroll.end(); en++)
			if(*en==student)
			studentenroll.erase(en);
	}
	void viewStudents(Student*student){
		for (auto i : studentenroll)
			cout << student->getstudentname()<<endl;
	}
	string getcoursename() {
		return coursename;
	}
};

