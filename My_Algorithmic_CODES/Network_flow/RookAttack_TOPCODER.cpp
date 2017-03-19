#line 90 "RookAttack.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pp;

class RookAttack {
	public:

	std::vector<int> lst[300];
	int row_col[300], col_row[300];

	bool find_match(int source)
	{
		int parent[300], current_row, curent_col;
		for(int i=0;i<=300;i++)
			parent[i]=-1;
		parent[source] = source;

		queue<int> q;
		q.push(source);


		int flag = 0;
		while( !flag and !q.empty())
		{
			current_row = q.front();
			printf("current row = %d\n", current_row);
			q.pop();
 	

			//loop over all the columns.
			for(int i=0; i<lst[current_row].size(); i++)
			{
				curent_col = lst[current_row][i];//picking up a column
				printf("current_col = %d\n", curent_col);

				
				int row_connecting_this_col = col_row[curent_col];
				printf("/*denotes the row number to which the column is linked*/\n row_connecting_this_col = %d\n", row_connecting_this_col);


				if(row_connecting_this_col == -1)
				{
					flag = 1;
					break;
				}
				if(parent[row_connecting_this_col] == -1)
				{
					printf("row_connecting_this_col is here setting its parent as %d\n", current_row);
					q.push(row_connecting_this_col);
					parent[row_connecting_this_col] = current_row;
				}
			}
		}
		if(!flag)
			return false;

		while(parent[current_row] != current_row)
		{
			int column_in_this_row = row_col[current_row];
			row_col[current_row] = curent_col;
			col_row[curent_col] = current_row;
			
			printf("column_in_this_row = %d\n", column_in_this_row);
			printf("row_col[%d] = %d\n",current_row, curent_col);
			printf("col_row[%d] = %d\n",curent_col, current_row);

			current_row = parent[current_row];
			curent_col = column_in_this_row;
			
			printf("current_row = %d\n", current_row);
			printf("curent_col = %d\n", curent_col);
		}
		row_col[current_row] = curent_col;
		col_row[curent_col] = current_row;

		printf("OUT row_col[%d] = %d\n",current_row, curent_col);
		printf("OUT col_row[%d] = %d\n",curent_col, current_row);
		printf("_____________________________________\n");
		
		return true;
	}
	int howMany(int rows, int cols, vector <string> cutouts) {
		
		int adj[303][303] = {0};
		int ret = 0;
		memset(row_col, -1, sizeof(row_col));
		memset(col_row, -1, sizeof(col_row));

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
			ret += find_match(i);

		return ret;
	}
};


// Powered by FileEdit
// Powered by CodeProcessor