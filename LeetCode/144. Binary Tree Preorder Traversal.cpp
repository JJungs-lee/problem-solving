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
	vector<int> res;

	void traver(TreeNode* cur) {
		if (cur == nullptr)
			return;

		res.push_back(cur->val);
		traver(cur->left);
		traver(cur->right);
	}

public:
	vector<int> preorderTraversal(TreeNode* root) {
		traver(root);
		return res;
	}
};