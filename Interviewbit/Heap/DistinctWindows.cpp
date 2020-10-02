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



vector<int> countDistinct(int arr[], int k, int n)
{
	map<int, int> hm;
	vector<int> ans;
	int dis_count = 0;

	for(int i = 0; i < k; i++)
	{
		if(hm[arr[i]] == 0)
			dis_count++;
		hm[arr[i]] += 1;
	}
	ans.push_back(dis_count);

	for(int i = k; i < n; i++)
	{
		if(hm[arr[i - k]] == 1)
			dis_count--;
		hm[arr[i - k]] -=1;

		if(hm[arr[i]] == 0)
			dis_count++;


		hm[arr[i]] += 1;
		ans.push_back(dis_count);
	}
	return ans;


}

int main()
{
	vec

}