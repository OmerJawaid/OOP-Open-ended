#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Room.h"
#include "Timetable.h"
#include "Section.h"
#include "Time.h"
#include <string>
#include <cstdlib>
using namespace std;
const string DATABASE_FILE = "users.txt";
bool login();
void signup();
int main() {
	int choice;
	bool loggedIn = false;

	do {
		cout << "Welcome to the program!" << endl;
		cout << "1. Signup" << endl;
		cout << "2. Login" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			signup();
			system("CLS");
			break;
		case 2:
			loggedIn = login();
			if (loggedIn) {
				cout << "Login Successful" << endl;
			}
			else {
				cout << "Login Failed" << endl;
			}
			break;
		default:
			cout << "Invalid choice! Please enter 1 or 2." << endl;
		}
	} while (!loggedIn);
	
	Timetable timetable1;
	string generationchoice;
	
	cout << "Welcome to University Timetable System" << endl;
	do {
		cout << "----------------------------------------" << endl
			<< "How would you like to generate timetable: " << endl
			<< "1) Teacher wise timetable" << endl
			<< "2) Section wise timetable" << endl
			<< "3) Student wise time table" << endl
			<< "4) Room wise and Lab wise timetable" << endl
			<< "5) By queries?" << endl
			<< "6) Exit!" << endl
			<< "Enter your choice in numbers: ";
		cin >> generationchoice;

		if (generationchoice == "1")
		{
			timetable1.teacherTimetable();
		}
		else if (generationchoice == "2")
		{
			timetable1.sectionTimetable();
		}
		else if (generationchoice == "3")
		{
			timetable1.studentTimetable();
		}
		else if (generationchoice == "4")
		{
			timetable1.roomTimetable();
		}
		else if (generationchoice == "5")
		{
			string query;
			do {
				cout << "Who is teaching on this day and time?" << endl
					<< "What is timetable for this day?" << endl
					<< "Enter your query: ";
				cin >> query;
				if (query == "1")
				{
					string day, time;
					cout << "Enter day and time: ";
					cin >> day >> time;
					timetable1.whoIsTeachingAt(day, time);
				}
				else if (query == "2")
				{
					string day;
					cout << "Enter day: ";
					cin >> day;
					timetable1.getTimeTableForDay(day);

				}
				else
					cout << "Invalid query! Try Again" << endl;
			} while (query != "1" && query != "2");
		}
		else if (generationchoice == "6")
		{
			break;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}

	} while (generationchoice != "6");
	timetable1.teacherTimetable(); // Print teacher timetable
	timetable1.studentTimetable(); // Print student timetable
	timetable1.writeTeacherTimetableToFile(); // Write teacher timetable to file
	timetable1.writeStudentTimetableToFile();

	system("pause");
	return 0;
}
void signup() {
	cout << "---------SIGNUP----------" << endl;
	string username, password;
	cout << "Enter User Name: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;


	ofstream outfile(DATABASE_FILE, ios::app);
	if (outfile.is_open()) {
		outfile << username << " " << password << endl;
		cout << "Signup Successful!" << endl;
		outfile.close();
	}
	else {
		cerr << "Error: Unable to open database file!" << endl;
	}
}


bool login() {
	cout << "------------LOGIN------------" << endl;
	string username, password;
	cout << "Enter User Name: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream infile(DATABASE_FILE);
	if (infile.is_open()) {
		string storedUsername, storedPassword;
		while (infile >> storedUsername >> storedPassword) {
			if (username == storedUsername && password == storedPassword) {
				infile.close();
				return true;
			}
		}
		infile.close();
	}
	else {
		cerr << "Error: Unable to open database file!" << endl;
	}
	return false;
}