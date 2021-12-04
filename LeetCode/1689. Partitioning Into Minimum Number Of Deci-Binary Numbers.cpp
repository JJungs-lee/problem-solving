class Solution {
public:
	int minPartitions(string n) {
		/*
		 * max_element API - algorithm header
		 * Time Complexity - O(n)
		 */
		return *max_element(n.begin(), n.end()) - '0';
	}
};