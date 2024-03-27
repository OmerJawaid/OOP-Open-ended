#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Course;

class Room {
private:
    string roomNumber;
    vector<string> total_rooms;
    vector<string> rooms_available;
    int capacity; 
	int count = 0;
    vector<string> total_labs;
    vector<string> available_labs;

public:
    Room(); Room(string r_no,int cap) : roomNumber(r_no),capacity(cap) {}
    void displayRooms_available();
    void assignRoom(Course* course);
    bool checkAvailabitiy(string room_number);
    void update_room(Course* course);
    void bookRoom();
    string getRoomNumber() const {
        return roomNumber;
    }
    int getcapacity() const { return capacity; }
};
