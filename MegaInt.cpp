#include "MegaInt.h"
#include <iostream>
#include<string>
#include <deque>
using namespace std;
#include <sstream>
#include <algorithm>

//Calculate the addition of the two numbers..
MegaInt MegaInt::add(MegaInt accumulator, MegaInt input)
{
	char sc;
	int z;
	char sa = accumulator.mega_int[0];
	accumulator.mega_int.pop_front();
	char sb = input.mega_int[0];
	input.mega_int.pop_front();
	char sign = input.mega_int[0];
	if (sign == '+' || sign == '-')
	{
		input.mega_int.pop_front();
	}
	int i = accumulator.mega_int.size();
	int j = input.mega_int.size();
	if (i > j)
	{
		z = i - j;
		for (int x = 0; x < z; x++)
		{
			input.mega_int.push_front('0');
		}
	}
	else if (j > i)
	{
		z = j - i;
		for (int x = 0; x < z; x++)
		{
			accumulator.mega_int.push_front('0');
		}
	}


	if (sa == sb)//Comparing the sign of both the numbers.
	{
		if (sign == '-')
		{
			sb = '-';
			if (accumulator.mega_int > input.mega_int)       //If accumulator value is greater than input value then subtract input value from accumulator.
			{ 
				accumulator = accumulator - input;
				sc = sa;

			}
			else if (input.mega_int > accumulator.mega_int) //If input value is greater than accumulator value then subtract accumulator value from input.
			{
				accumulator = input - accumulator;
				sc = sb;
			}
			else                                            //If both values are same then clear the accumulator.
			{
				sc = '+';
				accumulator.mega_int.clear();
				accumulator.mega_int.push_back('0');
			}
			accumulator.mega_int.push_front(sc);
			return accumulator;

		}
		else
		{
			accumulator = accumulator + input;
			sc = '+';

		}

	}
	else
	{
		if (sign == '-')
		{
			accumulator = accumulator + input;
			sc = sa;
		}

		else
		{
			sb = '+';
			if (accumulator.mega_int > input.mega_int)       //If accumulator value is greater than input value then subtract input value from accumulator.
			{
				accumulator = accumulator - input;
				sc = sa;

			}
			else if (input.mega_int > accumulator.mega_int) //If input value is greater than accumulator value then subtract accumulator value from input .
			{
				accumulator = input - accumulator;
				sc = sb;
			}
			else                                            //If both values are same then clear the accumulator.
			{
				sc = '+';
				accumulator.mega_int.clear();
				accumulator.mega_int.push_back('0');
			}

		}

	}
	accumulator.mega_int.push_front(sc);
	return accumulator;
}


MegaInt::MegaInt()
{
}

//Calculate the subtraction of the two numbers..
MegaInt MegaInt::subtract(MegaInt accumulator, MegaInt input)
{
	int z;
	char sc;
	char sa = accumulator.mega_int[0];
	accumulator.mega_int.pop_front();
	char sb = input.mega_int[0];
	input.mega_int.pop_front();
	char sign = input.mega_int[0];
	if (sign == '-' || sign == '+')
	{
		input.mega_int.pop_front();
	}
	int i = accumulator.mega_int.size();
	int j = input.mega_int.size();
	if (i > j)
	{
		z = i - j;
		for (int x = 0; x < z; x++)
		{
			input.mega_int.push_front('0');
		}

	}
	else if (j>i)
	{
		z = j - i;
		for (int x = 0; x < z; x++)
		{
			accumulator.mega_int.push_front('0');
		}

	}
	if (sa == sb)
	{
		if (sign == '+')
		{
			sc = sa;
			accumulator = accumulator + input;
			accumulator.mega_int.push_front(sc);
			return accumulator;
		}
		else
		{
			sb = '+';
			if (accumulator.mega_int > input.mega_int)
			{
				sc = sa;
				accumulator = accumulator - input;
			}

			else if (input.mega_int > accumulator.mega_int)
			{
				sc = sb;
				accumulator = input - accumulator;

			}

			else
			{
				sc = '+';
				accumulator.mega_int.clear();
				accumulator.mega_int.push_back('0');
			}

		}

	}
	else
	{
		if (sign == sb)
		{
			accumulator = accumulator + input;
			sc = '+';

		}
		else
		{

			if (accumulator.mega_int > input.mega_int)
			{
				sc = sa;
				accumulator = accumulator - input;
			}

			else if (input.mega_int > accumulator.mega_int)
			{
				sc = sb;
				accumulator = input - accumulator;

			}

			else
			{
				sc = '+';
				accumulator.mega_int.clear();
				accumulator.mega_int.push_back('0');
			}
		}
	}
	accumulator.mega_int.push_front(sc);
	return accumulator;
}


