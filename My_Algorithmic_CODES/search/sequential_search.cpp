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


*/
int main(int argc, char const *argv[])
{
	int	a[11] = {1,2,3,4,5,6,7,7,8,8,8};
	binary_search(a, 11, 8);
	return 0;
}