#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Course.h"
using namespace std;

class Room
{
private:
	string roomNumber;
	int capacity;
public:
	Room(string number, int cap) : roomNumber(number), capacity(cap) {
		cout << "Room constructor has been called." << endl;
	};
	void checkAvailabitiy() {};
	void bookRoom() {};
	string getRoomNumber() const {
		return roomNumber;
	}
	int getcapacity() const { return capacity; }
};
