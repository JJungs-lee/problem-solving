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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ret = nullptr, *prev = nullptr;
		int carry = 0;

		while (l1 || l2 || carry) {
			carry += (l1 ? l1->val : 0);
			carry += (l2 ? l2->val : 0);
			ListNode* cur = new ListNode(carry % 10);

			carry /= 10;
			if (!ret)
				ret = cur;
			if (prev)
				prev->next = cur;
			prev = cur;

			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}

		return ret;
	}
};