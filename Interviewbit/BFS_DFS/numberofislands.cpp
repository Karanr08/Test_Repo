#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define fo(i,l,r) for(int i=l;i< r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int lli;
typedef unsigned long long int ulli;
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
using namespace std;
#define M 1000000007


/*
int issafe(vector<vector<int>> grid, int row, int col,int x, int y, bool visited[])
{
	return ((x >= 0) &&(x < row) && (y >= 0) && (y < col) && M[x][y] && !visited[x][y]);
}


void DFS(vector<vector<int>> grid, int row, int col, int x, int y, bool visited[][grid[0].size()])
{
	static int rowNbr[] = {-1 , 0, 0, 1};
	static int colNbr[] = {0, 1, -1, 0};

	visited[x][y] = true;

	for(int k = 0; k < 4; k++)
	{
		if(issafe(grid, x, y, row, col, visited))
			DFS(grid, x + rowNbr[k], y + colNbr[k], row, col, visited);
	}
}

int countIslands(vector<vector<int>> grid)
{
	int row = grid.size();
	int col = grid[0].size();
	bool visited[row][col];

	memset(visited, false, sizeof(visited));

	int count = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(grid[i][j] && !visited[i][j])
			{
				DFS(grid, i, j, row, col, visited);
				++count;
			}
		}
	}
	return count;
}
*/
//////////////////////////////////////////////////////







// BFS/////////


bool issafe(vector<vector<int>> grid , int x, int y, int row, int col, bool visited[][col])
{
	return ((x >= 0) &&(x < row) && (y >= 0) && (y < col) && grid[x][y] && !visited[x][y]);
}


void BFS (vector<vector<int>> grid , int x, int y, int row, int col, bool visited[row][col])
{
	int rowNbr[] = {0, 0, 1, -1};
	int colNbr[] = {1, -1, 0, 0};

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;

	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			if(issafe(grid, i + rowNbr[k],j + colNbr[k], grid.size(), grid[0].size(), visited))
			{
				visited[i + rowNbr[k]][j + colNbr[k]] = true;
				q.push({i + rowNbr[k],j + colNbr[k] });
			}
		}
	}
}


int countIslands(vector<vector<int>> grid)
{
	int row = grid.size();
	int col = grid[0].size();

	bool visited[row][col];
	memset(visited, 0, sizeof(visited));

	int res = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(grid[i][j] && !visited[i][j]){
				BFS(grid, i, j, row, col, visited);
				res++;
			}

		}
	}
	return res;
}
int  main()
{
	vector<vector<int>> grid = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 

     cout << countIslands(grid) << endl;
}