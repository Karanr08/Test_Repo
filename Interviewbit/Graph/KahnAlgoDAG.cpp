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
void TopoSort()
{
	vector<int> in_degree(V, 0);

	for(int u = 0; u < V; u++)
	{
		for(auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			in_degree[*it]++;
		}
	}

	queue<int> q;
	for(int i = 0; i < V; i++)
	{
		if(in_degree[i] == 0)
			q.push(i);
	}

	int count = 0;

	vector<int> top_order;

	while(!q.empty())
	{
		int u = q.front();

		q.pop();

		top_order.push_back(u);
		for(auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			if(--in_degree[*it] == 0)
				q.push(*it);

			count++;
		}
	}

	if(count != V)
	{
		cout << "There is a cycle in graph" << endl;
		return false;
	}

	for(int i = 0; i < top_order.size(); i++)
	{
		cout << top_order[i] << " ";
	}
	cout << endl;
}*/

/*
int main()
{

	int A = 8;
	int B[6] = {1, 2, 3, 4, 5, 8};
	int C[6] = { 2, 3, 4, 5, 6, 7};
	vector<int> adj[A + 1];
    
    vector<int> in_degree(A + 1, 0);
    
    for(int i = 0; i < 6; i++)
    {
        
        adj[B[i]].push_back(C[i]);
        in_degree[C[i]]++;
    }
     for(int i = 1; i <=8; i++)
    {
        
        cout << in_degree[i] << "  " << i << endl;
    }
    
    queue<int> Q;
    
    for(int i = 1; i <= A; i++)
    {
        if(in_degree[i] == 0 )
        {
            Q.push(i);
        }
    }

    int count = 0;
    
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			if(--in_degree[*it] == 0)
				Q.push(*it);

			
		}
		count++;
        
        
        
    }
    cout << count << endl;
    if(count != A)
        return false;
    else
        return true;
}*/


int main()
{
	int x = ~(-5);
	cout << x << endl;
}