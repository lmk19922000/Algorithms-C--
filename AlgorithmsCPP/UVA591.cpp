#include "stdio.h"
#include "iostream"
#include <stdlib.h> 

using namespace std;

int main(){
	int total, avg, sum, ans, count=1;
	int arr[100];

	while (scanf("%d", &total) != EOF){
		if (total == 0){
			break;
		}
		
		sum = 0;
		for (int i = 0; i < total; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
			//printf("sum: %d ", sum);
		}

		avg = sum / total;
		//printf("avg: %d ", avg);
		ans = 0;
		for (int i = 0; i < total; i++){
			ans += abs(avg-arr[i]);
		}

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", count, ans/2);
		count++;
	}
	return 0;
}