#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	int total, num, count;
	char field[10][10];
	char played[10][10];
	char c;
	bool lose;

	scanf("%d", &total);

	while (total--){
		scanf("%d", &num);
		scanf("%c", &c);

		for (int i = 0; i < num; i++){
			for (int j = 0; j < num; j++){
				scanf("%c", &field[i][j]);
				//printf("%c ", field[i][j]);
			}
			scanf("%c", &c);
			//printf("\n");
		}

		for (int i = 0; i < num; i++){
			for (int j = 0; j < num; j++){
				scanf("%c", &played[i][j]);
				//printf("%c ", played[i][j]);
			}
			scanf("%c", &c);
			//printf("\n");
		}

		lose = false;
		for (int i = 0; i < num; i++){
			for (int j = 0; j < num; j++){
				if (played[i][j] == 'x'){
					if (field[i][j] == '*'){
						lose = true;
					}
					else
					{
						count = 0;
						// find number and display
						for (int k = -1; k <= 1; k++){
							for (int l = -1; l <= 1; l++){
								if (k == 0 && l == 0){
									continue;
								}
								if (i + k >= 0 && i + k < num &&j + l >= 0 && j + l < num){
									if (field[i+k][j+l] == '*'){
										count++;
									}
								}
							}
						}
						played[i][j] = char((int)'0' + count);
					}
				}
			}
		}

		if (lose){
			for (int i = 0; i < num; i++){
				for (int j = 0; j < num; j++){
					if (field[i][j] == '*'){
						played[i][j] = '*';
					}
				}
			}
		}
		
		for (int i = 0; i < num; i++){
			for (int j = 0; j < num; j++){
				printf("%c", played[i][j]);
			}
			printf("\n");
		}

		if (total != 0){
			printf("\n");
		}
	}
	return 0;
}