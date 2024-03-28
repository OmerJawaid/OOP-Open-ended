// Course.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Teacher.h"
#include "Room.h"
#include "Section.h"
#include "Time.h" 

class Student; // Forward declaration of Student class

class Course {
private:
    int courseCode;
    std::string courseName;
    Room* assignedRoom;
    Teacher* teacher;
    Section* assignedSection;
    Time* assignedTime;


public:
    std::vector<Student*> enrolledStudents;

    Course(int courseCode, const std::string& courseName, Teacher* teacher, Room* assignedRoom)
        : courseCode(courseCode), courseName(courseName), teacher(teacher), assignedRoom(assignedRoom), assignedSection(nullptr), assignedTime(nullptr) {}

    void addStudent(Student* student);
    void removeStudent(Student* student);
    void viewStudents() const;

    std::string getCourseName() const;
    int getCourseCode() const;
    Teacher* getTeacher() const;
    Room* getAssignedRoom() const;
    /*Section* getAssignedSection() const;*/
    void setAssignedSection(Section* section) {
        assignedSection = section;
    }

    Section* getAssignedSection() const {
        return assignedSection;
    }
    Time* getAssignedTime() const;
    /*void setAssignedSection(Section* section);*/
     void setAssignedRoom(Room* room);

    std::vector<Student*> getEnrolledStudents() const;
};
