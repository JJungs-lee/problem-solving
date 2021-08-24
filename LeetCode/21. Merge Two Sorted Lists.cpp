/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* res = nullptr;
		ListNode* prev = nullptr;

		while (l1 || l2) {
			int l1_val = l1 ? l1->val : 999;
			int l2_val = l2 ? l2->val : 999;
			int min_num = min(l1_val, l2_val);

			ListNode* cur = new ListNode(min_num);

			if (!res)
				res = cur;
			if (prev)
				prev->next = cur;
			prev = cur;

			if (l1 && l1->val == min_num)
				l1 = l1->next;
			else if (l2 && l2->val == min_num)
				l2 = l2->next;
		}
		return res;
	}
};