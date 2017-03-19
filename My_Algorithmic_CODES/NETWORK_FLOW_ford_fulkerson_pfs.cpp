/*
Network flow was done earlier on bfs 
now I trying in PFS(Priority first search)
going through the full details...
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct $
{
	int from;
	int vertex;
	int priority; 	
}node;


class mycomparison
{
public:
	bool operator() (const node &lhs, const node &rhs) const
	{
		return (lhs.priority < rhs.priority);
	}
};

int main(int argc, char const *argv[])
{
	std::priority_queue< node, std::vector<node>, mycomparison > pq;
	node x;
	x.vertex = 3;
	x.priority = 1e9;
	x.from = -1;
	cout << "fuck";
	pq.push(x);

	x.vertex = 12;
	x.priority = 19;
	x.from = 3;
	pq.push(x);

	cout << "fuck";
	return 0;
	node x;
	
	int n, m,start, end, capacity, source, sink ,adj[101][101] = {0};
	int path_capacity = 0;

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> capacity;
		adj[start][end] = capacity;
	}
	
	cin >> source >> sink;

	while(1)
	{
		int flag = 0;
		x.vertex = source;
		x.priority = 1e9;
		x.from = -1;
		pq.push(x);
		
		
		int from[101] = {0};

		while(!pq.empty())
		{
			node aux = pq.top();
			pq.pop();
			int where = aux.vertex;
			int cost = aux.priority;
			from[where] = aux.from;

			cout << where << " " << from[where] << " " << cost << "\n";
			if( where == sink)
			{
				int flag = 1;
				path_capacity = cost;
				while(!pq.empty())
					pq.pop();
				break;
			}

			for(int i=0; i<=n; i++)
			{
				if( adj[where][i]>0 and from[i]==0)
				{
					int new_cost = min(cost, adj[where][i]);
					x.vertex = i;
					x.priority = new_cost;
					x.from = where;
					pq.push(x);
				}
			}
		}
		
		if(flag == 0)
			break;

		int where = sink;
		while ( from[where] >-1)
		{
			int prev = from[where];
			adj[prev][where] -= path_capacity;
			adj[where][prev] += path_capacity;
			where = prev;
		}
	}
	cout << path_capacity;
	
	return 0;
}