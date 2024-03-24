#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Course.h"
using namespace std;

class Room
{
private:
	int roomNumber;
	vector<int>total_rooms = {417,418,419};
	vector<int>rooms_available = {417,418,419};
	int capacity, count = 0;
	vector<int>total_labs = {401,402};
	vector<int> available_labs = {401,402};
public:
    void displayRooms_available();
	void assignRoom(Course* course);
bool checkAvailabitiy(int room_number);
void bookRoom();
	int getRoomNumber() const {
		return roomNumber;
	}
	int getcapacity() const { return capacity; }
};
void update_room(Course* course);

