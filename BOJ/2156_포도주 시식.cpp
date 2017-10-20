#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[10001];
int dp[10001];


int main() {
	
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> graph[i];
	}
	dp[1] = graph[1];
	dp[2] = graph[1] + graph[2];

	// 3���� ���
	// 1. �ȸ��ô°�� >> dp[n] = dp[n-1]
	// 2. �̹����ʰ� 1�ܿ��� ���ô� ��� 
	//    ��, n-1��°�� ������ �ʰ� �׾Ʒ��� ���̴��� �� 
    //	    >> dp[n] = dp[n-2] + graph[n]
	// 3. �̹����ʰ� 2�ܿ��� ���ô� ��� 
	//    ��, n-1�� ���̰�, n-2�� ���ø� �ȵ�(����3�� ��������)
	//      >> dp[n] = graph[n] + graph[n-1] + dp[n-3]

	for(int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 1], max(graph[i] + dp[i - 2], graph[i] + graph[i - 1] + dp[i - 3]));
	}
	cout << dp[n] << endl;
	return 0;
}