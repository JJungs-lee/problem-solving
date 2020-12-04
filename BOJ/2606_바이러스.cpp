#include <iostream>
#include <stack>

using namespace std;

int map[101][101] = {
    0,
};
bool check[101] = {
    false,
};

int comCnt, connectCnt;
int ret = 0;
stack<int> s;

void DFS(int start) {
	s.push(start);
	check[start] = true;

	while(!s.empty()) {
		int v = s.top();
		s.pop();

		for (int i = 1; i <= comCnt; ++i) {
			if (map[v][i] && !check[i]) {
				s.push(i);
				check[i] = true;
				ret++;
			}
		}
	}
	
}

int main() {
	cin >> comCnt >> connectCnt;

	for (int i = 0; i < connectCnt; ++i) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	DFS(1);

	cout << ret;

	return 0;
}