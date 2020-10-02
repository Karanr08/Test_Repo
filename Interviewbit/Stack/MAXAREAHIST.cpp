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



int getMaxArea(int hist[], int n)
{
	stack<int> s;

	int max_area = 0;

	int tp;

	int area_with_top;

	int i = 0;

	while(i < n)
	{
		if(s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		else
		{
			tp = s.top();
			s.pop();

			area_with_top = hist[tp]*(s.empty() ? i : i - s.top() - 1);

			if(max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while(s.empty() == false)
	{
		tp = s.top();

		s.pop();
		area_with_top = hist[tp]*(s.empty() ? i : i - s.top() - 1);

		if(max_area < area_with_top)
			max_area = area_with_top;
	}
	return max_area;
}


int main()
{
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
	cout << getMaxArea(hist, 7) << endl;
}