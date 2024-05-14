#include <memory.h>

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
const int n = 9;
int arr[10];
bool check[10] = {
    false,
};

bool checkNum = true;
void DFS(int cnt, int sum) {
	if (cnt == 7 && sum == 100 && checkNum) {
		for (int i = 0; i < 7; ++i) {
			cout << vec[i] << endl;
		}
		checkNum = false;
		return;
	}

	for (int i = 0; i < 9; ++i) {
		if (!check[i] && sum + arr[i] <= 100) {
			check[i] = true;
			vec.push_back(arr[i]);
			DFS(cnt + 1, sum + arr[i]);
			check[i] = false;
			vec.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	memset(check, false, sizeof(check));
	DFS(0, 0);

	return 0;
}