#include "graph.h"
int main(int argc, char const *argv[])
{
	graph *x = new graph(10);
	x->add_undirected_node(1,2,12);
	x->add_undirected_node(1,3,12);

	x->add_heuristic(1,23);
	x->add_heuristic(2,12);

	for (int i = 0; i < 10; ++i)
	{
		cout << x->heuristic_value[i] << " ";
	}
	return 0;
}