// silnia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void decoder(string roman) {

	vector <int> result;
	int dec = 0;
	for (int i = 0; i < roman.length(); i++) {
		switch (roman.at(i))
		{
		case 'M': result.push_back(1000);
			break;
		case 'D': result.push_back(500);
			break;
		case 'C': result.push_back(100);
			break;
		case 'L': result.push_back(50);
			break;
		case 'X': result.push_back(10);
			break;
		case 'V': result.push_back(5);
			break;
		case 'I': result.push_back(1);
			break;
		}

	}


	for (int i = 0; i < roman.length() - 1; i++) {
		if (result[i] == 1 && (result[i + 1] == 5 || result[i + 1] == 10)) {
			result[i] = 0;
			result[i + 1] -=1;
		}
		if (result[i] == 10 && (result[i + 1] == 50 || result[i + 1] == 100)) {
			result[i] = 0;
			result[i + 1] -= 10;
		}
		if (result[i] == 100 && (result[i + 1] == 500 || result[i + 1] == 1000)) {
			result[i] = 0;
			result[i + 1] -= 100;
		}
	}
	dec = accumulate(result.begin(), result.end(),
		decltype(result)::value_type(0));
	cout << dec;
}


int main()
{
	decoder("XL");
}


