//, calculate longest path between any two nodes(also known as diameter of tree).

/*
input 
10 9
1 9
1 10
1 2
2 3
2 4
4 5
4 6
6 7
6 8
Output
6
*/


#include <bits/stdc++.h>
using namespace std;
int diameter = 0;
std::vector< std::vector<int> > v( 100 );

int max(int x, int y)
{
	return (x>y)?x:y;
}

//recursively go to the nodes and 
int fun(int index, int parent)
{
	std::vector<int> child;
	for (int i=0; i<v[index].size(); i++)
	{
		//cout << v[index][i];

		if (v[index][i] != parent)
			child.push_back(fun(v[index][i], index));
	}

	// getting two max from the array
	int max1=0, max2=0;
	for (int j = 0; j < child.size(); ++j)
	{
		if(max1< child[j])
		{
			max2 = max1;
			max1 = child[j];
		}
		else if(max2 < child[j])
			max2 = child[j];
	}
	cout << max1 << " " << max2 << "\n";
	diameter = max(diameter, 1 + max1 + max2);

	return 1 + max1;
}

int main(int argc, char const *argv[])
{
	int n, m, x, y;
	cin >> n >> m;
	
	
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int root = 1;
	fun(root, -1);

	cout << "\n" << diameter << "\n";
	/*
	for(int i=1;i<=n;i++)
		cout << i << " = " << dp2[i] << " " << dp1[i] << "\n";
	*/
	return 0;
}