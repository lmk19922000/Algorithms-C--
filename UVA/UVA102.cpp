#include "stdio.h"
#include "iostream"
#include "string"

using namespace std;

int main(){
	int b1, g1, c1, b2, g2, c2, b3, g3, c3, total;
	int max;
	string str;

	while (scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) != EOF){
		total = b1 + b2 + b3 + g1 + g2 + g3 + c1 + c2 + c3;
		max = b1 + g3 + c2;
		str = "BCG";
		if (max < b1 + g2 + c3){
			str = "BGC";
			max = b1 + g2 + c3;
		}
		if (max < b2 + g3 + c1){
			str = "CBG";
			max = b2 + g3 + c1;
		}
		if (max < b3 + g2 + c1){
			str = "CGB";
			max = b3 + g2 + c1;
		}
		if (max < b2 + g1 + c3){
			str = "GBC";
			max = b2 + g1 + c3;
		}
		if (max < b3 + g1 + c2){
			str = "GCB";
			max = b3 + g1 + c2;
		}
		
		printf("%s %d\n", str.c_str(), total - max);
	}
	return 0;
}