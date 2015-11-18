#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	int matrix[100][100];
	int prefix[100][100];
	int N;
	long max, sum;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (j == 0){
				prefix[i][j] = matrix[i][j];
			}
			else{
				prefix[i][j] = prefix[i][j - 1] + matrix[i][j];
			}
			//printf("%d ", prefix[i][j]);
		}
	}

	max = -1000000000;
	for (int i = 1; i <= N; i++){
		//printf("i: %d\n", i);
		for (int j = 1; j <= N; j++){
			//printf("j: %d\n", j);
			for (int k = 0; k <= N - i; k++){
				//printf("k: %d\n", k);
				for (int l = 0; l <= N - j; l++){
					//printf("l: %d\n", l);
					sum = 0;
					for (int m = k; m < k+i; m++){
						if (l == 0){
							sum += prefix[m][l + j-1];
						}
						else{
							sum += prefix[m][l + j-1] - prefix[m][l-1];
						}
					}
					//printf("sum: %li\n", sum);
					if (sum>max){
						max = sum;
					}
				}
			}
		}
	}

	printf("%li\n", max);
	return 0;
}