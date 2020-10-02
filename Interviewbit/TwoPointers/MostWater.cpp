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
typedef pair<int, pair<int, int>> ppi;
/*

int main()
{
	int n;
	cin >> n;
	vector<int> height(n);

	for(int i = 0; i < n; i++)
	{
		cin >> height[i];
	}

	 int max_area = 1;
       
        int i = 0;
        int j = n - 1;
        
        while(i < j)
        {
            if(height[i + 1] > height[i])
            {
                i++;
            }
            if(height[j - 1] > height[j])
            {
                j--;
            }
            max_area = max(max_area, (j - i)*min(height[i], height[j]));
        }
        
        cout<< max_area;
}*/

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0)
            return 1;
        
        double temp = myPow(x, n/2);
        if(n%2 == 0)
        	return temp*temp;
        else{
        	if(n > 0)
        	return temp*temp*x;
        	else
        		return (temp*temp)/x;
        }
       
    }
};