
//Exactly K distinct chars GFG

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
int kDis(string s, int k)
{
	int n = s.length();

	if(n*k == 0)
		return 0;


	vector<int> count(256, 0);

	int i = 0, ans = 0, j = 0;
	int u = 0;


	while(j < n)
	{
		if(count[s[j]] == 0)
			u++;
		count[s[j]]++;


		if(u <= k && j - i + 1 > ans)
		{
			ans = j - i + 1;
		}
		while(u > k)
		{
			count[s[i]]--;
			if(count[s[i]] == 0)
				u--;
			i++;
		}

		j++;

	}

	return ans;

}

*/
int main()
{

	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.length();

	set<char> st(k);

	string X = "";
	int len = 0;
	
	for(int i = 0; i < k; i++)
	{
		st.insert(s[i]);
	}

	X += st.front();
	st.erase(st.front());


	for(int j = k; j < n; j++)
	{
		
	}

}
	

