/*
	�Ǻ���ġ ���� ���ϴ� �� ������� = ��� ����� �̿�

	( Fn+2 )     =  (1  1) (fn+1)
	( Fn+1 )		(1  0) ( fn )   ���� ��Ÿ�� �� ����.

	����

	( Fn+2 )     =  (1  1) (fn+1)  = (1  1)^2 ( fn ) = (1  1)^3 (fn-1) = ... = (1  1)^n (f1)
	( Fn+1 )		(1  0) ( fn )    (1  0)   (fn-1)   (1  0)   (fn-2)		   (1  0)   (f2)

	��,
	( Fn+1 )  = (1  1)^n-1 ( 1 )
	(  Fn  )	(1  0)     ( 1 )
	
	�Ǵ� 
	( Fn+1  Fn  ) = (1  1)^n
	(  Fn  Fn-1 )	(1  0)    
*/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long> > matrix;
const long long mod = 1000000007LL;

matrix operator * (const matrix&a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

int main() {
	long long n;
	cin >> n;

	if(n <= 1) {
		cout << n << endl;
		return 0;
	}
	//ans �� �������
	matrix ans = { { 1, 0 }, { 0, 1 } };
	matrix a = { { 1, 1 }, { 1, 0 } };
	while(n > 0) {
		if(n % 2 != 0) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}
	cout << ans[0][1] << endl;
	return 0;
}