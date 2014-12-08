#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	int x1, x2, x3, y1, y2, count1, count2, temp;
	bool quit;

	while (scanf("%d %d %d %d %d", &x1, &x2, &x3, &y1, &y2) != EOF){
		if (x1 == 0 && x2 == 0 && x3 == 0 && y1 == 0 && y2 == 0){
			break;
		}
		if (x2 > x1){
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (x3 > x1){
			temp = x1;
			x1 = x3;
			x3 = temp;
		}
		
		if (y2 > y1){
			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		quit = false;
		if (y2 > x1){
			for (int i = 1; i <= 52; i++){
				if (i != x1&&i!=x2&&i != x3&&i != y1&&i != y2){
					printf("%d\n", i);
					quit = true;
					break;
				}
			}
			if (quit){
				continue;
			}
		}
		if (y2 > x2&&y2 > x3){
			for (int i = 1; i <= 52; i++){
				if (i != x1&&i != x2&&i != x3&&i != y1&&i != y2 && i>x2&&i>x3){
					printf("%d\n", i);
					quit = true;
					break;
				}
			}
			if (quit){
				continue;
			}
		}
		if (y1 > x1 && (y2 < x2 || y2 < x3)){
			//printf("dcm");
			for (int i = 1; i <= 52; i++){
				if (i != x1&&i != x2&&i != x3&&i != y1&&i != y2 && i>x2&&i>x3 &&i>x1){
					printf("%d\n", i);
					quit = true;
					break;
				}
			}
			if (quit){
				continue;
			}
		}

		printf("-1\n");	
	}
	return 0;
}