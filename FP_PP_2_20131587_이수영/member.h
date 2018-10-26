#include <iostream>
#include <string>
#include "delim.h"

#define LEN_MIL 11
#define STDMAXBUF 256

using namespace std;

class Member {

private:
	string ID;
	string Password;
	string Name;
	string	PhoneNumber;
	string Address;
	char Mileage[11];	

public:
	Member();
	Member(const string newID);
	Member(const Member &s);

	Member & operator = (const Member &s);
	bool operator == (const Member &s);
	bool operator != (const Member &s);

	friend istream & operator >> (istream &is, Member &s);
	friend ostream & operator << (ostream &os, Member &s);

	void setID(const string newID) { ID = newID; }
	void setPassword(const string newPassword) { Password = newPassword; }
	void setName(const string newName) { Name = newName; }
	void setPhoneNumber(const string newPhoneNumber) { PhoneNumber = newPhoneNumber; }
	void setAddress(const string newAddress) { Address = newAddress; }
	void setMileage(const char * newMileage) { memcpy(Mileage, newMileage, LEN_MIL); }

	string getID() {
		return ID;
	}
	string getPassword() {
		return Password;
	}
	string getName() {
		return Name;
	}
	string getPhoneNumber() {
		return PhoneNumber;
	}
	string getAddress() {
		return Address;
	}
	char* getMileage() {
		return Mileage;
	}
	int getLength() {
		return ID.size() + Password.size() + Name.size() + PhoneNumber.size() + Address.size() + strlen(Mileage);
	}

	bool Pack(IOBuffer &Buffer) const;
	bool Unpack(IOBuffer &);

};


istream & operator >> (istream &is, Member &s);
ostream & operator << (ostream &os, Member &s);