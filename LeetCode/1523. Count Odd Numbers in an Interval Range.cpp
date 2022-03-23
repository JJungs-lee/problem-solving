class Solution {
public:
	int countOdds(int low, int high) {
		int lastest = (high & 1) & (low & 1);
		return lastest + (high - low + 1) / 2;
	}
};
