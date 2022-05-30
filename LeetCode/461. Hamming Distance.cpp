class Solution {
public:
	int hammingDistance(int x, int y) {
		int xor_num = x ^ y;
		int distance = 0;
		while (xor_num != 0) {
			if (xor_num % 2 == 1)
				distance += 1;
			xor_num >>= 1;
		}
		return distance;
	}
};