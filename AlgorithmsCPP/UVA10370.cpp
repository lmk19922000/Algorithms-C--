#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	int total, num, sum, count;
	float avg;
	int arr[1000];

	scanf("%d", &total);

	while (total--){
		scanf("%d", &num);
		//printf("num: %d\n", num);
		sum = 0;
		for (int i = 0; i < num; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
			//printf("arr[%d]: %d\n", i, arr[i]);
		}

		avg = (float)sum / num;
		//printf("avg: %f\n", avg);
		count = 0;
		for (int i = 0; i < num; i++){
			if (arr[i]>avg){
				count++;
			}
		}

		printf("%.3f%%\n", (float)count / num * 100);
	}
	return 0;
}