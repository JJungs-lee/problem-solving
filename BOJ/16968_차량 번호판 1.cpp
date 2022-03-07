#include <iostream>

using namespace std;

#define NUM 1
#define ALPHA 2
#define DEFAULT_NUM 10
#define DEFAUTL_ALPHA 26

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num_cnt = DEFAULT_NUM;
	int alpha_cnt = DEFAUTL_ALPHA;
	int ret = 1;
	int status = 0;
	string str;
	cin >> str;

	for (auto c: str) {
		switch(c) {
			case 'c': {
				status == ALPHA? ret *= (DEFAUTL_ALPHA -1): ret *= DEFAUTL_ALPHA;
				status = ALPHA;
				break;
			}
			case 'd': {
				status == NUM? ret *= (DEFAULT_NUM - 1): ret *= DEFAULT_NUM;
				status = NUM;
				break;
			}
		}
	}
	cout << ret << endl;
	return 0;
}