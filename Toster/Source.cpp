#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Header.h"

using namespace std;

struct PosterDynamicArr
{
	Poster* data;
	int length;
	PosterDynamicArr()
	{
		data = nullptr;
		length = 0;
	}
	~PosterDynamicArr()
	{
		delete[] data;
	}
	void add(Poster input)
	{
		Poster* newdata = new Poster[++length];
		for (int i = 0; i < length - 1; i++)
		{
			newdata[i] = data[i];
		}
		newdata[length - 1] = input;
		delete[] data;
		data = newdata;
	}
};

int main()
{
	ifstream ifs("C:\\Temp\\input.txt");
	ofstream ofs("C:\\Temp\\output.txt");
	Poster poster;
	PosterDynamicArr pda;
	while (ifs.peek() != EOF)
	{
		Poster poster;
		poster.read(ifs);
		pda.add(poster);
	}
	cout
		<< left << setw(10) << "Name" << ' '
		<< setw(9) << "Hall Num" << ' '
		<< setw(14) << "Places Amount" << ' '
		<< setw(12) << "Ticket Cost" << ' '
		<< setw(11) << "Begin Time" << endl;
	for (int i = 0; i < pda.length; i++)
	{
		cout
			<< left << setw(10) << pda.data[i].getName() << ' '
			<< setw(9) << pda.data[i].getHallNum() << ' '
			<< setw(14) << pda.data[i].getPlacesAmount() << ' '
			<< setw(12) << pda.data[i].getTicketCost() << ' '
			<< right << setw(2) << pda.data[i].getBeginTime().hours << ':' << left
			<< (pda.data[i].getBeginTime().minutes < 10 ? "0" : "")
			<< pda.data[i].getBeginTime().minutes << endl;
	}
	cout << endl << "Input the name of a film" << endl;
	string filmName;
	cin >> filmName;
	int filmCounter = 0;
	for (int i = 0; i < pda.length; i++)
	{
		if (filmName == pda.data[i].getName())
		{
			pda.data[i].write(ofs);
			filmCounter++;
		}
	}
	if (filmCounter)
	{
		cout << endl << "Film schedule has successfully output in output.txt" << endl;
	}
	else
	{
		cout << endl << "There is no films with this name" << endl;
	}
	ifs.close();
	ofs.close();
}