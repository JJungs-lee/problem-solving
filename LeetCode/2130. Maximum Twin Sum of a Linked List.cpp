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
	// time complex - O(n)
	// space complex - O(1)
	ListNode* findMiddleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head->next;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = nullptr;

		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	int pairSum(ListNode* head) {
		ListNode* mid_node = findMiddleNode(head);
		ListNode* cur = reverse(mid_node->next);
		// devide
		mid_node->next = nullptr;

		ListNode *node1 = head, *node2 = cur;
		int max_num = INT_MIN;
		while (node1 && node2) {
			max_num = max(node1->val + node2->val, max_num);
			node1 = node1->next;
			node2 = node2->next;
		}
		return max_num;
	}
};