/*
bellman ford  
-------------
the algorithm calculate shortest paths in bottom-up manner. It first calculates the shortest distances for the shortest paths which have at-most one edge in the path. Then, it calculates shortest paths with at-nost 2 edges, and so on. After the ith iteration of outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges

Time complexity : O(VE)
Space complexity : O(V)

It depends on the way we define it.

*   If we assume that the graph is given, the extra space complexity is O(V) (for an array of distances).

*   If we assume that the graph also counts, it can be O(V^2) for an adjacency matrix and O(V+E) for an adjacency list.

They both are "true" in some sense. It's just about what we want to count in a specific problem
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,m,n,visited[1001],v[1003][3];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)
            visited[i]=-1002;
        visited[1]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&v[i][0],&v[i][1],&v[i][2]);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[v[j][1]]>visited[v[j][0]]+v[j][2])
                    visited[v[j][1]]=visited[v[j][0]]+v[j][2];
            }
        }
        int flag=0;
        for(int i=0;i<m;i++)
        {
            if(visited[v[i][1]]>visited[v[i][0]]+v[i][2])
            {
                flag=1;
                break;
            }
        }
        //get the value 
        printf("%d\n",visited[n-1] );
    }
    return 0;
}