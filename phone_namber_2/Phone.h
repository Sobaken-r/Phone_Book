#pragma once

class Phone
{
	int id;
	char* name;
	char home_number[12 + 1];
	char work_number[12 + 1];
	char mobile_number[12 + 1];
	char* info;

public:

	void setID(int uid);
	void setName(const char* uname);
	void setHomeNumber(const char* uhome_number);
	void setWorkNumber(const char* uwork_number);
	void setMobileNumber(const char* umobile_number);
	void setInfo(const char* uinfo);

	const char* getName() const;
	const char* getHomeNumber() const;
	const char* getWorkNumber() const;
	const char* getMobileNumber() const;
	const char* getInfo() const;

	Phone();
	Phone(const char* uname, const char* uhome_number, const char* uwork_number, const char* umobile_number, const char* uinfo);

	void addUser();
	void removeUser();

	void Print();
	~Phone();
};

