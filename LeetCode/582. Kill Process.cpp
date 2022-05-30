class Solution {
	unordered_map<int, vector<int>> hash;

public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		for (int i = 0; i < pid.size(); ++i)
			hash[ppid[i]].push_back(pid[i]);

		queue<int> q;
		vector<int> res;

		q.push(kill);
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			res.push_back(cur);
			for (int i = 0; i < hash[cur].size(); ++i) {
				q.push(hash[cur][i]);
			}
		}
		return res;
	}
};