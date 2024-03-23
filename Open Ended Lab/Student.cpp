#include"Course.h"
#include"Student.h"
using namespace std;
void Student::enrollCourse(Course* course) {
	coursesEnrolled.push_back(course);
}
void Student::dropCourse(Course* course) {
	for (auto cor = coursesEnrolled.begin(); cor != coursesEnrolled.end(); cor++)
		if (*cor == course)
			coursesEnrolled.erase(cor);
}
void Student::viewCourses(Course* course) {
	cout << "Courses Enrolled: ";
	for (auto i : coursesEnrolled)
	{
		cout << course->getcoursename() << endl;
	}
}
string Student::getstudentname() {
	return name;
}
string Student::getsection() const{
	return section;
}