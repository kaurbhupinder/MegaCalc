#include "MegaCalc.h"
#include "MegaInt.h"
#include <iostream>
#include<string>
using namespace std;
#include <sstream>
#include <algorithm>


//Initialize the Accumulator
void MegaCalc::run()
{

	MegaInt accumulator;
	accumulator.mega_int.push_back('+');
	accumulator.mega_int.push_back('0');

	cout << "Welcome to MegaCalculator" << endl;
	cout << "*************************" << endl;
	cout << endl;

	cout << "Accumulator : ";
	for (int i = 0;i < accumulator.mega_int.size();i++)
	{
		cout << accumulator.mega_int[i];
	}
	cout << endl;
	parse(accumulator);
}
//Read the input from user
void MegaCalc::parse(MegaInt accumulator)
{
	while (cin)
	{
		MegaInt input;
		MegaCalc output;
		cout << "Enter input:";
		string usercommand;
		getline(cin, usercommand);
		string newcommand = trim(usercommand);

		for (int i = 0;i < newcommand.length();i++)
		{

			input.mega_int.push_back(newcommand[i]);

		}

		if (input.mega_int[0] == '+')
		{
			accumulator = input.add(accumulator, input);
			display(accumulator);

		}
		else if (input.mega_int[0] == '-')
		{
			accumulator = input.subtract(accumulator, input);
			display(accumulator);
		}

		else if (input.mega_int[0] == '/')
		{
			accumulator = input.division(accumulator, input);
			display(accumulator);
		}
		else if (input.mega_int[0] == '%')
		{
			accumulator = input.modulus(accumulator, input);
			display(accumulator);
		}

		else if (input.mega_int[0] == '*')
		{
			accumulator = input.multiplication(input,accumulator);
			display(accumulator);
		}
		else if (input.mega_int[0] == 'f')
		{
			input = factorial(accumulator);
			display(accumulator);
		}
		else if (input.mega_int[0] == 'c')
		{
			accumulator = input.clear(accumulator);
			display(accumulator);
		}
		else if (input.mega_int[0] == '=')
		{
			accumulator = input.reset(input);
			display(accumulator);
		}
		else if (input.mega_int[0] == 'n')
		{
			accumulator = input.negate(accumulator);
		
			display(accumulator);
		}
		else if (input.mega_int[0] == 'h')
		{
			input = hailstone(accumulator);
			int mycount = 0;
			while (!(input.mega_int.size() == 2 && input.mega_int[1] == '1'))
			{
				++mycount;
				input = hailstone(input);
				cout << " > " << input << endl;

			}
			cout << "The length of the Hailstone is : " << mycount + 2 << endl;
			cout << endl;
			display(accumulator);
		}
		else if (input.mega_int[0] == 'q')
		{
			break;
		}
		else
		{
			cout << "ENTER A VALID INPUT :" << endl;
		}
	}
}

MegaCalc::MegaCalc()
{

}

//Trim the white spaces
string MegaCalc::trim(string& str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
			str.erase(i, 1);
			i--;
		}
	}
	return str;
}

//Display the output
void MegaCalc::display(MegaInt accumulator)
{
	char sign = accumulator.mega_int[0];
	accumulator.mega_int.pop_front();
	while (accumulator.mega_int.front() == '0' && accumulator.mega_int.size() > 1)
	{
		accumulator.mega_int.pop_front();
	}
	accumulator.mega_int.push_front(sign);
	cout << endl;
	cout << "Accumulator : " << accumulator << endl;

}



//Calculate the factorial of the input number
MegaInt MegaCalc::factorial(MegaInt accumulator)
{
	MegaInt mega_k, one, mega_fact;
	one.mega_int.push_back('1');
	one.mega_int.push_front('+');

	mega_fact.mega_int.push_front('1');
	mega_fact.mega_int.push_front('+');

	accumulator.mega_int.pop_front();
	for (MegaInt mega_k = one; mega_k <= accumulator; ++mega_k)
	{
		//mega_fact = mega_fact * mega_k;
		mega_fact = mega_fact * mega_k;
		cout << mega_k << "! = " << mega_fact << endl;
	}
	cout << endl;
	return mega_fact;
}


//Calculate the hailstone
MegaInt MegaCalc::hailstone(MegaInt input)
{
	MegaInt one, two, three;
	char c0 = '0';
	one.mega_int.push_front('1');
	one.mega_int.push_front('+');

	two.mega_int.push_front('2');
	two.mega_int.push_front('+');

	three.mega_int.push_front('3');
	three.mega_int.push_front('+');

	char a = input.mega_int.back();
	int Last_digit = a - int{ c0 };
	int remainder = Last_digit % 2;
	if (remainder == 0)
	{
		return one.division(input, two);
	}
	else
	{
		return one.add(one.multiplication(input, three), one);
	}

}

