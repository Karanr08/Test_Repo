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


int main()
{
	string s;
	cin >> s;

	int n = s.length();

	bool strTable[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			strTable[i][j] = false;
		}
	}
	int maxlength = 1;

	for(int i = 0; i < n; i++)
	{
		strTable[i][i] = true;
	}

	int start = 0;

	for(int i = 0; i < n -1; i++)
	{
		if(s[i] == s[i + 1]){
			strTable[i][i + 1] = true;
			start = i;
			maxlength = 2;
		}

	}

	for(int k = 3; k <= n; k++)
	{
		for(int i = 0; i < n - k + 1; i++)
		{
			int j = i + k - 1;

			if(strTable[i + 1][j - 1] && str[i] == str[j])
			{
				strTable[i][j] = true;

				if(k > maxlength)
				{
					start = i;
					maxlength = k;
				}
			}
		}
	}
}