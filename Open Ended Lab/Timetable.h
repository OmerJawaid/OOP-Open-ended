#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Course.h"
#include "Teacher.h"
#include "Room.h"
#include "Time.h"
#include "Section.h"
#include "Student.h"
#include <fstream>
#include <sstream>
using namespace std;

class Timetable {
private:
   

public:
    map<std::string, std::map<std::string, std::vector<std::tuple<Course*, Time*, Room*>>>> sectionCourses;
    void buildTimetable() {
        // Define rooms
        Room* room1 = new Room("4-17", 50);
        Room* room2 = new Room("4-18", 50);
        Room* room3 = new Room("4-19", 50);
        Room* room4 = new Room("4-01 Lab", 50);
        Room* room5 = new Room("4-02 Lab", 50);

        // Define teachers
        Teacher* teacher1 = new Teacher("Waleed", 201, "Waleed123@gmail.com");
        Teacher* teacher2 = new Teacher("Tamim", 202, "Tamim@gmail.com");
        Teacher* teacher3 = new Teacher("Sadaf", 203, "Sadaf@gmail.com");
        Teacher* teacher4 = new Teacher("Awais", 204, "Awais@gmail.com");

        // Define time slots
        vector<Time*> times = createTimeSlots();

        // Define sections
        Section* section1 = new Section("SE-01");
        Section* section2 = new Section("SE-02");

        // Define students
        Student* student1 = new Student(301, "Ahmad", "ahmad@gmail.com", "2-A");
        section1->addStudent(student1);
        Student* student2 = new Student(302, "Omer", "omer@gmail.com", "2-A");
        section1->addStudent(student2);
        // Define more students if needed...

        // Define courses
        Course* course1 = new Course(403, "OOP Lab", teacher1, room1);
        course1->setAssignedSection(section1);
        course1->addStudent(student1);
        course1->addStudent(student2);

        Course* course2 = new Course(404, "OOP", teacher2, room1);
        course2->setAssignedSection(section1);
        course2->addStudent(student1);
        course2->addStudent(student2);
        // Define more courses if needed...

        // Schedule courses
        scheduleCourse(course1, times, room4);
        scheduleCourse(course2, times, room5);
        // Schedule more courses if needed...
    }

    void scheduleCourse(Course* course, vector<Time*>& times, Room* room) {
        // Shuffle time slots to randomize scheduling
        random_shuffle(times.begin(), times.end());

        // Find an available time slot
        Time* chosenTime = nullptr;
        for (Time* time : times) {
            bool conflict = false;
            for (const auto& day : sectionCourses) {
                for (const auto& sectionPair : day.second) {
                    for (const auto& courseTimeRoomTuple : sectionPair.second) {
                        Time* existingTime = get<1>(courseTimeRoomTuple);
                        if (existingTime->getStartTime() == time->getStartTime() && existingTime->getEndTime() == time->getEndTime()) {
                            conflict = true;
                            break;
                        }
                    }
                    if (conflict) break;
                }
                if (conflict) break;
            }
            if (!conflict) {
                chosenTime = time;
                break;
            }
        }

        if (chosenTime) {
            Section* section = course->getAssignedSection();
            sectionCourses["Monday"][section->getName()].push_back(make_tuple(course, chosenTime, room));
        }
        else {
            cout << "Unable to schedule course: " << course->getCourseName() << endl;
        }
    }

    void teacherTimetable() {
        buildTimetable();

        
        map<Teacher*, vector<tuple<Course*, Time*, Room*>>> teacherCourses;

        
        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            
            for (const auto& sectionPair : day.second) {
            
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Teacher* teacher = get<0>(courseTimeRoomTuple)->getTeacher();
                    teacherCourses[teacher].push_back(courseTimeRoomTuple);
                }
            }

            
            for (const auto& teacherCoursePair : teacherCourses) {
                Teacher* teacher = teacherCoursePair.first;
                vector<tuple<Course*, Time*, Room*>> courses = teacherCoursePair.second;
                /*if (teacher->getName() == "Tamim") {*/
                    cout << "Teacher: " << teacher->getName() << endl;
                    for (const auto& courseTimeRoomTuple : courses) {
                        Course* course = get<0>(courseTimeRoomTuple);
                        Time* time = get<1>(courseTimeRoomTuple);
                        Room* room = get<2>(courseTimeRoomTuple);
                        cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << endl;
                    }
               /* }*/
                cout << endl;
            }
        }
    }
   
    void studentTimetable() {
        buildTimetable();

        
        map<Student*, vector<tuple<Course*, Time*, Room*>>> studentCourses;

        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            for (const auto& sectionPair : day.second) {
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);

                    for (Student* student : course->getEnrolledStudents()) {
                        studentCourses[student].push_back(courseTimeRoomTuple);
                    }
                }
            }

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
            // Build the timetable
            buildTimetable();

            // Iterate over days
            for (const auto& day : sectionCourses) {
                cout << "Day: " << day.first << endl;

                // Iterate over sections for the day
                for (const auto& sectionPair : day.second) {
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



    void writeTimetableToFile(const std::string& filename, const std::string& content) {
        std::ofstream outfile("timetable.txt");
        if (outfile.is_open()) {
            outfile << content;
            outfile.close();
            std::cout << "Timetable written to file: " << "timetable.txt" << std::endl;
        }
        else {
            std::cerr << "Unable to open file: " << "timetable.txt" << std::endl;
        }
    }

    void writeTeacherTimetableToFile() {
        // Build teacher timetable
        stringstream timetableContent;
        // Iterate over days and sections to build timetable content
        for (const auto& day : sectionCourses) {
            for (const auto& sectionPair : day.second) {
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Teacher* teacher = get<0>(courseTimeRoomTuple)->getTeacher();
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);
                    timetableContent << "Teacher: " << teacher->getName() << ", Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << std::endl;
                }
            }
        }
        // Write content to file
        writeTimetableToFile("teacher_timetable.txt", timetableContent.str());
    }

    void writeStudentTimetableToFile() {
        // Build student timetable
        std::stringstream timetableContent;
        // Iterate over days and sections to build timetable content
        for (const auto& day : sectionCourses) {
            for (const auto& sectionPair : day.second) {
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Course* course = get<0>(courseTimeRoomTuple);
                    Time* time = get<1>(courseTimeRoomTuple);
                    Room* room = get<2>(courseTimeRoomTuple);
                    for (Student* student : course->getEnrolledStudents()) {
                        timetableContent << "Student: " << student->getstudentname() << ", Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << std::endl;
                    }
                }
            }
        }
        // Write content to file
        writeTimetableToFile("student_timetable.txt", timetableContent.str());
    }







};
