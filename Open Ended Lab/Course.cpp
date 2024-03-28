// Course.cpp
#include "Course.h"
#include "Student.h"
#include "Room.h"
#include "Section.h"
#include <algorithm>

void Course::addStudent(Student* student) {
    enrolledStudents.push_back(student);
}

void Course::removeStudent(Student* student) {
    auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), student);
    if (it != enrolledStudents.end()) {
        enrolledStudents.erase(it);
    }
}

void Course::viewStudents() const {
    for (auto student : enrolledStudents) {
        std::cout << "Name: " << student->getstudentname() << "\tSection: " << student->getsection() << std::endl;
    }
}

std::string Course::getCourseName() const {
    return courseName;
}

int Course::getCourseCode() const {
    return courseCode;
}

Teacher* Course::getTeacher() const {
    return teacher;
}

Room* Course::getAssignedRoom() const {
    return assignedRoom;
}

//Section* Course::getAssignedSection() const {
//    return assignedSection;
//}

Time* Course::getAssignedTime() const {
    return assignedTime;
}

//void Course::setAssignedSection(Section* section) {
//    assignedSection = section;
//}

void Course::setAssignedRoom(Room* room) {
    room = assignedRoom;
}

std::vector<Student*> Course::getEnrolledStudents() const {
    return enrolledStudents;
}
