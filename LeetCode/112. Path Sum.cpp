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
	bool checkTargetSum(TreeNode* cur, int diff) {
		if (!cur)
			return false;

		diff -= cur->val;

		if (!cur->left && !cur->right && diff == 0)
			return true;

		return checkTargetSum(cur->left, diff) || checkTargetSum(cur->right, diff);
	}

public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		return checkTargetSum(root, targetSum);
	}
};