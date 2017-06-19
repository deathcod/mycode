/*
Floyd Warshall
The idea is to one by one pick all vertices and update all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of source and destination vertices respectively, there are two possible cases.
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j].

Time complexity = O(V^3)
Space complexiy = O(V^2)
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adj_matrix[21][21] = {0};
    int t;
    cin >> t;
    while(t--)
    {
        int no_of_vertices;
        cin >> no_of_vertices;
        
        //creating the graph
        for(int i=0; i<no_of_vertices; i++)
        {
            for(int j=0; j<no_of_vertices; j++)
            {
                cin >> adj_matrix[i][j];
            }
        }
        
        //applying the floyd warshall algorithm
        for(int k=0; k<no_of_vertices; k++)
        {
            for(int i=0; i<no_of_vertices; i++)
            {
                for(int j=0; j<no_of_vertices;j++)
                {
                    if(adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j])
                        adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
        
        //display the graph
        for(int i=0; i<no_of_vertices; i++)
        {
            for(int j=0; j<no_of_vertices; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}