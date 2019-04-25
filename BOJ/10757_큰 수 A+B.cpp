#include <iostream>
#include <string>

using namespace std;

int my_atoi(char c){
	return c - '0';
}

int main(){
    string a,b;
    string ret = "";
    cin >> a >> b;
    
    int i = a.length() -1;
    int j = b.length() -1;
    int carry = 0;

    while(i > -1 || j > -1 || carry != 0){
    	int plus_a = 0;
    	int plus_b = 0;
    	
    	if(i > -1) plus_a = my_atoi(a[i]);
    	if(j > -1) plus_b = my_atoi(b[j]);

    	int cur_sum = plus_a +plus_b + carry;

		carry = 0;
		while(cur_sum > 9){
			carry++;
			cur_sum -= 10;
		}

    	ret.insert(0,to_string(cur_sum));

    	if(i >= 0 ) i--;
    	if(j >= 0 ) j--;
    }
    cout<< ret <<endl;
    
    return 0;
}