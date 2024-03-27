#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Course.h"
#include "Teacher.h"
#include "Room.h"
#include "Time.h"
#include "Section.h"
#include"Room.h"
using namespace std;

class Timetable {
private:
    map<std::string, std::map<std::string, std::vector<std::tuple<Course*, Time*, Room*>>>> sectionCourses;

public:
    void buildTimetable() {
        Room* room1 = new Room("4-01", 50);
        Room* room2 = new Room("4-02", 50);
        Room* room3 = new Room("4-03", 50);
        Room* room4 = new Room("4-04", 50);

        Teacher* teacher1 = new Teacher("Waleed", 201, "Waleed123@gmail.com");
        Teacher* teacher2 = new Teacher("Tamim", 200, "Tamim@gmail.com");
        Teacher* teacher3 = new Teacher("Ds wali mam", 150, "ds@gmail.com");

        vector<Time*> times = createTimeSlots();

        // Create sections
        Section* section1 = new Section("SE-01");
        Section* section2 = new Section("SE-02");

        // Create students
        Student* student1 = new Student(301, "John", "john@example.com", "2-A");
        Student* student2 = new Student(302, "Alice", "alice@example.com", "2-B");

        // Create courses and assign sections
        Course* course1 = new Course(403, "OOP", teacher1, room1);
        course1->setAssignedSection(section1);
        course1->addStudent(student1);  // Enroll student1 in course1
        Course* course2 = new Course(404, "DS", teacher2, room1);
        course2->setAssignedSection(section2);
        course2->addStudent(student2);  // Enroll student2 in course2
        Course* course3 = new Course(405, "Algorithms", teacher3, room1);
        course3->setAssignedSection(section1);
        course3->addStudent(student1);  // Enroll student1 in course3

        // Populate timetable with courses, times, and rooms
        sectionCourses["Monday"][section1->getName()].push_back(make_tuple(course1, times[0], room1));
        sectionCourses["Monday"][section2->getName()].push_back(make_tuple(course2, times[1], room3));
        sectionCourses["Tuesday"][section1->getName()].push_back(make_tuple(course3, times[0], room2));
    }
    vector<Time*> createTimeSlots() {
        vector<Time*> times;
        times.push_back(new Time("8:30", "9:30"));
        times.push_back(new Time("9:30", "10:30"));
        times.push_back(new Time("10:30", "11:30"));
        times.push_back(new Time("11:30", "12:30"));
        times.push_back(new Time("12:30", "1:30"));
        times.push_back(new Time("1:30", "2:30"));
        return times;
    }

    void teacherTimetable() {
        buildTimetable();

        // Map of teacher -> courses
        map<Teacher*, vector<tuple<Course*, Time*, Room*>>> teacherCourses;

        // Iterate over days
        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            // Iterate over sections for the day
            for (const auto& sectionPair : day.second) {
                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Teacher* teacher = get<0>(courseTimeRoomTuple)->getTeacher();
                    teacherCourses[teacher].push_back(courseTimeRoomTuple);
                }
            }

