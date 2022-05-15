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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return head;

		ListNode* res = head;
		ListNode* cur = head->next;

		while (cur) {
			if (res->val == cur->val) {
				cur = cur->next;
				continue;
			}

			res->next->val = cur->val;
			res = res->next;
			cur = cur->next;
		}
		res->next = nullptr;

		return head;
	}
};