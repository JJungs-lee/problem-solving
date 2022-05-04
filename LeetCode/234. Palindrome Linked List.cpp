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
	ListNode* reverse(ListNode* head) {
		ListNode *prev = nullptr, *cur = head, *next = nullptr;

		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	ListNode* findMiddleNode(ListNode* head) {
		ListNode *slow = head, *fast = head->next;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	bool isPalindrome(ListNode* head) {
		ListNode* middle_node = findMiddleNode(head);

		ListNode* p1 = head;
		ListNode* p2 = reverse(middle_node->next);

		middle_node->next = nullptr;

		while (p1 && p2) {
			if (p1->val != p2->val)
				return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		return true;
	}
};