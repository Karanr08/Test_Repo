/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> ump;


void StoreParent(TreeNode *root)

{

	queue<TreeNode*> q;

	q.push(root);


	while(!q.empty())
	{
		TreeNode *p = q.front();

		q.pop();

		if(p == root)
		{
			ump[p] = NULL;
		}


		if(p->left)
		{
			ump[p->left] = p;
			q.push(p->left);
		}

		if(p->right)
		{
			ump[p->right] = p;
			q.push(p->right);
		}
	}
}

vector<int> ans;

void TreeNodeataDistanceK(TreeNode *root, TreeNode *target, int K)
{
	unordered_set<TreeNode*> s;

	int dist = 0;

	queue<TreeNode*> q;

	q.push(target);
	s.insert(target);

	while(!q.empty())
	{
		if(dist == k)
		{
			while(!q.empty())
			{
				ans.push_back(q.front()->val);
				q.pop();
			}
		}

		int size = q.size();

		for(int i = 0; i < size; i++)
		{
			TreeNode *p = q.front();

			q.pop();

			if(p->left && s.find(p->left) == s.end())
			{
				q.push(p->left);
				s.insert(p->left);

			}
			if(p->right && s.find(p->right) == s.end())
			{
				q.push(p->right);
				s.insert(p->right);
			}

			if(ump[p] && s.find(ump[p]) == s.end())
			{
				q.push(ump[p]);
				s.insert(ump[p]);
			}

		}
		dist++;
	}
}
    vector<int> distanceK(TreeTreeNode* root, TreeTreeNode* target, int K) {
        
        TreeNodeataDistanceK(root, target, K);
        return ans;
        
        
    }
};