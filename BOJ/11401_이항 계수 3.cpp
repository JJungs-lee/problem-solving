#if 0 
조합 - n개 중 서로 다른 r개를 선택하되 순서를 고려 안함
	nCr = n! / r! * (n-r)!

페르마의 소정리
	m이 소수인 경우에는 페르마의 소정리를 이용해서 구할 수 있습니다.

	m이 소수이고, a와 m이 서로소라면, a^m−1은 m으로 나눈 나머지는 1입니다.

	즉, 이 말은 a^m−1≡1(modm) 이라는 의미가 됩니다.

	따라서, a^m−1 = a * a^m−2 ≡ 1(mod m)이 되고

	a^m−2가 a * x ≡ 1(modm)을 만족하는 x가 되기 때문에, 역원은 a^m−2가 됩니다.

	즉, N!/(K!(N−K)!를 M = 1,000,000,007로 나눈 나머지를 구하는 문제입니다.

	A=N!, B=K!(N−K)! 이라고 한다면, A/B(modM)을 구해야 합니다.

	M이 소수이기 때문에, 페르마의 소정리를 이용할 수 있습니다. 따라서 ,구해야 하는 값은 A×B^M−2(modM)이 됩니다.

	어떤 수의 제곱은 로그 시간 만에 구할 수 있기 때문에, 다음과 같이 코드를 작성할 수 있습니다.

꿀팁 !!!
	(사칙연산에 모두 적용 가능하다)
	(a + b) % M = (a % M + b % M) % M
	(a - b) % M = (a % M - b % M) % M
	(a × b) % M = (a % M × b % M) % M
	(a / b) % M = (a % M × (1/b) % M) %M

#endif

#include <iostream>

using namespace std;

long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while(y > 0) {
		if(y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main() {
	int n, k;
	long long p = 1000000007LL;
	long long t1 = 1;
	long long t2 = 1;
	long long ans;
	cin >> n >> k;
	// n! 구하기
	for(int i = 1; i <= n; ++i) {
		t1 *= i;
		t1 %= p;
	}
	// K! 구하기
	for(int i = 1; i <= k; ++i) {
		t2 *= i;
		t2 %= p;
	}
	// (n-k)!구하기
	for(int i = 1; i <= n - k; ++i) {
		t2 *= i;
		t2 %= p;
	}
	long long t3 = mul(t2, p - 2, p);
	t3 %= p;
	ans = t1*t3;
	ans %= p;
	cout << ans << endl;

	return 0;
}