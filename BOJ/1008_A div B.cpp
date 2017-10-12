#include <iostream>
#include <limits>

using namespace std;

int main(){

	double a, b;
	double num;

	cin >> a >> b;

	num = a / b;

	cout.precision(15);
	//if (num > std::numeric_limits<double>::epsilon()) 
	cout << a / b << endl;

	return 0;
}