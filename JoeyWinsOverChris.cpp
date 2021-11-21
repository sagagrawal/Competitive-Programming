/*
This file contains a solution to a problem described below:
Chris wants to give money to Joey by playing a game without any rules. But Joey wants to set some rules for the game as follows:
1. They have a set of 1000000 cards(A) each with a unique number on it. The product of digits of each card represents the value of the card. Whoever has the highest value of card drawn wins. If both has same value of card then it's a tie and nobody wins.

Consider they play N rounds of this game.

Constraints:
1 <= A <=1000000
1 <= N <= 100000
*/

#include <iostream>
#include <vector>

using namespace std;

int getProduct(int num)
{
	int result = 1;

	while(num > 0)
	{
		result *= (num % 10);
		num = num / 10;
	}
	return result;
}

vector<int> getWaysToWin(const vector<int> &myarr)
{
	vector<int> result;

	for (int item : myarr)
	{
		int product = getProduct(item);

		if (product == 0)
		{
			result.push_back(0);
			continue;
		}
		int waysToWin = 0;
		for (int i = 1; i <= pow(10, 6); i++)
		{
			int temp_product = getProduct(i);

			if (temp_product < product)
			{
				waysToWin++;
			}
		}
		result.push_back(waysToWin);
	}

	return result;
}

int main()
{
	vector<int> arr;
	vector<int> res;
	arr.push_back(123456);
	arr.push_back(2021);

	res = getWaysToWin(arr);

	for (int item : res)
	{
		cout << item << endl;
	}
	return 0;
}
