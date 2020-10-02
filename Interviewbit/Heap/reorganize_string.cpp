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


string reorganizeString(string str)
{
	int freq[26] = {0};
	for(int i = 0; i < str.length(); i++)
	{
		freq[str[i] - 'a']++;
	}

	priority_queue<pair<int, char>> pq;

	for(int i = 0; i < 26; i++)
	{
		if(freq[i] != 0)
		{
			pq.push({freq[i], 'a' + i});
		}
	}

	string ans = "";
	
	while(!pq.empty())
	{
		int cnt1 = pq.top().first;
		char c1 = pq.top().second;
		pq.pop();

		if(!pq.empty())
		{
			int cnt2 = pq.top().first;
			char c2 = pq.top().second;

			pq.pop();
			ans += c1;
			ans += c2;
			cnt2--;
			cnt1--;
			if(cnt1)
				pq.push({cnt1, c1});
			if(cnt2)
				pq.push({cnt2, c2});
			continue;
		}

		if(ans.size() > 0 && ans[ans.size() - 1] == c1){
			return "";
		}
		ans += c1;
		cnt1--;
		if(cnt1)
			pq.push({cnt1, c1});
	}

	return ans;
}


int main()
{
	string str;
	cin >> str;
	cout << reorganizeString(str) << endl;
}