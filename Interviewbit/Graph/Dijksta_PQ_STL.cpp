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


typedef pair<int, int> ip;

void addedge(vector<ip> adj[], int u, int v, int wt)
{
	adj[u].push_back({v, wt});
	adj[v].push_back({u, wt});
}


void shortestPath(vector<ip> adj[], int V, int src)
{
	priority_queue<ip, vector<ip>, greater<ip>> pq;

	vector<int> dist(V, INT_MAX);

	pq.push({0, src});
	dist[src] = 0;


	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for(auto x : adj[u])
		{
			int v = x.first;
			int wt = x.second;

			if(dist[v] > dist[u] + wt)
			{
				dist[v] = dist[u] + wt;
				pq.push({dist[v],v});			}
		}
	}


	printf("Vertex Distance from source\n");

	for(int i = 0; i < V; i++)
	{
		cout << i << "   " << dist[i] << endl;
	}
}

int main()
{
	int V, e;
	cin >> V >> e;

	vector<ip> adj[V];
	
	int a, b, wt;

	while(e--)
	{
		cin >> a >> b >> wt;
		addedge(adj, a, b, wt);
	}
	cout << "DONE" << endl;

	shortestPath(adj, V, 0);


}







 int m = maze.size(), n = maze[0].size(), d[] = {0, 1, 0, -1, 0};
        queue<vector<int>> todo;
        todo.push(start);
        maze[start[0]][start[1]] = -1;
        while (!todo.empty()) {
            vector<int> p = todo.front();
            todo.pop();
            for (int i = 0; i < 4; i++) {
                int r = p[0], c = p[1];
                while (r + d[i] >= 0 && r + d[i] < m && c + d[i + 1] >= 0 && c + d[i + 1] < n && maze[r + d[i]][c + d[i + 1]] <= 0) {
                    r += d[i];
                    c += d[i + 1];
                }
                if (r == destination[0] && c == destination[1]) {
                    return true;
                }
                if (!maze[r][c]) {
                    maze[r][c] = -1;
                    todo.push({r, c});
                }
            }
        }
        return false;





///////////////////////////////

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, start[0], start[1]});
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        dist[start[0]][start[1]] = 0;


        int d[] = {0, 1, 0, -1, 0};

        while(!pq.empty())
        {
        	auto p = pq.front();
        	pq.pop();

        	for(int i = 0; i < 4; i++)

    		{
    			int r = p[0], c = p[1];
    			int x = r, y = c;

    			while(r + d[i] >= 0 && r + d[i] < n && c + d[i+1] >= 0 && c + d[i + 1] < m && maze[r + d[i]][c + d[j]] <= 0)
    			{
    				r += d[i];
    				c += d[i + 1];
    			} 

    			if(dist[r][c] > dist[x][y] + abs)
    		}


        }

        class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        if(maze.empty() or start.empty() or dest.empty())
            return 0;   
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>dist(m,vector<int>(n,-1));
        vector<int> dir{0,1,0,-1,0};
        queue<pair<int,int>>q;
        dist[start[0]][start[1]]=0;
        q.push({start[0],start[1]});
        while(!q.empty())
        {
            auto coord=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=coord.first;
                int col=coord.second;
                int currDistance=dist[row][col];
                while(row+dir[i]>=0 and col+dir[i+1]>=0 and row+dir[i]<m and col+dir[i+1]<n and maze[row+dir[i]][col+dir[i+1]]!=1)
                {
                    row+=dir[i];
                    col+=dir[i+1];
                    ++currDistance;
                }
                if(dist[row][col] ==-1 or currDistance<dist[row][col] )
                {
                    dist[row][col]=currDistance;
                    q.push({row,col});
                }
            }
        }
        return dist[dest[0]][dest[1]];
    }
};




int orangesRooting(vector<vector<int>> &grid)
{
	int n = grid.size();

	int m = grid[0].size();


	queue<pair<int, int>> Q;

	int fresh = 0;

	int ans = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)

			{
				if(grid[i][j] == 2)
				{
					Q.push({i, j});
				}
				if(grid[i][j] == 1)
					fresh++;
			}
	}

	int dir[] = {0, 1, 0, -1, 0};
	while(!Q.empty())
	{
		int sz = Q.size();

		while(sz--)
		{
			pair<int, int> p = Q.front();

			Q.pop();

			for(int i = 0; i < 4; i++)
			{
				int r = p.first + dir[i];
				int c = p.second + dir[i + 1];

				if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
				{
					grid[r][c] = 2;
					Q.push({r,c});
					fresh--;
				}
			}
		}
		ans++;
	}


	if(fresh > 0) return -1;
	if(ans == -1) return 0;
	return ans;
}









class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 1;
                    grid[i][j] = 0;
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
                                grid[r][c] = 0;
                                a++;
                                todo.push({r, c});
                            }
                        }
                    }
                    area = max(area, a);
                }
            }
        }
        return area;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int n = M.size();
        int m = M[0].size();
        
        int dir[] = {0, 1, 0, -1, 0};
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(M[i][j] == 1)
                {
                        ++count;
                    queue<pair<int, int>> Q;
                    M[i][j] = 0;
                    
                    
                    Q.push({i, j});

                    while(!Q.empty())
                    {
                        auto p = Q.front();
                        Q.pop();
                        
                        
                        for(int k = 0; k < 4; k++)
                        {

                            int r = p.first + dir[k];
                            int c = p.second + dir[k + 1];
                            
                            if(r >= 0 && r < n && c >= 0 && c < m && M[r][c] == 1)
                            {
                            	 M[r][c] = 0;
                                Q.push({r, c});
                               
                            }
                        
                        }
                    }
                    
                }
            }
        }
        
        return count;
        
        
    }
};


int find(int x)
{
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void union(int x, int y)
{
	int xp = find(x);
	int yp = find(y);

	if(rank[xp] > rank[yp])
	{
		parent[yp] = xp;
	}
	else if(rank[xp] < rank[yp])
	{
		parent[xp] = yp;
	}
	else
	{
		parent[xp] = yp;
		rank[xp]++;
	}
}










///////////////////////////////////////////////






class Solution {
public:
    
    
    void addEdge(int src, int dest, int wt, vector<int> adj[])
    {
        adj[src].push_back({dest, wt});
    }
    int networkDelayTime(vector<vector<int>>& t, int N, int K) {
        
        
        vector<pair<int, int>> adj[N];
        
        for(int i = 0; i = N; i++)
        {
            addEdge[t[i][0]].push_back({t[i][1], t[i][2]});
            
        }

        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> dist(N + 1, INT_MAX);

       	pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty())
        {
        	int u = pq.top().second;
        	pq.top();

        	for(auto x : adj[u])
        	{
        		int v = x.first;
        		int wt  = x.second;
        		if(dist[v] > dist[u] + wt)
        		{
        			dist[v] = dist[u] + wt;
        			pq.push({dist[v], v});
        		}
        	}




        }

        int ans = 0;

        for(int i = 1; i <=N; i++)
        {
        	if(dist[i] == INT_MAX) return -1;
        	ans = max(ans, dist[i]);
        }

        return ans;



    }
};