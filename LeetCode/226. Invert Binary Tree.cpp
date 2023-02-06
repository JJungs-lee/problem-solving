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
	void dfs(TreeNode* cur) {
		if (!cur || (!cur->left && !cur->right))
			return;

		if (cur->left)
			dfs(cur->left);
		if (cur->right)
			dfs(cur->right);

		swap(cur->left, cur->right);
	}

public:
	TreeNode* invertTree(TreeNode* root) {
		dfs(root);
		return root;
	}
};