#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int x, y, w, h;
	int ret;

	cin >> x >> y >> w >> h;

	ret = min(w - x, min(h - y, min(x, y)));
	cout << ret << endl;

	return 0;
}