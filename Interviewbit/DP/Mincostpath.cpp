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
#define R 3
#define C 3
int min(int x, int y, int z) 
{ 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
} 
void mincost(int COST[R][C], int m, int n)
{
	int dp[m+ 1][n + 1] ;
	memset(dp, 0, sizeof(dp));

	dp[1][1] = COST[0][0];

	for(int i = 1; i <=m; i++)
	{
		dp[i][1] = COST[i-1][0] + dp[i-1][1];
	}

	for(int i = 1; i <= n; i++)
	{
		dp[1][i] = dp[1][i - 1] + COST[0][i - 1];
	}

	for(int i = 2; i <= m; i++)
	{
		for(int j = 2; j <= n; j++)
		{
			dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + COST[i-1][j-1];
		}
	}

	for(int i = 0; i <=m; i++)
	{
		for(int j = 0; j <= n ; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};


struct cell
{
	int x;
	int y;
	int cost;
};


class mycomparison
{
public:
	bool operator() (const cell &lhs, const cell &rhs) const
	{
		return (lhs.cost > rhs.cost);
	}
};



int main()
{
	int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 

    mincost(cost, 3, 3);

}



// ******************NEW APPROACH*****************//

/*
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

*/


