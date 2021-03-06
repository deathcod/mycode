#include <bits/stdc++.h>
using namespace std;

/*
Binary search:
This algorthim helps to find a value in a sorted sequence.

Time Complexity: O(logN) [Since it uses half the search space] 
Space Complexity: O(1) [Space taken by this algorithm is same for any number of element in the array]
*/
void binary_search(int *a, int n, int value)
{
	int lower_bound = 0, upper_bound = n-1;
	while(lower_bound <= upper_bound)
	{
		int mid = lower_bound + (upper_bound - lower_bound)/2;
		if (a[mid] == value)
		{
			cout << "Search result found at index " << mid << "\n";
			return;
		}
		else if(a[mid] < value)
			lower_bound = mid +1;
		else
			upper_bound = mid -1;
	}
	cout << "No search result found \n";
}

/*
Discreate Binary Search
using binary search on monotonic increasing function f whose domain is set of integers.

Time Complexity: O(logN) [Since it uses half the search space] 
Space Complexity: O(1) [Space taken by this algorithm is same for any number of element in the array]
*/
// return the index.
int discreate_binary_search(int *a, int n, int c, int value)
{
	// to solve this we consider the output from the array in a form of [no, no, no, yes, yes, yes, yes, yes]
	// "no" means the condition which we are looking for is not satisfied.
	int lower_bound = 0, upper_bound = n-1;
	while(lower_bound < upper_bound)
	{
		switch(c)
		{
			// find the index which is greater than or equal to the target value
			case 1:
			{	
				int mid = lower_bound + (upper_bound - lower_bound)/2;
				if(a[mid] >= value)
					upper_bound = mid;
				else
					lower_bound = mid + 1;
				break;
			}

			// find the index which is just less than the target value
			case 2:
			{	
				// To judge how to choose mid consider [ no, yes ], condition over two array element
				int mid = lower_bound + (upper_bound - lower_bound + 1)/2;
				if(a[mid] >= value)
					upper_bound = mid - 1;
				else
					lower_bound = mid;
				break;
			}

		}
	}
	return lower_bound; // returning 0 based index
}

/*Disreate binary search for real numbers.(This is the general situation in competitive programming)

Time Complexity: O(logN)
Space Complexity: O(1)
*/
bool p(double x, double value)
{
	// Using log as the monotonic increasing function
	// We are trying to get the approximate value of x, such that p(x) = value
	return (log(x) > value);
}

double discreate_binary_search_real_values(double lower_bound, double upper_bound, double value)
{
	while (fabs(upper_bound - lower_bound) > 1e-9)
	{
		double mid = lower_bound + (upper_bound - lower_bound)/2.0;
		if (p(mid, value) == true)
			upper_bound = mid;
		else
			lower_bound = mid;
	}
	return lower_bound;
}

int main(int argc, char const *argv[])
{
	int	a[11] = {1, 3, 5, 6, 7, 7, 10, 12, 18, 20, 25};
	binary_search(a, 11, 8);

	cout << discreate_binary_search(a, 11, 1, 8) << "\n";
	cout << discreate_binary_search(a, 11, 2, 8) << "\n";

	//trying to get the value of log-base e value
	cout << discreate_binary_search_real_values(0, 1e9, 1) << "\n";
	return 0;
}