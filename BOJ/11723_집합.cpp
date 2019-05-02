#include <stdio.h>
#include <cstring>

int main() {
	int oper_cnt;
	char op[11];
	int x;
	
	unsigned long long num = 0;
	
	scanf("%d",&oper_cnt);
	while(oper_cnt--){
		scanf("%s",&op);
		if(op[0] == 'a' && op[1] == 'd'){
			scanf("%d",&x);
			num |= (1<<x);
		}else if(op[0] == 'r'){
			scanf("%d",&x);
			num &= ~(1<<x);
		}else if(op[0] == 'c'){
			scanf("%d",&x);
			printf("%d\n", (num & (1<<x)) ==0? 0: 1);
		}else if(op[0] == 't'){
			scanf("%d",&x);
			num ^= (1<<x);
		}else if(op[0] == 'a' && op[1] == 'l'){
			num = (1<<21) -1;
		}else if(op[0] == 'e'){
			num = 0;
		}
	}
	
	return 0;
}