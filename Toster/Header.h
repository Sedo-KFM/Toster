#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Time
{
	int hours;
	int minutes;
};

class Poster
{
	string name;
	int hallNum;
	int placesAmount;
	int ticketCost;
	Time beginTime;
public:
	Poster()
	{
		name = "Undefined";
		hallNum = 0;
		placesAmount = 0;
		ticketCost = 0;
		beginTime = { 0, 0 };
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setHallNum(int hallNum) {
		this->hallNum = hallNum;
	}
	int getHallNum() {
		return hallNum;
	}
	void setPlacesAmount(int placesAmount) {
		this->placesAmount = placesAmount;
	}
	int getPlacesAmount() {
		return placesAmount;
	}
	void setTicketCost(int ticketCost) {
		this->ticketCost = ticketCost;
	}
	int getTicketCost() {
		return ticketCost;
	}
	void setBeginTime(Time beginTime) {
		this->beginTime = beginTime;
	}
	Time getBeginTime() {
		return beginTime;
	}
	void read(istream& is)
	{
		name = readfor(is, " ");
		hallNum = atoi(readfor(is, " ").c_str());
		placesAmount = atoi(readfor(is, " ").c_str());
		ticketCost = atoi(readfor(is, " ").c_str());
		beginTime.hours = atoi(readfor(is, ":").c_str());
		string buf = "\n";
		buf.push_back(EOF);
		beginTime.minutes = atoi(readfor(is, buf).c_str());
	}
	void write(ostream& os)
	{
		char buf[64];
		os.write(name.c_str(), name.size());
		os.put(' ');
		_itoa_s(hallNum, buf, 10), intsize(hallNum);
		buf[63] = '\0';
		os.write(buf, strlen(buf));
		os.put(' ');
		_itoa_s(placesAmount, buf, 10), intsize(placesAmount);
		buf[63] = '\0';
		os.write(buf, strlen(buf));
		os.put(' ');
		_itoa_s(ticketCost, buf, 10), intsize(ticketCost);
		buf[63] = '\0';
		os.write(buf, strlen(buf));
		os.put(' ');
		_itoa_s(beginTime.hours, buf, 10), intsize(beginTime.hours);
		buf[63] = '\0';
		os.write(buf, strlen(buf));
		os.put(':');
		_itoa_s(beginTime.minutes, buf, 10), intsize(beginTime.minutes);
		buf[63] = '\0';
		os.write(buf, strlen(buf));
		os.put('\n');
	}
private:
	string readfor(istream& is, string stop)
	{
		string input = "";
		char peek = is.peek();
		while (!(stop.find(is.peek()) + 1))
		{
			input += is.get();
		}
		char space = is.get();
		return input;
	}
	int intsize(int input)
	{
		int count = 1;
		while (input)
		{
			input /= 10;
			if (input)
			{
				count += 1;
			}
		}
		return count;
	}
};