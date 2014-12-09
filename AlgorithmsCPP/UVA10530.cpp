#include "stdio.h"
#include "iostream"
#include "string"

using namespace std;

int main(){
	string line;
	int guess;
	int min, max;
	
	while(scanf("%d", &guess) != EOF)
	{
		if (guess == 0){
			break;
		}
		getline(cin, line);

		min = 0; max = 11;
		while (getline(cin, line)){
			if (line == "right on"){
				if (min >= max - 1 || guess<=min || guess>=max){
					printf("Stan is dishonest\n");
				}
				else{
					//printf("max: %d\n", max);
					//printf("min: %d\n", min);
					printf("Stan may be honest\n");
				}
				break;
			}

			if (line == "too high"){
				if (max > guess){
					max = guess;
					//printf("max: %d\n", max);
				}
			}

			if (line == "too low"){
				if (min < guess){
					min = guess;
					//printf("min: %d\n", min);
				}
			}

			scanf("%d", &guess);
			getline(cin, line);
		}
	}

	return 0;
}