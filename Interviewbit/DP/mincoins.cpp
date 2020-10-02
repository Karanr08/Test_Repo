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
typedef pair<int, int> pi; 
typedef pair<int, pair<int, int>> ppi;



int mincoins(int coins[], int m, int V)
{
	int table[V + 1];
	table[0] = 0;

	for(int i = 1; i <=V; i++)
		table[i] = INT_MAX;
	for(int i = 1; i <= V; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(coins[j] <= i)
			{
				int sub_res = table[i - coins[j]];
				if(sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
		}
	}
	return table[V];
}