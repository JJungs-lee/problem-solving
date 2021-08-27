#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Data {
public:
	int age;
	char name[101];
	int join_num;

	Data(int _age, char* _name, int _join_num): age(_age), join_num(_join_num) {
		strcpy(name, _name);
	}

	inline bool operator<(Data d) const {
		if (this->age < d.age) {
			return true;
		} else if (this->age == d.age) {
			return (this->join_num < d.join_num);
		} else {
			return false;
		}
	}
};

int main() {
	int n;
	int age;
	char name[101];
	vector<Data> d;

	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d %s", &age, name);
		d.push_back(Data(age, name, i));
	}

	sort(d.begin(), d.end());

	for (auto d_ : d) {
		printf("%d %s\n", d_.age, d_.name);
	}
	return 0;
}