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
		NODE = n;
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
	void display_path(int index);
	int get_number_of_nodes();

	//AI
	void add_heuristic(int x, int cost);
	bool heuristic_consistency();
};

//zero based indexing
void graph :: add_directed_node(int x, int y, int cost)
{
	adj_list[x].push_back(pair<int, int>(y,cost));
}

//zero based indexing
void graph :: add_undirected_node(int x, int y, int cost)
{
	adj_list[x].push_back(pair<int, int>(y,cost));
	adj_list[y].push_back(pair<int, int>(x,cost));
}

//zero based indexing
void graph :: add_heuristic(int x, int cost)
{
	h[x] = cost;
}

//zero based indexing
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

//zero based indexing
bool graph :: heuristic_consistency()
{
	int *local_visited = new int[NODE]();
	for (int i = 0; i < NODE; ++i)
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
graph * example1()
{
	graph *g = new graph(5);

	g->add_directed_node(0, 1, 1);
	g->add_directed_node(0, 2, 4);
	g->add_directed_node(1, 2, 2);
	g->add_directed_node(1, 3, 5);
	g->add_directed_node(2, 3, 2);
	g->add_directed_node(1, 4, 12);
	g->add_directed_node(3, 4, 3);

	g->add_heuristic(0, 7);
	g->add_heuristic(1, 6);
	g->add_heuristic(2, 4);
	g->add_heuristic(3, 2);
	g->add_heuristic(4, 0);

	return g;
}

graph* example2()
{
	graph *g = new graph(9);

	g->add_undirected_node(0, 1, 4);
	g->add_undirected_node(0, 7, 8);
	g->add_undirected_node(1, 2, 8);
	g->add_undirected_node(1, 7, 11);
	g->add_undirected_node(2, 3, 7);
	g->add_undirected_node(2, 8, 2);
	g->add_undirected_node(2, 5, 4);
	g->add_undirected_node(3, 4, 9);
	g->add_undirected_node(3, 5, 14);
	g->add_undirected_node(4, 5, 10);
	g->add_undirected_node(5, 6, 2);
	g->add_undirected_node(6, 7, 1);
	g->add_undirected_node(6, 8, 6);
	g->add_undirected_node(7, 8, 7);

	return g;
}