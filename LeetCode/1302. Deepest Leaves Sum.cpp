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
	int deepestLeavesSum(TreeNode* root) {
		int sum = 0;
		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty()) {
			sum = 0;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode* cur = q.front();
				q.pop();

				sum += cur->val;

				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return sum;
	}
};