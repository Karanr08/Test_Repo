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



int V, E;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

int main()
{
	
}


string find_window(string s, string pat)
{
	int n = s.length();
	int m = pat.length();


	if(n < m)
		return "";


	int hashPat[256] = {0};
	int hashStr[256] = {0};


	for(int i = 0; i < m; i++)
	{
		++hashPat[pat[i]];
	}


	int l = 0, ansleft = -1, min_left = INT_MAX;


	int count = 0;

	for(int j = 0; j < n; j++)
	{
		hashStr[s[j]]++;


		if(hashPat[s[j]] != 0 && hashStr[s[j]] <= hashPat[s[j]])
			count++;

		if(count == m)
		{
			while(hashStr[s[l]] > hashPat[s[l]] || hashPat[s[l]] == 0)
			{
				if(hashStr[s[l]] > hashPat[s[l]])
					hashStr[s[l]]--;

				l++;
			}
		}

		int wind = j - l + 1;

		if(min_left > wind)
		{
			min_left = wind;
			ansleft = l;
		}
	}

	if(ansleft == -1)
		return "";
	return s.substr(ansleft, min_left);
}