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
void Course::viewStudents() const {
	for (auto i : studentenroll)
		cout << i->getstudentname() << endl;
}
string Course::getcoursename() const {
	return coursename;
}
int Course::getcoursecode()const {
	return courseCode;
};
Teacher* Course::getteacher()const {
	return teacher;
};
Room* Course::getAssignedRoom()const {
	return assignedRoom;
};
vector<Student*> Course::getEnrolledStudents()const {
	return studentenroll;
};