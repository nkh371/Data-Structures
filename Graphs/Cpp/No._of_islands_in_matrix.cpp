#include <iostream>
#include <stdio.h> 

#define rows 4
#define cols 4

using namespace std;

bool condition(int adj[][cols], bool visited[][cols], int r, int c)
{
	if(!visited[r][c] && adj[r][c] && (r >= 0 && r < rows) && (c >= 0 && c < cols))
		return true;
		
	return false;
}

void DFS_fn(int adj[][cols], bool visited[][cols], int r, int c)
{
	/*Initializing neighbours*/
	static int nrows[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	static int ncols[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	
	int i;
	for(i = 0; i <= 8; i++)
	{
		int nw_r = r + nrows[i];
		int nw_c = c + ncols[i]; 
		if(condition(adj, visited, nw_r, nw_c))
		{
			visited[nw_r][nw_c] = true;
			DFS_fn(adj, visited, nw_r, nw_c);
		}
	}
}
			

void DFS(int adj[][cols])
{
	bool visited[rows][cols];
	
	int i, j;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < cols; j++)
			visited[i][j] = false;
	
	int count = 0;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			if(!visited[i][j] && adj[i][j])
			{	
				DFS_fn(adj, visited, i, j);
				count++;
			}
		}
	}
	
	printf("Total no. of islands are --> %d", count);		
}

int main(void)
{
	int ar[][cols] = { {1, 1, 0, 1},
					   {0, 1, 0, 0},
					   {0, 0, 0, 0},
					   {1, 1, 0, 1} };
					   
	DFS(ar);
					   
	return 0;
}
