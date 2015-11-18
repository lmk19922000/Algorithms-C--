#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int total, ans1, ans2;
	int arr[4];
	int digit[8];
	scanf("%d", &total);

	while (total--){
		scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

		//printf("%d %d %d %d", num1, num2, num3, num4);
		ans1 = 0;
		for (int i = 0; i < 4; i++){
			ans1 += arr[i] % 10;
			arr[i] /= 10;
			digit[2 * i] = (arr[i] % 10)*2;
			arr[i] /= 10;
			ans1 += arr[i] % 10;
			arr[i] /= 10;
			digit[2 * i+1] = (arr[i] % 10) * 2;
		}

		ans2 = 0;
		for (int i = 0; i < 8; i++){
			while (digit[i] != 0){
				ans2 += digit[i] % 10;
				digit[i] /= 10;
			}
		}

		if ((ans1 + ans2) % 10 == 0){
			printf("Valid\n");
		}
		else{
			printf("Invalid\n");
		}
	}
	return 0;
}