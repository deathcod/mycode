#line 90 "RookAttack.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pp;

class RookAttack {
	public:

	std::vector<int> lst[300];
	int row_col[300], col_row[300];
	int current_col, current_row, row_connecting_this_col;
	int parent[300];
	
	bool find_match(int source)
	{
		current_row = source;
		for(int i=0; i< lst[source].size();i++)
		{
			current_col = lst[source][i];
			row_connecting_this_col = col_row[current_col];
			
			if(row_connecting_this_col == -1)
			{
				return true;
			}
			if(parent[row_connecting_this_col] == -1)
			{	
				parent[row_connecting_this_col] = source;
				return find_match(row_connecting_this_col);
			}
		}
		return false;
	}

	int howMany(int rows, int cols, vector <string> cutouts) {
		
		int ret = 0;
		int adj[303][303] = {0};
		memset(row_col, -1, sizeof(row_col));
		memset(col_row, -1, sizeof(col_row));
		memset(parent, -1, sizeof(parent));

		int cuts_len = cutouts.size();
		for(int i=0; i< cuts_len; i++)
		{
			stringstream ss(cutouts[i]);
			int r,c;
			ss >> r >> c;
			adj[r][c] = 1;
		}
	
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				if(adj[i][j] == 0)
					lst[i].push_back(j);
					
		for(int i=0; i<rows; i++)
		{
			if(find_match(i))
			{
				ret += 1;
				
				if(parent[current_row] != i)
				{	
					int column_connecting_this_row = row_col[current_row];
					row_col[current_row] = current_col;
					col_row[current_col] = current_row;
					
					current_row = parent[current_row];
					current_col = column_connecting_this_row;
										
				}
				row_col[current_row] = current_col;
				col_row[current_col] = current_row;
			}
			
		}

		return ret;
	}
};


// Powered by FileEdit
// Powered by CodeProcessor