#include"Course.h"
#include"Student.h"
#include"Room.h"
using namespace std;

void Course::addStudent(Student* student) {
	studentenroll.push_back(student);
}
void Course:: removeStudent(Student* student) {
	auto it = std::find(studentenroll.begin(), studentenroll.end(), student);
	if (it != studentenroll.end()) {
		studentenroll.erase(it);
	}
	}
void Course::viewStudents() {
	for (auto i : studentenroll)
		cout << i->getstudentname() << endl;
}
string Course::getcoursename() {
	return coursename;
}