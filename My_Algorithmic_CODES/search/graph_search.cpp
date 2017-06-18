#include "graph.h"
#include "minheap.h"

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
			cout << "PATH: ";
			GRAPH->display_path(destination);
			cout << "cost: " << top.second;
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
The optimality of A*-GRAPH-SEARCH places stronger demands on the heuristic, requiring it to be consistent. A heuristic is consistent if it approximates the actual path cost in an incremental way without taking any step back. Formally, for every node N and for every successor P of N, h(N) <= h(P) + cost(N, P). Fortunately, most natural heuristic functions (particularly those obtained by relaxing problem constraints) are consistent.

Time complexity: O((|V| + |E|).log|V|)
Space complexity: O(V)
*/
void a_star_graph(graph *GRAPH, int source, int destination)
{
	if(GRAPH->heuristic_consistency())
		cout << "graph is consistent\n";
	else
	{
		cout << "graph is not consistent\n";
		return;
	}

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
			// This shows the path a* search graph took.
			cout << "PATH: ";
			GRAPH->display_path(destination);
			cout << "cost: " << top.second;
			return;
		}
		GRAPH->visited[top.first] = 1;

		for (int i = 0; i < GRAPH->adj_list[top.first].size(); ++i)
		{
			pair<int ,int > current_node = GRAPH->adj_list[top.first][i];

			if(GRAPH->visited[current_node.first] == 1)
				continue;

			g[current_node.first] = g[top.first] + current_node.second;
			f = g[current_node.first] + GRAPH->h[current_node.first];

			GRAPH->path[current_node.first] = GRAPH->path[top.first];
			GRAPH->path[current_node.first].push_back(current_node.first);

			pq.push(pair<int, int>(current_node.first, f));
		}
	}
}

/*
Disjkstra algorithm
Dijkstra’s algorithm, two sets are maintained, one set contains list of vertices already included in SPT (Shortest Path Tree), other set contains vertices not yet included. With adjacency list representation, all vertices of a graph can be traversed in O(V+E) time using BFS. The idea is to traverse all vertices of graph using BFS and use a Min Heap to store the vertices not yet included in SPT (or the vertices for which shortest distance is not finalized yet).  Min Heap is used as a priority queue to get the minimum distance vertex from set of not yet included vertices. Time complexity of operations like extract-min and decrease-key value is O(LogV) for Min Heap

Time complexity : O((E + V)logV)
Space complexity : O(V)
since at worst case you need to hold all vertices in the heap

*/
void Disjkstra(graph *GRAPH, int source, int destination)
{
	
	//initializing the heap
	int nodes = GRAPH->get_number_of_nodes();

	minheap *pq = new minheap(nodes);
	for(int i=0; i<nodes; i++)
	{
		pq->insert_key(pp(i, 1e9));
	}

	pq->decrease_key(source, 0);
	GRAPH->path[source].push_back(source);

	while(!pq->isempty())
	{
		pp top = pq->extract_min();

		//cout << "testing...";
		//cout << top.first  << " " << top.second << "\n";

		if(top.first == destination)
		{
			cout << "PATH: ";
			GRAPH->display_path(destination);
			cout << "cost: " << top.second;
			return;
		}
		GRAPH->visited[top.first] = 1;

		for (int i = 0; i < GRAPH->adj_list[top.first].size(); ++i)
		{
			pp current_node = GRAPH->adj_list[top.first][i];
			if(GRAPH->visited[current_node.first] == 1)
				continue;

			//cout << "\n----------\n";
			//cout << "current_node: " << current_node.first << "\n";
			//cout << "get_value: " << pq->get_val(current_node.first) << "\n";
			//cout << "top_data + current_data: " << top.second + current_node.second << "\n";
			if(pq->get_val(current_node.first) > top.second + current_node.second)
			{
				//cout << "replace";
				pq->decrease_key(current_node.first, top.second + current_node.second);

				GRAPH->path[current_node.first] = GRAPH->path[top.first];
				GRAPH->path[current_node.first].push_back(current_node.first);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	graph *g = example2();
	a_star_tree(g, 0, 4);
	cout << "\n\n";

	g = example2();
	a_star_graph(g, 0, 4);
	cout << "\n\n";

	g = example2();
	Disjkstra(g, 0, 4);
	cout << "\n\n";

	return 0;
}