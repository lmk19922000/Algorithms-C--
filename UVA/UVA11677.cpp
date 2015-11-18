#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	int h1, m1, h2, m2, start, end;
	
	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)!=EOF){
		if(h1==0 &&h2==0&&m1==0&&m2==0){
			break;
		}
		
		start = h1*60+m1;
		end=h2*60+m2;
		int ans = end-start;
		if(ans>0){
			printf("%d\n", ans);
		} else{
			printf("%d\n", 24*60+ans);
		}
	}
	
	return 0;
}
