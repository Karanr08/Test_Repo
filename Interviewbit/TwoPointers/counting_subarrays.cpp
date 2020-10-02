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
int countSubArrays(int arr[], int x, int n)
{
	int count = 0;
	int start = -1, end = -1;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] < x)
		{
			if(start == -1){
				start = i;
				end = i;
			}
			else{
				end = i;
			}
		}

		else
		{
			if(start != -1 && end != -1 )
			{
				int length = end - start + 1;
				count += (length*(length + 1))/2;
			}
			start = -1;
			end = -1;
		}

	}
	if(start != -1 && end != -1)
	{
		int length = end - start + 1;
		count += (length*(length + 1))/2;
	}
	return count;
}

*/

int countSubArrays(vector<int> arr, int x)
{
	int n = arr.size();

	int count = 0;
	int start = -1, end = -1;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] < x)
		{
			if(start = -1)
			{
				start = i;
				end = i;
			}
			else
				end = i;
		}
		else
		{
			if(start != -1 && end != -1)
			{
				int len = end - start + 1;
				count += (len*(len + 1))/2;
			}

		}
	}
	return count;
}
int  main()
{


}

int countTriangles(vector<int> arr)
{
	int n = arr.size();

	sort(arr.begin(), arr.end());

	int l, r, i;
	for(int i = n - 1; i >= 1; i--)
	{
		l = 0, r = i - 1;
		while(l < r)
		{
			if(arr[l] + arr[r] > arr[i])
			{
				count += r - l;
			}
			r--;
			else
				l++;
		}
	}

}