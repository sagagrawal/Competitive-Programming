#include <vector>
#include <iostream>
#include <string>

using namespace std;

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
	vector<string> result;
	int i = 0, j = 0;

	while (i < names1.size())
	{
		if (std::count(result.begin(), result.end(), names1.at(i)) == 0)
		{
			result.push_back(names1.at(i));
		}
		i++;
	}

	while (j < names2.size())
	{
		if (std::count(result.begin(), result.end(), names2.at(j)) == 0)
		{
			result.push_back(names2.at(j));
		}
		j++;
	}

	return result;
}

int main()
{
	std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
	std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

	std::vector<std::string> result = unique_names(names1, names2);
	for (auto element : result)
	{
		std::cout << element << ' '; // should print Ava Emma Olivia Sophia
	}
	return 0;
}