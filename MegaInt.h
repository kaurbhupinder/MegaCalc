#ifndef MEGAINT_H
#define MEGAINT_H

#include<iostream>
#include<string>
#include <deque>
using namespace std;

class MegaInt
{
public:
	deque<char> mega_int;
	MegaInt();
	MegaInt add(MegaInt, MegaInt);
	MegaInt subtract(MegaInt, MegaInt);
	MegaInt multiplication(MegaInt, MegaInt);
	MegaInt division(MegaInt, MegaInt);
	MegaInt modulus(MegaInt, MegaInt);
	MegaInt clear(MegaInt);
	MegaInt reset(MegaInt);
	MegaInt negate(MegaInt);

	MegaInt operator*(MegaInt& obj);
	MegaInt operator+(MegaInt);
	MegaInt operator-(MegaInt);
	bool operator<=(MegaInt);
	void operator++();
	MegaInt operator=(MegaInt);
	friend ostream & operator<<(ostream & out, MegaInt & obj);
	bool operator>=(MegaInt);
};



#endif#program once
#pragma once
