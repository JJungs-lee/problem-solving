#include <iostream>
#include <math.h>
using namespace std;

int main(){

	int testCase;
	cin >> testCase;

	while(testCase--){
		double x1, y1;		//시작점
		double x2, y2;		//도착점
		int n;			//행성의 개수

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		// 행성 중심, 반지름
		int ret = 0;
		double cx, cy, r;

		/*한원에 대한 도착지와 어린왕자의 상태는 총 4가지.
			1. 어린왕자가 원 안에 있을 경우
			1 - 1) 도착지도 원 안에 있다 == 카운트 x
			1 - 2) 도착지는 원 밖에 있다 == 카운트 o

			2. 어린왕자가 원 밖에 있다.
			2 - 1) 도착지는 원 안에 있다 == 카운트 o
			2 - 2) 도착지도 원 밖에 있다 == 카운트 x
		*/
		for(int i = 0; i < n; ++i){
			cin >> cx >> cy >> r;
			double a = sqrt(pow(cx - x1, 2) + pow(cy - y1, 2));
			double b = sqrt(pow(cx - x2, 2) + pow(cy - y2, 2));
			if(a<r && b>r){
				ret++;
			} else if(a > r && b < r){
				ret++;
			}
		}
	
		cout << ret << endl;

	}

	return 0;
}