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

		ListNode* push_node = head;
		ListNode* cur = head->next;

		while (cur) {
			if (push_node->val == cur->val) {
				cur = cur->next;
				continue;
			}
			push_node->next->val = cur->val;
			push_node = push_node->next;
			cur = cur->next;
		}
		push_node->next = nullptr;
		return head;
	}
};