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


double power(int x, int y)
{
	double temp;
	if(x == 0)
		return 0;
	if( y == 0)
	{
		return 1;
	}

	temp = power(x, y/2);
	if(y%2 == 0)
		return temp*temp;
	else{

		if(y > 0)
			return x*temp*temp;
		else
			return (temp*temp) / x;
	}

		
}

int main()
{
	double ans;
	int x, y;
	cin >> x >> y;
	ans = power(x, y);

	int d;
	cin >> d;
	if (ans < 0)
	{
		cout << (int)(d - ans)%d << endl;
	}
	else
		cout << (int)ans % d << endl;
}