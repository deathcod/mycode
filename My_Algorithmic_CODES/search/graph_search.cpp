#include "graph.h"

class mycomparison
{
public:
	bool operator() (const pair<int,int> &lhs, const pair<int, int> &rhs) const
	{
		// implementing a min - priority queue
		return (lhs.second > rhs.second);
	}
};


/*
A* tree search algorithm
A* search is an informed search algorithm used for path-finding and graph traversal. It combines the advantages of both Dijkstra’s algorithm (in that it can find a shortest path) and Greedy Best-First-Search (in that it can use a heuristic to guide search). It combines the information that Dijkstra’s algorithm uses (favoring vertices that are close to the starting point) and information that Best-First-Search uses (favoring vertices that are closer to the goal).

Let g(n) represent the exact cost of the path from the starting point to any vertex n, and h(n) represent the heuristic estimated cost from vertex n to the goal. Dijkstra’s algorithms builds a priority queue of nodes ordered on their g(n) values. Best-First-Search employs a priority queue of nodes ordered on h(n) values. A* balances the two as it moves from the starting point to the goal. It builds a priority queue of nodes ordered on f(n) = g(n) + h(n) which is the total estimated path cost through the node n.


Time complexity: O((|V| + |E|).log|V|)
Space complexity: O(V)
*/
void a_star_tree(graph *GRAPH, int source, int destination)
{
	int *g = new int[GRAPH->get_number_of_nodes()]();
	int f = g[source] + GRAPH->h[source];
	GRAPH->path[source].push_back(source);

	priority_queue< pair<int,int> , std::vector< pair<int,int> >, mycomparison> pq;
	pq.push(pair<int, int> (source, f));

	while(!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();

		if(top.first == destination)
		{
			// This shows the path a* search tree took.
			GRAPH->display_path(destination);
			return;
		}


		for (int i = 0; i < GRAPH->adj_list[top.first].size(); ++i)
		{
			pair<int ,int > current_node 	= GRAPH->adj_list[top.first][i];
			g[current_node.first] 		 	= g[top.first] + current_node.second;
			f							 	= g[current_node.first] + GRAPH->h[current_node.first];

			GRAPH->path[current_node.first] = GRAPH->path[top.first];
			GRAPH->path[current_node.first].push_back(current_node.first);

			pq.push(pair<int, int>(current_node.first, f));
		}
	}
}

/*
A* graph search algorithm

*/

int main(int argc, char const *argv[])
{
	graph *g = example1(10);
	cout << g->heuristic_consistency() << "\n";
	a_star_tree(g, 1, 5);
	return 0;
}