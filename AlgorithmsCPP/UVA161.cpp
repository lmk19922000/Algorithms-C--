#include <stdio.h>
#include <iostream>

using namespace std;

const int SIZE = 5 * 3600 + 1;

int main(){
	bool time[SIZE];
	int count0=0, cycle, start, end, h, m, s, minCycle=SIZE;
	bool flag;
	for (int i = 0; i < SIZE; i++){
		time[i] = true;
	}

	while (scanf("%d", &cycle) != EOF){
		if (cycle == 0){
			count0++;

			if (count0 == 3){
				break;
			}
			
			if (count0 == 1){// Print
				flag = true;
				for (int i = minCycle-5; i < SIZE; i++){
					if (time[i]){
						h = i / 3600;
						m = (i - h * 3600) / 60;
						s = i - h * 3600 - m * 60;
						printf("%02d:%02d:%02d\n", h, m, s);
						flag = false;
						break;
					}
				}

				if (flag){
					printf("Signals fail to synchronise in 5 hours\n");
				}

				// Reinitialize for the next set
				for (int i = 0; i < SIZE; i++){
					time[i] = true;
				}
				minCycle = SIZE;
			}
		}
		else{
			count0 = 0;

			if (minCycle > cycle){
				minCycle = cycle;
			}

			for (int i = 0; i < SIZE; i++){
				start = (2 * i + 1)*cycle - 5;
				end = 2 * (i+1)*cycle-1;
				if (start >= SIZE){
					break;
				}

				for (int j = start; j <= end; j++){
					if (j < SIZE){
						time[j] = false;
					}
					else{
						break;
					}
				}
			}
		}
	}
	
	return 0;
}