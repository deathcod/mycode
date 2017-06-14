#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
	int NODE;
public:
	std::vector<pair<int, int> >*adj_list;
	int *h;
	int *visited;
	std::vector<int> *path;
	graph(int n)
	{
		NODE = n + 1;
		adj_list = new vector< pair< int, int > > [NODE];
		h = new int[NODE]();
		visited = new int[NODE]();
		path = new std::vector<int> [NODE];
	};
	~graph()
	{
		delete(adj_list);
		delete(h);
		delete(visited);
		delete(path);
	};
	
	void add_directed_node(int x, int y, int cost);
	void add_undirected_node(int x, int y, int cost);
	void mark_visited(int x, int value);
	void display_path(int index);
	int get_number_of_nodes();

	//AI
	void add_heuristic(int x, int cost);
	bool heuristic_consistency();
};

void graph :: add_directed_node(int x, int y, int cost)
{
	adj_list[x].push_back(pair<int, int>(y,cost));
}

void graph :: add_undirected_node(int x, int y, int cost)
{
	adj_list[x].push_back(pair<int, int>(y,cost));
	adj_list[y].push_back(pair<int, int>(x,cost));
}

void graph :: add_heuristic(int x, int cost)
{
	h[x] = cost;
}

void graph :: mark_visited(int x, int value)
{
	visited[x] = value;
}

void graph :: display_path(int index)
{
	for (int i = 0; i < path[index].size(); ++i)
	{
		cout << path[index][i] << " ";
	}
	cout << "\n";
}

int graph :: get_number_of_nodes()
{
	return NODE;
}

bool graph :: heuristic_consistency()
{
	int *local_visited = new int[NODE]();
	for (int i = 1; i < NODE; ++i)
	{
		if(local_visited[i] == 1)
			continue;
		local_visited[i] = 1;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int parent = q.front();
			q.pop();
			for(int j = 0; j < adj_list[parent].size(); j++)
			{
				pair<int, int> pp =  adj_list[parent][j];
				int child = pp.first;
				if(local_visited[child] == 0)
				{
					int cost = pp.second;
					if (h[parent] - h[child] > cost)
						return false;
					local_visited[child] = 1;
					q.push(child);
				}
			}
		}
	}
	return true;
}

//This is an example setup having a directed graph and also the heuristic value
graph * example1(int n)
{
	graph *g = new graph(n);

	g->add_directed_node(1, 2, 1);
	g->add_directed_node(1, 3, 4);
	g->add_directed_node(2, 3, 2);
	g->add_directed_node(2, 4, 5);
	g->add_directed_node(3, 4, 2);
	g->add_directed_node(2, 5, 12);
	g->add_directed_node(4, 5, 3);

	g->add_heuristic(1, 7);
	g->add_heuristic(2, 6);
	g->add_heuristic(3, 4);
	g->add_heuristic(4, 2);
	g->add_heuristic(5, 0);

	return g;
}