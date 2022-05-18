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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> res;
		if (!root)
			return res;

		queue<TreeNode *> q;
		q.push(root);
		bool is_reverse = false;
		while (!q.empty()) {
			vector<int> level_v;
			int size = q.size();

			for (int i = 0; i < size; ++i) {
				TreeNode *cur = q.front();
				q.pop();
				level_v.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			if (is_reverse)
				reverse(begin(level_v), end(level_v));

			res.push_back(level_v);
			is_reverse ^= true;
		}
		return res;
	}
};