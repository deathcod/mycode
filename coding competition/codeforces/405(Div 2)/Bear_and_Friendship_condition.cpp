#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m,x,y;
	cin >> n >> m;
	int degree[150001] = {0};
	std::vector<int> v[n+1];
	for(int i =0; i<m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
	// for(int i=1;i<=n;i++)
	// 	cout << degree[i] << " ";
	// cout << "\n";
	int visited[150001] = {0};
	std::map<int, int> map;
	for(int i=0; i<n; i++)
	{
		if(visited[i]!=0)
			continue;
		visited[i]=1;
		int s = v[i].size();
		if(s==0)
			continue;
		for(int j=0; j<s; j++)
		{
			visited[v[i][j]]=1;
			map[v[i][j]] = 1;
			//cout << v[i][j] << " = " << degree[v[i][j]] << "<>" << degree[i] << " " << i <<"\n";
			if(degree[v[i][j]] != degree[i])
			{
				cout << "NO";
				return 0;
			}
		}

		map[i] = 2;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			int ss = v[f].size();
			for(int j=0; j<ss; j++)
			{
				if(map.find(v[f][j]) != map.end())
				{
					if(map[v[f][j]] == 1)
					{
						map[v[f][j]]=2;
						q.push(v[f][j]);
					}
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
		}
		map.clear();
	}
	cout << "YES";
	return 0;
}