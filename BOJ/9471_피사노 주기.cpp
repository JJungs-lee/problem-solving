/*
	1960년, IBM의 직원 Donald Wall은 피보나치 수열을 m으로 나눈 나머지가 주기를 이룬다는 것을 증명했다.

	예를 들어, 피보나치 수열의 처음 10개를 11로 나눈 예는 다음과 같다.

	n	1	2	3	4	5	6	7	8	9	10
	F(n)	1	1	2	3	5	8	13	21	34	55
	F(n) mod 11	1	1	2	3	5	8	2	10	1	0
	나머지를 이용해서 만든 수열은 주기가 나타날 수 있다. k(m)을 반복하는 부분 수열의 길이라고 했을 때, k(11) = 10임을 알 수 있다.

	Wall은 아래와 같은 여러가지 성질도 증명했다.

	m > 2인 경우에 k(m)은 짝수이다.
	임의의 짝수 정수 n > 2에 대해서, k(m) = n인 m이 항상 존재한다.
		k(m) ≤ m^2 - 1
		k(2^n) = 3×2^(n-1)
		k(5^n) = 4×5^n
		k(2×5^n) = 6n
	n > 2라면, k(10^n) = 15×10^(n-1)
 
*/
#include <iostream>

using namespace std;

int main() {
	int testCase;
	int n, m;
	cin >> testCase;

	while(testCase--) {
		cin >> n >> m;
		int m1, m2;
		m1 = m2 = 1;
		int period = 0; 

		//다시 처음의 1, 1이 나온다면 주기가 완성이 되었다는 말이니 종료를 하면 되고, 그동안 period가 카운팅되어 이만큼의 주기라는걸 알수있다.
		do {
			int temp = m1;
			m1 = m2;
			// (a + b) mod c = (a mod c + b mod c) mod c
			m2 = (temp + m2) % m;
			period++; 
		} while(!(m1 == 1 && m2 == 1));


		cout << n << " " <<period<< endl;
	}
	return 0;
}