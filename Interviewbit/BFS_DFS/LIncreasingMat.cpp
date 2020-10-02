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

int dfs(vector<vector<int>> &m, vector<vector<int>> &v, int i, int j, int prev)
{



	if(i < 0 || j < 0 || j >= m[0].size() || j >= m.size() || prev >= m[i][j])
		return 0;

	if(v[i][j] != 0)
		return v[i][j];

	int a = dfs(m, v, i +  1, j, m[i][j]);
	int b = dfs(m, v, i , j - 1, m[i][j]);

	int c = dfs(m, v, i - 1, j, m[i][j]);
	int d = dfs(m, v, i , j + 1, m[i][j]);


	return v[i][j] = max(v[i][j], max(a, max(b, max(c, d)))) + 1;
}


int main()
{

	vector<vector<int>> m = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  
	vector<vector<int>> v;

	int n = m.size();
	int k  = m[0].size();

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			vector<int> temp(k, 0);
			v.push_back(temp);
		}
	}


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			dfs(m, v, i, j, INT_MIN);
		}
	}


	for(int i =0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}*/


int main()
{
	string s;
	cin >> s;

	int i = 0, ans = 0;
	unordered_map <char, int> um;

	for(int j = 0; j < s.length();j++)
	{
		um[s[j]]++;
		while(um['a'] && um['b'] && um['c'])
		{
			cout << um[s[i]] << "  I " << i << endl; 
			um[s[i]]--;

			i++;
			cout << um[s[i - 1]] << "L2  I " << i << endl; 
		}

		ans += i;
		cout << "ANS         " << ans << endl;
	}
}





powerSet(vector<char> v, int set_size)
{

	unsigned int pow_size = pow(2, set_size);
	int countet, j;
	for(counter = 0; counter < pow_size; counter++)
	{
		for(j = 0; j < set_size; j++)
		{
			if(counter & (1 << j))
				ans.push_back(v[j]);
		}
	}
}