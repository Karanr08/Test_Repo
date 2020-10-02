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


bool isValid(int count[], int k)
{
	int val = 0;
	for(int i = 0; i < 26; i++)
	{
		if(count[i] > 0)
			val++;
	}

	return (k>=val);
}


void kUniques(string s, int k)
{
	int u = 0;
	int n = s.length();

	int count[26];
	memset(count, 0, sizeof(count));

	for(int i = 0; i < 26; i++)
	{
		if(count[s[i] - 'a'] == 0)
			u++;
		count[s[i] - 'a']++;
	}


	if ( u < k)
	{
		return ;
	}

	int curr_start = 0, curr_end = 0;

	int max_wnidow_size = 1, max_window_start = 0;

	memset(count, 0, sizeof(count));


	count[s[0] - 'a']++;

	for(int i = 1; i < n; i++)
	{
		count[s[i] - 'a']++;
		curr_end++;

		while(!isValid(count, k))
		{
			count[s[curr_start] - 'a']--;
			curr_start++;
		}

		if(curr_end - curr_start + 1 > max_wnidow_size)
		{
			max_wnidow_size = curr_end - curr_start + 1;
			max_window_start = curr_start;
		}
	}

	
}