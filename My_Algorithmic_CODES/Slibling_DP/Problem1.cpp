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
1 2 100 50 20 5 5 12 60 5 

output
232
*/
#include <bits/stdc++.h>
using namespace std;
int dp1[100], dp2[100], visited[100], cost[100];
std::vector< std::vector<int> > v( 100 );

int max(int x, int y)
{
	return (x>y)?x:y;
}

//recursively go to the nodes and 
int fun(int index)
{
	if(dp2[index]!=0)
		return dp2[index];

	dp1[index] = cost[index];
	for (int i=0; i<v[index].size(); i++)
	{
		//cout << v[index][i];
		if (visited[v[index][i]]==0)
		{
			visited[v[index][i]] = 1;
			dp1[index] += fun(v[index][i]);
			dp2[index] += max(dp1[v[index][i]], dp2[v[index][i]]);
		}
	}
	//cout << "\n";
	
	return dp2[index];
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

	//input the cost for each node
	for(int i=1; i<=n; i++)
		cin >> cost[i];

	int root = 1;
	visited[1] =1;
	fun(root);

	cout << "\n" << max(dp1[1],dp2[1]) << "\n";
	/*
	for(int i=1;i<=n;i++)
		cout << i << " = " << dp2[i] << " " << dp1[i] << "\n";
	*/
	return 0;
}