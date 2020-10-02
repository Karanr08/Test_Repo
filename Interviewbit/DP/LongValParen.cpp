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

	stack<char> stk;


	int n = s.length();

	int dp[n + 1] ={0};

	for(int i = 0; i < n; i++)
	{
		if(s[i] =='(')
			dp[i] = 0;
		else if (s[i] ==')' && s[i - 1] == '(')
			dp[i] = dp[i-2] + 2;
	}
	
}


{

	unordered_map <int, int> map;

	int p1 = 0, p2 = 0;

	int res = 0;

	int k = 2;

	while(p1 < s.length() && p2 < s.length())
	{
		while(p2 < s.length() && map.size() == k)
		{
			res = max(res, p2 - p1);
			map[s[p2]]++;
			p2++;
		}

		while(p1 < s.lenght() && map.size() == k + 1)
		{
			map[s[p1]]--;
			if(map[s[p1]] == 0)
				map.erase(s[p1]);

			p1++;
		}

		res = max(res, p2 - p1);
	}
	return res;
}