#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<int> v[2001];
static bool visied[2001];

bool dfs(int idx, int depth) {
	if (depth == 4)
		return true;

	visied[idx] = true;
	bool checked = false;

	for (int j = 0; j < v[idx].size(); ++j) {
		int next = v[idx][j];

		if (!visied[next] && !checked) {
			visied[next] = true;
			checked = dfs(next, depth + 1);
			visied[next] = false;
		}
		if (checked) {
			return true;
		}
	}
	visied[idx] = false;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int to, from;

		cin >> to >> from;
		v[to].push_back(from);
		v[from].push_back(to);
	}

	bool is_okay = false;
	for (int i = 0; i < n; ++i) {
		is_okay = dfs(i, 0);
		if (is_okay) {
			break;
		}
	}
	cout << is_okay << endl;

	return 0;
}