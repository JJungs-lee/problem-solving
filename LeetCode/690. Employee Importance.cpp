/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
	Employee emp[2001];
	int dfs(int cur_id) {
		Employee cur = emp[cur_id];
		if (!cur.subordinates.size())
			return cur.importance;

		int res = cur.importance;
		for (int i = 0; i < cur.subordinates.size(); ++i) {
			res += dfs(cur.subordinates[i]);
		}
		return res;
	}

public:
	int getImportance(vector<Employee*> employees, int id) {
		for (auto e : employees) {
			emp[e->id].id = e->id;
			emp[e->id].importance = e->importance;
			emp[e->id].subordinates = e->subordinates;
		}
		return dfs(id);
	}
};