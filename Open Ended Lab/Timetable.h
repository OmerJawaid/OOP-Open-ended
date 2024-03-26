#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Course.h"
#include "Teacher.h"
#include "Room.h"
#include "Time.h"
using namespace std;

class Timetable {
private:
    map<string, vector<pair<Course*, Time*>>> courses;

public:
    void buildTimetable() {
        Room* room1 = new Room("4-01", 50);
        Teacher* teacher1 = new Teacher("Waleed", 201, "Waleed123@gmail.com");
        Teacher* teacher2 = new Teacher("Tamim", 200, "Tamim@gmail.com");
        Teacher* teacher3 = new Teacher("Ds wali mam", 150, "ds@gmail.com");

        vector<Time*> times = createTimeSlots();
        courses["Monday"].push_back(make_pair(new Course(403, "OOP", teacher1, room1), times[0]));
        courses["Monday"].push_back(make_pair(new Course(404, "DS", teacher2, room1), times[1]));        
        courses["Tuesday"].push_back(make_pair(new Course(405, "Algorithms", teacher3, room1), times[0]));
    }

    void teacherTimetable() {
        buildTimetable();
        for (const auto& day : courses) {
            cout << "Day: " << day.first << endl;
            for (const auto& courseTimePair : day.second) {
                cout << "Teacher: " << courseTimePair.first->getteacher()->getName() << ", Course: " << courseTimePair.first->getcoursename();
                cout << ", Time: " << courseTimePair.second->getStartTime() << " - " << courseTimePair.second->getEndTime() << endl;
            }
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

};