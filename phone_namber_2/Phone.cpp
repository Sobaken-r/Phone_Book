#include "Phone.h"
#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;

void Phone::setID(int uid)
{
	id = uid;
}

void Phone::setName(const char* uname)
{
	delete[]name;
	name = new char[strlen(uname) + 1];
	strcpy_s(name, strlen(uname) + 1, uname);
}

void Phone::setHomeNumber(const char* uhome_number)
{
	strcpy_s(home_number, 12 + 1, uhome_number);
}

void Phone::setWorkNumber(const char* uwork_number)
{
	strcpy_s(work_number, 12 + 1, uwork_number);
}

void Phone::setMobileNumber(const char* umobile_number)
{
	strcpy_s(mobile_number, 12 + 1, umobile_number);
}

void Phone::setInfo(const char* uinfo)
{
	delete[]info;
	info = new char[strlen(uinfo) + 1];
	strcpy_s(info, strlen(uinfo) + 1, uinfo);
}

const char* Phone::getName() const
{
	return name ? name : "Name";
}

const char* Phone::getHomeNumber() const
{
	return home_number;
}

const char* Phone::getWorkNumber() const
{
	return work_number;
}

const char* Phone::getMobileNumber() const
{
	return mobile_number;
}

const char* Phone::getInfo() const
{
	return info ? info : "No info";
}

Phone::Phone() : name{ nullptr }, home_number{ NULL }, work_number{ NULL }, mobile_number{ NULL }, info{ nullptr } {};
Phone::Phone(const char* uname, const char* uhome_number, const char* uwork_number, const char* umobile_number, const char* uinfo)
{
	setName(uname);
	setHomeNumber(uhome_number);
	setWorkNumber(uwork_number);
	setMobileNumber(umobile_number);
	setInfo(uinfo);
}

void Phone::addUser()
{
	char ifinfo;
	char* name = new char{};
	char* infoName = new char{};
	char number[12];
	cout << "ID: " << id << endl;
	cout << "Введите имя пользователя: ";
	cin >> name;
	setName(name);
	cout << "Введите домашний телефон: ";
	cin >> number;
	setHomeNumber(number);
	cout << "Введите рабочий телефон: ";
	cin >> number;
	setWorkNumber(number);
	cout << "Введите мобильный телефон: ";
	cin >> number;
	setMobileNumber(number);
	cout << "Добавить информацию?(Y/N)";
	cin >> ifinfo;
	if(ifinfo == 'y' || ifinfo == 'Y')
	{
		cout << "Информация о пользователе: ";
		cin >> infoName;
		setInfo(infoName);
	}
	else
	{
		setInfo("No Info");
	}
}

void Phone::removeUser()
{
	setName("######");
	setHomeNumber("###########");
	setWorkNumber("###########");
	setMobileNumber("###########");
	setInfo("deleted");
}

void Phone::Print()
{
	cout << "-------------------------------------------" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Home number: ";
	for (int i = 0; i < 12; i++)
	{
		if (i == 3 || i == 6 || i == 8)
		{
			cout << home_number[i] << "-";
		}
		else
		{
			cout << home_number[i];
		}
	}
	cout << endl;
	cout << "Work number: ";
	for (int i = 0; i < 12; i++)
	{
		if (i == 3 || i == 6 || i == 8)
		{
			cout << work_number[i] << "-";
		}
		else
		{
			cout << work_number[i];
		}
	}
	cout << endl;
	cout << "Mobile number: ";
	for (int i = 0; i < 12; i++)
	{
		if (i == 3 || i == 6 || i == 8)
		{
			cout << mobile_number[i] << "-";
		}
		else
		{
			cout << mobile_number[i];
		}
	}
	cout << endl;
	cout << "Info: " << info << endl;
	cout << "-------------------------------------------" << endl << endl;
}

Phone::~Phone()
{
	delete[]name;
	delete[]info;
}
