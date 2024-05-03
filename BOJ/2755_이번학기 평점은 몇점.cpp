#include <iostream>
#include <string>
#include <iomanip>      // std::setiosflags

using namespace std;

struct data {
	string sub;
	int rate;
	string grade;
};

int main() {
	int num;
	float sum = 0;
	int gCount = 0; 
	data *d;

	cin >> num;

	d = new data[num];

	for (int i = 0; i < num; ++i) {
		cin >> d[i].sub >> d[i].rate >> d[i].grade;

		if (d[i].grade == "A+") { sum += (d[i].rate) * 4.3;  gCount += d[i].rate; }
		else if (d[i].grade == "A0") { sum += (d[i].rate) * 4.0;  gCount += d[i].rate; }
		else if (d[i].grade == "A-") { sum += (d[i].rate) * 3.7;  gCount += d[i].rate; }
		else if (d[i].grade == "B+") { sum += (d[i].rate) * 3.3;  gCount += d[i].rate; }
		else if (d[i].grade == "B0") { sum += (d[i].rate) * 3.0;  gCount += d[i].rate; }
		else if (d[i].grade == "B-") { sum += (d[i].rate) * 2.7;  gCount += d[i].rate; }
		else if (d[i].grade == "C+") { sum += (d[i].rate) * 2.3;  gCount += d[i].rate; }
		else if (d[i].grade == "C0") { sum += (d[i].rate) * 2.0;  gCount += d[i].rate; }
		else if (d[i].grade == "C-") { sum += (d[i].rate) * 1.7;  gCount += d[i].rate; }
		else if (d[i].grade == "D+") { sum += (d[i].rate) * 1.3;  gCount += d[i].rate; }
		else if (d[i].grade == "D0") { sum += (d[i].rate) * 1.0;  gCount += d[i].rate; }
		else if (d[i].grade == "D-") { sum += (d[i].rate) * 0.7;  gCount += d[i].rate; }
		else { sum += (d[i].rate) * 0.0;  gCount += d[i].rate; }
	}

	cout.precision(3);
	cout << setiosflags(ios::showpoint) << sum / gCount;

	return 0;
}

