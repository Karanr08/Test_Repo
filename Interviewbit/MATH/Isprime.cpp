
/*#define _CRT_SECURE_NO_WARNINGS
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


bool isPrime(int n)
{
	if (n == 1) return false;

	int uplmt = sqrt(n);
	for(int i = 2; i <= uplmt; i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

int gcd(int a, int b)
{
	if(a == 0)
		return b;

	return gcd(b%a, a); 
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << endl;

	cout << "LCM" << endl;
	cout << (n*m)/(gcd(n, m)) << endl;
}*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int findNumberOfLIS(vector<int>& nums) {
     int n = nums.size();
        
        if(n == 0)
            return 0;
        
        int lis[n];
        lis[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
        	lis[i] = 1;
           if(nums[i] > nums[i - 1])
           {
               lis[i] = 1 + lis[i-1];
           }
            else
                lis[i] = 1;
        }

        for(int i = 0; i < n; i++)
        {
        	cout << lis[i] << " ";
        }
        cout << endl;
        
        
        return *max_element(lis, lis + n);
   }
};
main(){
   Solution ob;
   vector<int> v = {2, 2, 2, 2, 2};
   cout << (ob.findNumberOfLIS(v));
}


///////////////////////////////


{
	int g[n][n];
	for(int i = 0; i < n; i++)
	{
		g[f[i][0]][f[i][1]] = f[i][2];
	}


	vector<int> dist(n+1, INT_MAX);


	dist[src] = 0;

	pq.push({0, src, 0});

	while(!pq.empty())
	{
		auto p = p.top();
		p.pop();

		int 
	}
}