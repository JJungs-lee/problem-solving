/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	void dfs(vector<int>& v, TreeNode* cur) {
		if (cur == nullptr)
			return;
		if (!cur->left && !cur->right) {
			v.push_back(cur->val);
			return;
		}

		if (cur->left)
			dfs(v, cur->left);
		if (cur->right)
			dfs(v, cur->right);
	}

public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> leaf_v1, leaf_v2;
		dfs(leaf_v1, root1);
		dfs(leaf_v2, root2);

		if (leaf_v1.size() != leaf_v2.size())
			return false;

		for (int i = 0; i < leaf_v1.size(); ++i) {
			if (leaf_v1[i] != leaf_v2[i])
				return false;
		}
		return true;
	}
};