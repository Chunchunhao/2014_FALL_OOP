/*
 * This file is for 2014 Fall OOP_HW1
 * defined a function called readInput, to recongnize the input
*/
#ifndef HWREAD_H

#define HWREAD_H

#include <iostream>
#include <string>
using namespace std;

int readInput(string in);

int readInput(string in) {
	int num = 0,
		negBit = (in[0] == '-' ? 1 : 0);

	if (negBit == 1 && in.size() == 1)
		return -2;	// input is '-'

	for (int i = (negBit == 1 ? 1 : 0); i < in.size(); i++)
	{
		if (in[i] < '0' || in[i] > '9'){
			return -2; // not integer
		}
		else {
			num = num * 10 + in[i] - '0';
			if (num < 0)
				return num; // overflow
		}
	}
	if (negBit == 1){
		return -1; // a negative integer
	}
	else
		return num;
}


#endif