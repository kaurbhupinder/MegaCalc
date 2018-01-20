#ifndef MEGACALC_H
#define MEGACALC_H

#include<iostream>
#include<string>
#include <deque>
#include "MegaInt.h"
using namespace std;

class MegaCalc
{
public:
	void run();
	MegaCalc();
	string trim(string& str);
	void parse(MegaInt);
	void display(MegaInt);

	MegaInt factorial(MegaInt);
	MegaInt hailstone(MegaInt);
};

#endif
