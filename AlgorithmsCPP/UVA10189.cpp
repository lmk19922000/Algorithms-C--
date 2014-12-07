#include "stdio.h"
#include "iostream"

using namespace std;

void findNeighbor(char[][100], char[][100], int, int);

int main(){
	int R, C, count=1;
	char arr[100][100];
	char mine[100][100];

	while (scanf("%d %d", &R, &C) != EOF){
		if (R == 0 && C == 0){
			break;
		}
			getchar();
		
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				scanf("%c", &arr[i][j]);
				//printf("%c", arr[i][j]);
			}
			getchar();
		}

		findNeighbor(arr, mine, R, C);
		if (count != 1){
			printf("\n");
		}
		printf("Field #%d:\n", count);
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				printf("%c", mine[i][j]);
				if (j == C - 1){
					printf("\n");
				}
			}
		}
		count++;
	}
	return 0;
}

void findNeighbor(char arr[][100], char mine[][100], int R, int C){
	int count;
	for(int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			//printf("%c", arr[i][j]);
			if (arr[i][j] == '*'){
				mine[i][j] = '*';
				continue;
			}
			count = 0;
			for (int k = -1; k <= 1; k++){
				for (int l = -1; l <= 1; l++){
					if (k == 0 && l == 0){
						continue;
					}
					if (i + k >= 0 && i + k < R &&j + l >= 0 && j + l < C){
						if (arr[i + k][j + l] == '*'){
							count++;
						}
					}
				}
			}
			mine[i][j] = char(int('0')+count);
		}
	}
}