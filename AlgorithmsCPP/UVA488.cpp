#include "iostream"
#include "stdio.h"

using namespace std;

int main(){
	int total, am, fre;

	scanf("%d", &total);

	while (total--){
		scanf("%d %d", &am, &fre);
		while (fre--){
			for (int i = 1; i <= am; i++){
				for (int j = 0; j < i; j++){
					printf("%d", i);
				}
				printf("\n");
			}
			for (int i = am - 1; i>0; i--){
				for (int j = 0; j < i; j++){
					printf("%d", i);
				}
				printf("\n");
			}
			if (fre != 0){
				printf("\n");
			}
		}

		if (total != 0){
			printf("\n");
		}
	}
	return 0;
}