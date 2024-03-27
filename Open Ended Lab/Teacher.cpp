// Teacher.cpp
#include "Teacher.h"
#include "Course.h"
#include <iostream>

Teacher::Teacher(std::string n, int ID, std::string em) : name(n), teacherID(ID), email(em) {}

void Teacher::assignCourse(Course* course) {
    coursesTaught.push_back(course);
}

void Teacher::removeCourse(Course* course) {
    for (auto c = coursesTaught.begin(); c != coursesTaught.end(); c++) {
        if (*c == course) { // Change assignment operator '=' to comparison operator '=='
            coursesTaught.erase(c);
            break; // Exit the loop after erasing the course
        }
    }
}

void Teacher::viewCourse(Course* course) {
    std::cout << "Courses Taught by " << name << " are:" << std::endl;
    for (auto view = coursesTaught.begin(); view != coursesTaught.end(); view++) {
        std::cout << (*view)->getCourseName() << std::endl;
    }
}
