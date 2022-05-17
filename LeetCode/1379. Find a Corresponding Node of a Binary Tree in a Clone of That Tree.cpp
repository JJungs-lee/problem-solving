/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		queue<TreeNode*> origin_q;
		queue<TreeNode*> clone_q;

		origin_q.push(original);
		clone_q.push(cloned);

		while (!origin_q.empty()) {
			TreeNode* origin_cur = origin_q.front();
			origin_q.pop();

			TreeNode* clone_cur = clone_q.front();
			clone_q.pop();

			if (origin_cur == target)
				return clone_cur;

			if (origin_cur->left) {
				origin_q.push(origin_cur->left);
				clone_q.push(clone_cur->left);
			}
			if (origin_cur->right) {
				origin_q.push(origin_cur->right);
				clone_q.push(clone_cur->right);
			}
		}
		return nullptr;
	}
};