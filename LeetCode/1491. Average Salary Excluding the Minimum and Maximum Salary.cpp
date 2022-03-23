class Solution {
public:
	double average(vector<int>& salary) {
		double max_n = 0;
		double min_n = 987654321;
		double sum = 0;

		for (double n : salary) {
			max_n = std::max(max_n, n);
			min_n = std::min(min_n, n);
			sum += n;
		}
		return (sum - max_n - min_n) / (salary.size() - 2);
	}
};