//Calculate the division.
MegaInt MegaInt::division(MegaInt accumulator, MegaInt mega_calc)
{
	int z;
	MegaInt result;
	result.mega_int.push_back('0');
	result.mega_int.push_front('+');
	char sa = accumulator.mega_int[0];
	accumulator.mega_int.pop_front();
	mega_calc.mega_int.pop_front();
	char sb = mega_calc.mega_int[0];
	if (sb == '+' || sb == '-')
	{
		mega_calc.mega_int.pop_front();
	}
	else
	{
		sb = '+';
	}
	int i = accumulator.mega_int.size();
	int j = mega_calc.mega_int.size();
	if (i > j)
	{
		z = i - j;
		for (int x = 0; x < z; x++)
		{
			mega_calc.mega_int.push_front('0');
		}
	}
	else if (j > i)
	{
		z = j - i;
		for (int x = 0; x < z; x++)
		{
			accumulator.mega_int.push_front('0');
		}

	}

	//Main loop for Division.
	while (accumulator >= mega_calc)
	{
		accumulator = accumulator - mega_calc;
		//cout << accumulator << endl;
		++result;

	}

	result.mega_int.pop_front();
	if (sa == sb)
	{
		result.mega_int.push_front('+');
	}
	else
	{
		result.mega_int.push_front('-');
	}
	return result;
}

//Calculate the modulus.
MegaInt MegaInt::modulus(MegaInt accumulator, MegaInt mega_calc)
{
	int z;
	char sa = accumulator.mega_int[0];
	accumulator.mega_int.pop_front();
	mega_calc.mega_int.pop_front();
	char sb = mega_calc.mega_int[0];

	if (sb == '+' || sb == '-')
	{
		mega_calc.mega_int.pop_front();
	}
	else
	{
		sb = '+';
	}
	int i = accumulator.mega_int.size();
	int j = mega_calc.mega_int.size();
	if (i > j)
	{
		z = i - j;
		for (int x = 0; x < z; x++)
		{
			mega_calc.mega_int.push_front('0');
		}
	}
	else if (j > i)
	{
		z = j - i;
		for (int x = 0; x < z; x++)
		{
			accumulator.mega_int.push_front('0');
		}

	}
	while (accumulator >= mega_calc)
	{
		accumulator = accumulator - mega_calc;

	}

	if (sa == sb)
	{
		accumulator.mega_int.push_front('+');
	}
	else
	{
		accumulator.mega_int.push_front('-');
	}

	return accumulator;
}



//Calculate the multiplication..

MegaInt MegaInt::multiplication(MegaInt accumulator, MegaInt mega_calc)
{
	MegaInt  temp, one, mega_k;
	char sign1;
	char sign2;
	char sa;
	int val;
	char d0{ '0' };
	sign1 = mega_calc.mega_int[0];
	mega_calc.mega_int.pop_front();
	accumulator.mega_int.pop_front();

	one.mega_int.push_front('2');
	one.mega_int.push_front('+');

	int z;
	sign2 = accumulator.mega_int[0];
	if (sign2 == '+' || sign2 == '-')
	{
		sa = sign2;
		accumulator.mega_int.pop_front();

	}
	else
	{
		sa = '+';
	}
	temp = accumulator;
	int k = accumulator.mega_int.size();
	int j = mega_calc.mega_int.size();
	if (k > j)
	{
		z = k - j;
		for (int x = 0; x < z; x++)
		{
			mega_calc.mega_int.push_front('0');
		}

	}
	else if (j > k)
	{
		z = j - k;
		for (int x = 0; x < z; x++)
		{
			accumulator.mega_int.push_front('0');
		}

	}

	//Main loop for Multiplication.
	for (mega_k = one; mega_k <= mega_calc; ++mega_k)
	{
		accumulator = accumulator + temp;
	}
	if (sign1 == sa)
	{
		accumulator.mega_int.push_front('+');
	}
	else
	{
		accumulator.mega_int.push_front('-');
	}
	return accumulator;
}



//Clear the accumulator(set the value to zero).
MegaInt MegaInt::clear(MegaInt accumulator)
{
	accumulator.mega_int.clear();
	accumulator.mega_int.push_front('0');
	accumulator.mega_int.push_front('+');
	return accumulator;
}

//Negate the current value of accumulator.
MegaInt MegaInt::negate(MegaInt accumulator)
{
	char sa = accumulator.mega_int.front();
	accumulator.mega_int.pop_front();
	if (sa == '+')
	{
		sa = '-';
	}
	else
	{
		sa = '+';
	}
	accumulator.mega_int.push_front(sa);
	return accumulator;
}

//Reset the accumulator and set the input value.

MegaInt MegaInt::reset(MegaInt mega_calc)
{
	mega_calc.mega_int.pop_front();
	if (mega_calc.mega_int.front() == '+' || mega_calc.mega_int.front() == '-')
	{
		return mega_calc;
	}
	else
	{
		mega_calc.mega_int.push_front('+');
		return mega_calc;
	}
}

