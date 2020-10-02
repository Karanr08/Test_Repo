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

struct TreeNode{
	int data;
	TreeNode *left, *right;
};


TreeNode *newNode(int data)
{
	TreeNode *node = new TreeNode();
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return node;
}

TreeNode* insert(TreeNode* node, int data)
{
	if(node == NULL)
		return newNode(data);
	if(data < node -> data)
	{
		node -> left = insert(node->left, data);
	}
	else if(data > node -> data)
	{
		node -> right = insert(node -> right, data);
	}

	return node;
}

vector<int> ans;
void TopView(TreeNode *root)
{

	if(root == NULL)
	{
		return ;
	}

	TreeNode* temp;

	queue<pair<TreeNode*, int>> Q;
	map<int, int> mp;
	Q.push({root, 0});
	while(!Q.empty())
	{
		temp = Q.front().first;
		int d = Q.front().second;
		Q.pop();



		if(mp.find(d) == mp.end())
		{
			ans.push_back(temp -> data);
			mp[d] = temp->data;
		}

		if(temp -> left)
		{
			Q.push({temp -> left, d - 1});
		}

		if(temp -> right)
		{
			Q.push({temp -> right, d + 1});
		}
	}

}


int main()
{
	int n;
	cin >> n;
	vector<int> Tree(n);

	for(int i = 0; i < n; i++)
	{
		cin >> Tree[i];
	}
	TreeNode *root = NULL;
	root = insert(root, Tree[0]);
	for(int i = 1; i < n; i++)
	{
		insert(root, Tree[i]);
	}

	TopView(root);
    for(int i = 0; i < ans.size(); i++)
    {
    	cout << ans[i] << " ";
    }

}


class Solution {
public:
    
    
    int dir[5] = {0, 1, 0, -1, 0};
   
    int find(int x, int parent[])
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }
    
    void Union(int x, int y, int parent[], int rank[])
    {

        int xp = find(x, parent);
        int yp = find(y, parent);
        
        if(rank[xp] > rank[yp])
            parent[yp] = xp;
        else if(rank[xp] < rank[yp])
            parent[xp] = yp;
        else
        {
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    int Count(int parent[], vector<vector<int>> &grid)
    {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {

            for(int j = 0; j < m; j++)
            {

                if(parent[i*m + j] == i*m + j && grid[i][j] == '1')
                    ans++;
            }
        }
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        vector<vector<int>> grid(m, vector<int>(n));
        int parent[n*m];
        int rank[n*m];
        for(int i = 0; i < n*m; i++)
        {

            parent[i] = i;
            rank[i] = 0;
        }
        vector<int> res;
        int x, y;
        int count = 0;
        for(int i = 0; i < positions.size(); i++)
        {
            x = positions[i][0];
            y = postions[i][1];
            int curr = x*n + y;
            if(!grid[x][y])
            	count++:
            grid[x][y] = 1;
            
            for(int k = 0; k < 4; k++)
            {
            	int r = x + dir[k];
            	int c = y + dir[k + 1];
            	int pos = x*n + c;
            	if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c])
            		Union(curr, pos, parent, rank);
            }
        }
        
        res.push_back(Count(parent, grid));
        

    }

    return res;
};