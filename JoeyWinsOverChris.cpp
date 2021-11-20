#include <iostream>
#include <vector>

using namespace std;

int getProduct(int num)
{
	int result = 1;

	for (int i = 0; num > 0; i++)
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
