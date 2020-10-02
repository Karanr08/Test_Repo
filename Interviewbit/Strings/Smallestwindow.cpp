
/*
GFG

Given a string, find the smallest window length with all distinct characters of the given string. 
For eg. str = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .
*/





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



string find(string s)
{
	int u = 0;
	vector<int> count(256, 0);

	set<char> st;

	int n = s.length();

	for(int i = 0; i < n; i++)
	{
		if(count[s[i]] == 0)
			u++;
		count[s[i]]++;
	}

	int start = 0, min_len = INT_MAX, start_idx = -1;
	vector<int> cur_count(256, 0);
	int c = 0;

	for(int j = 0; j < n; j++)
	{
		

		if(cur_count[s[j]] == 0)
			c++;
		cur_count[s[j]]++;

		

		if(c == u)
		{
			while(cur_count[s[start]] > 1)
			{
				if(cur_count[s[start]] > 1)
					cur_count[s[start]]--;
				start++;


			}

			int len_window = j - start + 1;

			if(min_len > len_window)
			{
				min_len = len_window;
				
				start_idx = start;
			}
		}
	}

	return s.substr(start_idx, min_len);
}

int main()
{

	string s;
	cin >> s;
	cout << find(s) << endl;

}