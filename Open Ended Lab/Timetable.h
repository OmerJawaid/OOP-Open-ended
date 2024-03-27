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

        // Create courses and assign sections
        Course* course1 = new Course(403, "OOP", teacher1, room1);
        course1->setAssignedSection(section1);
        Course* course2 = new Course(404, "DS", teacher2, room1);
        course2->setAssignedSection(section2);
        Course* course3 = new Course(405, "Algorithms", teacher3, room1);
        course3->setAssignedSection(section1);

        // Populate timetable with courses, times, and rooms
        sectionCourses["Monday"][section1->getName()].push_back(make_tuple(course1, times[0], room1));
        sectionCourses["Monday"][section2->getName()].push_back(make_tuple(course2, times[1], room3));
        sectionCourses["Tuesday"][section1->getName()].push_back(make_tuple(course3, times[0], room2));
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
};
