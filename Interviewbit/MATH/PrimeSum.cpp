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




int Prime(int num)
{
    if(A == 1) return 0;

	lli uplmt = (lli) sqrt(A);
	for(lli i = 2; i <= uplmt; i++)
	{
		if(A % i == 0)
			return 0;
	}
	return 1;
}

vector<int> Solution::primesum(int n) {
    vector<bool> val;
    vector<int> sol;
    // unordered_map<int, bool> map;
    
    for(int i = 1; i <= n/2;i++)
    {
            // condition for i to be a prime number
            if (Prime(i))
            {
                    // condition for n-i to be a prime number
                    if (Prime(n-i))
                    {
                        sol.push_back(i);
                        sol.push_back(n - i);
                        return sol;
                      
                    }
            }    
    }
  
}
