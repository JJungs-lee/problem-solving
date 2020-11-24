#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m[15001];
int trieSize = 0;

void insertTrie(vector<string>& vec) {
	int num = 0;
	for (auto& s: vec) {
		if (m[num].find(s) == m[num].end()) {
			m[num][s] = ++trieSize;
			num = trieSize;
		} else {
			num = m[num][s];
		}
	}
}

void printTrie(int node, int depth) {
	for (auto& [s, i] : m[node]) {
		cout << string(depth * 2, '-') << s << endl;
		printTrie(i, depth+1);
	}
}

int main() { 
	int n;
	cin >> n;

	while(n--) {
		int k;
		cin >> k;
		vector<string> vec(k);

		for (auto& s : vec)
			cin >> s;

		insertTrie(vec);
	}
	printTrie(0, 0);

	return 0;
}