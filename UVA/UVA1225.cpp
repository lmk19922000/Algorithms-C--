#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
	int total, num;
	int arr[10];
	string str;
	scanf("%d", &total);

	while (total--){
		scanf("%d", &num);

		memset(arr, 0, sizeof(arr));
		while (num){
			//printf("%d\n", num);
			str = to_string(num);
			for (int i = 0; i < str.size(); i++){
				//printf("%d\n", str[i] - 48);
				arr[str[i] - 48]++;
			}
			num--;
		}

		for (int i = 0; i < 10; i++){
			if (i != 9){
				printf("%d ", arr[i]);
			}
			else{
				printf("%d\n", arr[i]);
			}
		}
	}
	return 0;
}