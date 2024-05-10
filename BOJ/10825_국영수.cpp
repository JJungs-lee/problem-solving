#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct people {
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(const people &a, const people &b) {
	if (a.korean != b.korean)
		return a.korean > b.korean;

	if (a.english != b.english)
		return a.english < b.english;

	if (a.math != b.math)
		return a.math > b.math;

	return a.name < b.name;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<people> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].name >> v[i].korean >> v[i].english >> v[i].math;
	}

	sort(v.begin(), v.end(), cmp);

	for (auto iter : v)
		cout << iter.name << '\n';
	return 0;
}