            // Display teacher timetable for the current day
            for (const auto& teacherCoursePair : teacherCourses) {
                Teacher* teacher = teacherCoursePair.first;
                vector<tuple<Course*, Time*, Room*>> courses = teacherCoursePair.second;
                if (teacher->getName() == "Tamim") {
                    cout << "Teacher: " << teacher->getName() << endl;
                    for (const auto& courseTimeRoomTuple : courses) {
                        Course* course = get<0>(courseTimeRoomTuple);
                        Time* time = get<1>(courseTimeRoomTuple);
                        Room* room = get<2>(courseTimeRoomTuple);
                        cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << endl;
                    }
                }
                cout << endl;
            }
        }
    }
   
    void studentTimetable() {
        buildTimetable();

        // Map of student -> courses
        map<Student*, vector<tuple<Course*, Time*, Room*>>> studentCourses;

        // Iterate over days
        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            // Iterate over sections for the day
            for (const auto& sectionPair : day.second) {
                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);

                    // Iterate over enrolled students for the course
                    for (Student* student : course->getEnrolledStudents()) {
                        studentCourses[student].push_back(courseTimeRoomTuple);
                    }
                }
            }

            // Display student timetable for the current day
            for (const auto& studentCoursePair : studentCourses) {
                Student* student = studentCoursePair.first;
                vector<tuple<Course*, Time*, Room*>> courses = studentCoursePair.second;
                cout << "Student: " << student->getstudentname() << endl;
                for (const auto& courseTimeRoomTuple : courses) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);
                    cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << endl;
                }
                cout << endl;
            }
        }
    }



    void sectionTimetable() {
        //buildTimetable();

        //// Iterate over days
        //for (const auto& day : sectionCourses) {
        //    cout << "Day: " << day.first << endl;

        //    // Iterate over sections for the day
        //    for (const auto& sectionPair : day.second) {
        //        cout << "Section: " << sectionPair.first << endl;

        //        // Check if there are any courses for this section
        //        if (sectionPair.second.empty()) {
        //            cout << "No courses for this section." << endl;
        //        }
        //        else {
        //            // Iterate over courses for the section
        //            for (const auto& courseTimePair : sectionPair.second) {
        //                cout << "Course: " << courseTimePair.first->getCourseName();
        //                cout << ", Time: " << courseTimePair.second->getStartTime() << " - " << courseTimePair.second->getEndTime() << endl;
        //            }
        //        }
        //    }
        //}
    }

    
    void roomTimetable() {
        // Build the timetable
        buildTimetable();

        // Iterate over days
        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            // Create a map to store courses by room
            map<Room*, vector<tuple<Course*, Time*, Section*>>> roomCourses;

            // Iterate over sections for the day
            for (const auto& sectionPair : day.second) {
                // Get the section name
                const string& sectionName = sectionPair.first;

                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);

                    // Find the section object from its name
                    Section* section = nullptr;
                    for (const auto& sectionCoursesPair : sectionCourses[day.first]) {
                        if (sectionCoursesPair.first == sectionName) {
                            // Iterate over the tuples to find the section
                            for (const auto& tuple : sectionCoursesPair.second) {
                                Course* course = std::get<0>(tuple);
                                // Assuming each tuple contains the same section, get the section from any tuple
                                section = course->getAssignedSection();
                                break;
                            }
                            break;
                        }
                    }

                    // Add the course to the corresponding room
                    roomCourses[room].push_back(make_tuple(course, time, section));
                }
            }

            // Display room-wise timetable for the current day
            for (const auto& roomCoursePair : roomCourses) {
                Room* room = roomCoursePair.first;
                vector<tuple<Course*, Time*, Section*>> courses = roomCoursePair.second;

                cout << "Room: " << room->getRoomNumber() << endl;
                for (const auto& courseTimeSectionTuple : courses) {
                    Course* course = get<0>(courseTimeSectionTuple);
                    Time* time = get<1>(courseTimeSectionTuple);
                    Section* section = get<2>(courseTimeSectionTuple);

                    cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Section: " << section->getName() << endl;
                }
                cout << "-----------------------------" << endl;
            }
        }
    }

    void whoIsTeachingAt(string day, string time) {
        buildTimetable();
        cout << "Courses and Details at " << time << " on " << day << ":" << endl;

        // Check if the provided day exists in the sectionCourses map
        if (sectionCourses.find(day) != sectionCourses.end()) {
            // Iterate over sections for the given day
            for (const auto& sectionPair : sectionCourses[day]) {
                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Time* courseTime = get<1>(courseTimeRoomTuple);
                    // Check if the course starts at the provided time
                    if (courseTime->getStartTime() == time) {
                        Course* course = get<0>(courseTimeRoomTuple);
                        Room* room = get<2>(courseTimeRoomTuple);
                        Teacher* teacher = course->getTeacher();

                        cout << "Course: " << course->getCourseName() << endl;
                        cout << "Teacher: " << teacher->getName() << endl;
                        cout << "Room: " << room->getRoomNumber() << endl;
                        cout << "Section: " << sectionPair.first << endl;
                        // Add more details as needed
                        cout << "Time: " << courseTime->getStartTime() << " - " << courseTime->getEndTime() << endl;
                        cout << endl;
                    }
                }
            }
        }
        else {
            cout << "No courses scheduled for " << day << endl;
        }
    }



    void getTimeTableForDay(string day) {
        buildTimetable();
        cout << "Timetable for " << day << ":" << endl;

        // Check if the provided day exists in the sectionCourses map
        if (sectionCourses.find(day) != sectionCourses.end()) {
            // Iterate over sections for the given day
            for (const auto& sectionPair : sectionCourses[day]) {
                string sectionName = sectionPair.first;
                cout << "Section: " << sectionName << endl;

                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);
                    cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << endl;
                }
                cout << endl;
            }
        }
        else {
            cout << "No courses scheduled for " << day << endl;
        }
    }

};
