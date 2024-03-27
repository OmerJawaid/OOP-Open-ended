#include"Room.h"
#include "Course.h" // Include Course.h for Course class

Room::Room(string r_no,int cap) : roomNumber(r_no),capacity(cap) {
    total_rooms = { "417","418","419" }; // Initialize total rooms
    rooms_available = total_rooms; // Initially all rooms are available
    total_labs = { "401","402" }; // Initialize total labs
    available_labs = total_labs; // Initially all labs are available
}

void Room::displayRooms_available() {
    cout << "Rooms available: " << endl;
    for (int i = 0; i < rooms_available.size(); i++) {
        cout << rooms_available[i] << endl;
    }
}

void Room::assignRoom(Course* course) {
    bool check = false;
    do {
        cout << "Enter room number: ";
        cin >> roomNumber;
        check = checkAvailabitiy(roomNumber);
        if (check) {
            course->setAssignedRoom(this); // Passing the Room pointer to Course
            // Remove the assigned room from available rooms
            rooms_available.erase(remove(rooms_available.begin(), rooms_available.end(), roomNumber), rooms_available.end());
        }
        else {
            cout << "Room not available" << endl;
        }
    } while (!check);
}
    Room* assignedRoom; // Declare the variable "assignedRoom" in the Room class

    bool Room::checkAvailabitiy(string room_number) {
        for (int i = 0; i < rooms_available.size(); i++) {
            if (rooms_available[i] == room_number) {
                return true;
            }
        }
        return false;
    }

void Room::update_room(Course* course) {
    int up_room;
    cout << "Enter room number that you want to update = ";
    cin >> up_room;
    auto it = find(rooms_available.begin(), rooms_available.end(), up_room);
    if (it != rooms_available.end()) {
        course->setAssignedRoom(this); // Passing the Room pointer to Course
    }
    else {
        cout << "Room Number doesn't exist. Try Again!" << endl;
    }
}

void Room::bookRoom() {
    // Implementation for booking a room goes here if needed.
}
