#include <cstdio>
#include <vector>
using namespace std;

void merge(vector<int>& v, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int copy = 0;
	vector<int> backup;

	while (i <= mid && j <= e) {
		if (v[i] < v[j]) {
			backup.push_back(v[i++]);
		} else {
			backup.push_back(v[j++]);
		}
	}
	while (i <= mid)
		backup.push_back(v[i++]);
	while (j <= e)
		backup.push_back(v[j++]);

	for (int tmp = s; tmp <= e; ++tmp) {
		v[tmp] = backup[copy++];
	}
}
void mergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		mergeSort(v, s, mid);
		mergeSort(v, mid + 1, e);
		merge(v, s, e);
	}
}

int main() {
	int n;
	int num;
	scanf("%d", &n);

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		v.push_back(num);
	}

	mergeSort(v, 0, n - 1);
	for (int k = 0; k < n; ++k) {
		printf("%d\n", v[k]);
	}
	return 0;
}