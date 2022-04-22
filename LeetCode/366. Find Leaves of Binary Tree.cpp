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
   public:
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> res;

		while (root->left || root->right) {
			vector<int> collect_leaf;

			dfs(root, collect_leaf);
			res.push_back(collect_leaf);
		}
		res.push_back({root->val});

		return res;
	}

	bool dfs(TreeNode* cur, vector<int>& collect_leaf) {
		if (!cur->left && !cur->right)
			return true;

		if (cur->left && dfs(cur->left, collect_leaf)) {
			collect_leaf.push_back(cur->left->val);
			cur->left = nullptr;
		}

		if (cur->right && dfs(cur->right, collect_leaf)) {
			collect_leaf.push_back(cur->right->val);
			cur->right = nullptr;
		}
		return false;
	}
};