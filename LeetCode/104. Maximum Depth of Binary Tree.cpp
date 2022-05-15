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
	int top_down(TreeNode* cur, int depth) {
		if (cur == nullptr)
			return depth;

		int left_level = top_down(cur->left, depth + 1);
		int right_level = top_down(cur->right, depth + 1);

		return max(left_level, right_level);
	}

public:
	int maxDepth(TreeNode* root) {
		return top_down(root, 0);
	}
};