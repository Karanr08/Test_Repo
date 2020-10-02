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


int maxHist(int row[])
{
	stack<int> result;

	int top_val;

	int max_area = 0;

	int area = 0;

	int i = 0;
	while(i < C)
	{
		if(result.empty() || row[result.top()] <= row[i])
		{
			result.push(i++);
		}
		else
		{
			top_val = row[result.top()];
			result.pop();
			area = top_val*i;
			if(!result.empty())
			{
				area = top_val * (i - result.top() - 1);

			}
			max_area = max(area, max_area);
		}
	}
	while (!result.empty()) { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
} 
}



int maxRectangle()
{
	int result = maxHist(A[0]);

	for(int i = 1; i < R; i++)
	{
		for(int j = 1; j < C; j++)
		{
			if(A[i][j])
				A[i][j] += A[i-1][j];
			result = max(result, maxHist(A[i]));
		}
	}

	return result;
}