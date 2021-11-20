#include <iostream>
#include <vector>

using namespace std;

int getDigitsCount(int num)
{
	int result = 0;
	
	for (int i = 0; num > 0; i++)
	{
		num = num / 10;
		result++;
	}
	return result;
}

int* getDigitsArrayFromNum(int num, const int &digitsCount)
{
	int* ptr = nullptr;

	ptr = new int[digitsCount];

	for (int i = 0; i < digitsCount; i++)
	{
		*(ptr + i) = num % 10;
		num = num / 10;
	}
	return ptr;
}

int getProduct(const int* digits, const int &count)
{
	int result = 1;
	for (int i = 0; i < count; i++)
	{
		result *= (*(digits + i));
	}
	return result;
}

vector<int> getWaysToWin(const vector<int> &myarr)
{
	vector<int> result;

	for (int item : myarr)
	{
		int count = getDigitsCount(item);
		int* digits = getDigitsArrayFromNum(item, count);

		int product = getProduct(digits, count);

		if (product == 0)
		{
			result.push_back(0);
			continue;
		}
		int waysToWin = 0;
		for (int i = 1; i <= pow(10, 6); i++)
		{
			int temp_count = getDigitsCount(i);
			int* temp_digits = getDigitsArrayFromNum(i, temp_count);

			int temp_product = getProduct(temp_digits, temp_count);

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