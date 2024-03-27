#pragma once
#include <string>
#include <vector>
#include <algorithm> // Include the algorithm header for std::find
#include "Student.h"
#include"Course.h"// Include the header where Student class is declared
class Student;
class Course;
using namespace std;
class Section {
private:
    std::string name;
    std::vector<Student*> students;
    /*vector<Course*> courses;*/
public:
    Section(const string& name) : name(name){};

    const std::string& getName() const {
        return name;
    }

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(Student* student) {
        auto it = find(students.begin(), students.end(), student);
        if (it != students.end()) {
            students.erase(it);
        }
    }

    const std::vector<Student*>& getStudents() const {
        return students;
    }
};
