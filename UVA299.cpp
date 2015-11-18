#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	int total, num, swap;
	int arr[50];

	scanf("%d", &total);
	while (total--){
		scanf("%d", &num);
		for (int i = 0; i < num; i++){
			scanf("%d", &arr[i]);
			//printf("%d ", arr[i]);
		}
		swap = 0;
		for (int i = 0; i < num; i++){
			for (int j = i + 1; j < num; j++){
				if (arr[i]>arr[j]){
					swap++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", swap);
	}
	return 0;
}