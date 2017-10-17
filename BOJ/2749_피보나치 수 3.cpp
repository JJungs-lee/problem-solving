/*
	피보나치 수를 K로 나눈 나머지는 항상 주기를 가지게 됩니다. 이를 피사노 주기(Pisano Period)라고 합니다.

	피보나치 수를 3으로 나누었을 때, 주기의 길이는 8입니다.

	   n	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
	  Fn	0	1	1	2	3	5	8	13	21	34	55	89	144	233	377	610
	Fnmod3	0	1	1	2	0	2	2	1	0	1	1	2	0	2	2	1

	주기의 길이가 P 이면, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같습니다.

	M = 10^k 일 때, k > 2 라면, 주기는 항상 15 × 10^k-1 입니다. 이 사실을 모른다고 해도, 주기를 구하는 코드를 이용해서 문제를 풀 수 있습니다.
	이 문제에서 M = 10^6 이기 때문에, 주기는 15 × 10^5 = 1500000가 되겠네요.
*/

#include <iostream>
using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;

int fibo[p] = { 0, 1 };

int main() {

	long long n;
	cin >> n;
	
	for(int i = 2; i<p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}
	
	cout << fibo[n%p] << '\n';
	
	return 0;
}