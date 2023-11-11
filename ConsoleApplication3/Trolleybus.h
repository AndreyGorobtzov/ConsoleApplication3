#pragma once
#include <string>
using namespace std;

template<class T>
T input(string s = "")
{
	T var;
	cout << s; cin >> var;
	return var;
}

class Trolleybus
{
public:
	int num_of_bus;
	string surname_of_driver;
	int num_of_track;
	friend ostream& operator<< (ostream& os, const Trolleybus& tb)
	{
		return os
			<< "Номер троллейбуса: " << tb.num_of_bus << endl
			<< "Фамилия водителя: " << tb.surname_of_driver << endl
			<< "Номер маршрута: " << tb.num_of_track << endl;
	}
	friend istream& operator>> (istream& is, Trolleybus& tb)
	{
		is >> tb.num_of_bus;
		is >> tb.surname_of_driver;
		is >> tb.num_of_track;
		return is;
	}
};

class Park
{
private:
	ListNode<Trolleybus> park;
	ListNode<Trolleybus> track;
public:
	void AddToPark(Trolleybus t)
	{
		park.AddHead(t);
	}
	void AddToTrack(Trolleybus t)
	{
		track.AddHead(t);
	}
	void GoToPark(int pos)
	{
		try {
			park.AddHead(track[pos]);
			track.DeleteNodePos(pos);
		}
		catch (const char* error_message)
		{
			cout << error_message << endl;
		}
	}
	void GoToTrack(int pos)
	{
		try {
		track.AddHead(park[pos]);
		park.DeleteNodePos(pos);
		}
		catch (const char* error_message)
		{
			cout << "Ошибка!!! " << error_message << endl;
		}
	}
	void ParkInfo()
	{
		park.ListHead();
	}
	void TrackInfo()
	{
		track.ListHead();
	}
};