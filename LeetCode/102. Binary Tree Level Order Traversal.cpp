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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;

		if (root == nullptr)
			return res;

		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> level_list;

			while (size--) {
				auto cur = q.front();
				q.pop();

				level_list.push_back(cur->val);

				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			res.push_back(level_list);
		}
		return res;
	}
};