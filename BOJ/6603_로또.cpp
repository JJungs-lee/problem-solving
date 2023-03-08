#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		vector<bool> visited(v.size(), false);
		for (int i = 0; i < 6; i++)
			visited[i] = true;

		do {
			for (int i = 0; i < v.size(); ++i) {
				if (visited[i])
					cout << v[i] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(visited.begin(), visited.end()));

		cout << '\n';
	}

	return 0;
}
