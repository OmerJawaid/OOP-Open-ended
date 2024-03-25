#pragma once
class Time
{
private:
	string startTime, endTime;
public:
	Time(string start, string end) :startTime(start), endTime(end) {};
	string getStartTime() { return startTime; }
	string getEndTime() { return endTime; }
};

