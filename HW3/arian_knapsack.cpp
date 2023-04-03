#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <random>

// profit , weight
struct Item
{
	int value, weight;
};

static bool cmp(Item a, Item b)
{
	// calculate profit/weight
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

inline double fractionalKnapsack(int W, std::vector<Item> &arr)
{
	std::sort(arr.begin(), arr.end(),cmp);

	double finalvalue = 0.0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].weight <= W)
		{
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}
		else
		{
			finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}

int main()
{
	// int W = 50;
	// std::vector<Item> arr = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	// std::cout << fractionalKnapsack(W, arr) << std::endl;

	// W = 15;
	// std::vector<Item> arr1 = { {10, 2}, {5, 3}, {15, 5},{7,7},{6,1},{18,4},{3,1} };
	// std::cout << fractionalKnapsack(W, arr1) << std::endl;

	int W = 0;
	int n = 0;
	std::vector<Item> arr;

	std::cin >> W >> n;
	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{
		Item temp;
		std::cin >> temp.value;
		arr.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i].weight;
	}

	std::cout << std::fixed << std::setprecision(2) << fractionalKnapsack(W, arr);
	return 0;
}