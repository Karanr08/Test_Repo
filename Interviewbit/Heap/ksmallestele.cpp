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




int main()
{
	vector<int> arr = {1, 1, 1, 3, 2, 2, 4};

	priority_queue<pi, vector<pi>, greater<pi> > minh;
	unordered_map<int, int> ump;

	for(int i = 0; i < arr.size(); i++)
	{
		ump[arr[i]]++;
	}
	int k;
	cin >> k;
	for(auto i = ump.begin(); i != ump.end(); i++)
	{
		minh.push(make_pair(i->second, i->first));
		if(minh.size() > k)
			minh.pop();
	}
	for(int i = 0; i < minh.size() ; i++)
	{
		cout << minh.top().second << "-->>   " << minh.top().first << endl;
		minh.pop();
	}
	cout << endl;
}