#include <iostream>
#include <vector>

using namespace std;

static int tmp[500001];
static int cnt;
static int n, k;

void merge(vector<int>& v, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r) {
		if (v[i] <= v[j])
			tmp[t++] = v[i++];
		else
			tmp[t++] = v[j++];
	}

	while (i <= q)
		tmp[t++] = v[i++];
	while (j <= r)
		tmp[t++] = v[j++];

	i = p;
	t = 1;
	while (i <= r) {
		cnt++;
		if (k == cnt)
			cout << tmp[t] << '\n';
		v[i++] = tmp[t++];
	}
}

void merge_sort(vector<int>& v, int p, int r) {
	if (p < r) {
		if (k <= cnt)
			return;

		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	merge_sort(v, 0, n - 1);

	if (k > cnt)
		cout << "-1\n";
	return 0;
}