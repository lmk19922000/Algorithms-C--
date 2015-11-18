#include "stdio.h"
#include "iostream"
#include <string.h>

using namespace std;

int find(int[], int);

int main(){
	int arr[1000000];
	int num;

	memset(arr, 0, sizeof(arr));

	while (scanf("%d", &num) != EOF){
		if (num == 0){
			break;
		}
		printf("f91(%d) = %d\n", num, find(arr, num));
	}

	return 0;
}

int find(int arr[1000000], int num){
	//printf("%li ", num);

	if (arr[num] != 0){
		return arr[num];
	}

	if (num <= 100){
		return(find(arr, find(arr, num + 11)));
	}
	else{
		return num - 10;
	}
}