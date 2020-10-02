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

void sortedMatrixSearch(int mat[][MAX], int n, int m, int x)
{

	if(n == 1){
		binarySearch(mat, 0, 0, m - 1, x);
		return;
	}

	int i_low = 0;
	int i_high = n - 1;
	int j_mid = m/2;
	while((i_low + 1) < i_high)
	{
		int i_mid = (i_low + i_high)/2;

		if(mat[i_mid][j_mid] == x)
		{
			cout << "Found at (" << i_mid << ", "
                 << j_mid << ")"; 
            return; 
		}
		else if(mat[i_mid][j_mid] > x)
		{
			i_high = i_mid;
		}
		else
			i_low = i_mid;
	}

	if(mat[i_low][j_mid] == x)
		cout << "Found at (" << i_low << ","
             << j_mid << ")"; 
    else if (mat[i_low+1][j_mid] == x) 
        cout << "Found at (" << (i_low+1) 
             << ", " << j_mid << ")"; 

    else if (x <= mat[i_low][j_mid - 1])
    	binarySearch(mat, i_low, 0, j_mid - 1, x);
    else if (x >= mat[i_low][j_mid + 1] && x <= mat[i_low][m - 1])
    	binarySearch(mat, i_low, j_mid + 1, m - 1, x);
    else if(x <= mat[i_low + 1][j_mid - 1])
    	binarySearch(mat, i_low + 1, 0, j_mid - 1, x);
    else 
    	binarySearch(mat, i_low + 1, j_mid + 1, m - 1, x);
}

*/


int main()
{
	int arr[] = {5};

	int lower = lower_bound(arr, arr + 1, 5) -arr ;
	int high = upper_bound(arr, arr + 1, 5) - arr;
	cout << lower << endl;
	cout << high - 1 << endl;
	
	

}