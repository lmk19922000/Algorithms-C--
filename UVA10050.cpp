#include <iostream>
using namespace std;

int main() {
	int total, numDays, numParties, count;
	int h[100];
	bool days[3650];
	
	scanf("%d", &total);
	
	while(total--){
		scanf("%d", &numDays);
		scanf("%d", &numParties);
		
		for(int i = 0; i<numParties; i++){
			scanf("%d", &h[i]);
		}
		
		for(int i = 0; i<numDays; i++){
			days[i] = false;
		}
		
		for(int i = 0; i<numParties; i++){
			int j = h[i]-1;
			while(j<numDays){
				
				if((j+1)%7 != 6 && (j+1)%7 != 0){
					//printf("j: %d\n", j);
					days[j] = true;
				}
				j+= h[i];
			}
		}
		
		count = 0;
		for(int i = 0; i<numDays; i++){
			if(days[i]){
				//printf("i: %d\n", i);
				count++;
			}
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}