//Operator- overloading.
MegaInt MegaInt::operator-(MegaInt input)
{
	MegaInt output;
	int borrow = 0;
	int check;
	char c7;
	int j = mega_int.size() - 1;
	int k = input.mega_int.size() - 1;
	int p = max(mega_int.size(), input.mega_int.size());
	int i = p - 1;
	int t;
	int val3 = 0;
	int val4 = 0;
	char d0{ '0' };

	while (j >= 0 && k >= 0)
	{

		val3 = mega_int[j] - int{ d0 };
		val4 = input.mega_int[k] - int{ d0 };
		t = val3 - (val4 + borrow);
		borrow = 0;
		if (t < 0) {
			borrow = 1;
			t = 10 + t;
		}
		c7 = static_cast<char>(t + d0);
		output.mega_int.push_front(c7);
		--i;
		--j;
		--k;
	}
	while (j >= 0)
	{
		val3 = mega_int[j] - int{ d0 };
		t = val3 - borrow;
		borrow = 0;
		if (t < 0)
		{
			borrow = 1;
			t = 10 + t;
		}
		c7 = static_cast<char>(t + d0);
		output.mega_int.push_front(c7);
		i--;
		j--;
	}
	if (borrow == 1 || k >= 0)
	{
		cout << "impossible..." << endl;

	}
	else
	{
		return output;
	}
}

//operator= overloading.
MegaInt MegaInt::operator=(MegaInt mega_calc)
{
	mega_int = mega_calc.mega_int;
	return *this;
}

//operator<= overloading
bool MegaInt::operator<=(MegaInt mega_calc)
{
	char a = mega_int[0];
	mega_int.pop_front();
	int size1 = mega_int.size();
	int size2 = mega_calc.mega_int.size();
	int diff = 0;
	if (size1 > size2)
	{
		diff = size1 - size2;
		for (int x = 0; x < diff; x++)
		{
			mega_calc.mega_int.push_front('0');
		}

	}
	else if (size2 > size1)
	{
		diff = size2 - size1;
		for (int x = 0; x < diff; x++)
		{
			mega_int.push_front('0');
		}

	}
	if (mega_int <= mega_calc.mega_int)
	{
		mega_int.push_front(a);
		return true;
	}
	else
	{
		mega_int.push_front(a);
		return false;
	}
}

//operator* overloading.
MegaInt MegaInt::operator*(MegaInt& obj)
{
	MegaInt input;
	input.mega_int = mega_int;
	return multiplication(input, obj);
}


//operator+ overloading.
MegaInt MegaInt::operator+(MegaInt input)
{
	MegaInt output;
	int t = 0;
	int carry = 0;
	int val1 = 0;
	int val2 = 0;
	char c0{ '0' };
	int check;
	char c7;
	int j = mega_int.size() - 1;
	int k = input.mega_int.size() - 1;
	int i = max(mega_int.size(), input.mega_int.size());
	while (j >= 0 && k >= 0)
	{
		val1 = mega_int[j] - int{ c0 };
		val2 = input.mega_int[k] - int{ c0 };
		int t = val1 + val2 + carry;
		check = t % 10;
		c7 = static_cast<char>(check + c0);
		output.mega_int.push_front(c7);
		carry = t / 10;
		i = i - 1;
		j = j - 1;
		k = k - 1;
	}

	while (j >= 0)
	{
		val1 = mega_int[j] - int{ c0 };
		t = val1 + carry;
		check = t % 10;
		c7 = static_cast<char>(check + c0);
		output.mega_int.push_front(c7);
		carry = t / 10;
		i = i - 1;
		j = j - 1;
	}

	while (k >= 0)
	{
		val2 = input.mega_int[k] - int{ c0 };
		t = val2 + carry;
		check = t % 10;
		c7 = static_cast<char>(check + c0);
		output.mega_int.push_front(c7);
		carry = t / 10;
		i = i - 1;
		k = k - 1;
	}
	if (carry >= 1)
	{
		c7 = static_cast<char>(carry + c0);
		output.mega_int.push_front(c7);
	}
	return output;
}

//operator>= overloading.
bool MegaInt::operator>=(MegaInt mega_calc)
{
	if (mega_int >= mega_calc.mega_int)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//operator<< overloading.
ostream & operator<<(ostream & out, MegaInt & obj) {

	for (char ch : obj.mega_int) {

		cout << ch;
	}
	return out;

}

//operator++ overloading.
void MegaInt::operator++()
{
	MegaInt one, inc_val;
	one.mega_int.empty();
	one.mega_int.push_front('1');
	one.mega_int.push_front('+');
	inc_val.mega_int = mega_int;
	inc_val = add(inc_val, one);
	mega_int = inc_val.mega_int;
}