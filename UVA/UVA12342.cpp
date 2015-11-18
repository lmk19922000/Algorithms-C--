#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	int total, count=1;
	long int amount;
	double tax;

	scanf("%d", &total);

	while (total--){
		scanf("%li", &amount);
		//printf("%li\n", amount);
		if (amount <= 180000){
			tax = 0;
		}
		else {
			amount -= 180000;
			if (amount <= 300000){
				tax = (double)amount / 10;
				//printf("1 %f\n", tax);
			}
			else{
				amount -= 300000;
				tax = 30000;
				if (amount <= 400000){
					tax += (double)amount / 100 * 15;
					//printf("2 %f\n", tax);
				}
				else{
					amount -= 400000;
					tax += 4000*15;
					if (amount <= 300000){
						tax += (double)amount / 5;
						//printf("3 %f\n", tax);
					}
					else{
						amount -= 300000;
						tax += 60000;
						//printf("4 %f\n", tax);
						tax += (double)amount / 4;
						//printf("5 %lf\n", tax);
					}
				}
			}
		}

		if (tax > 0 && tax < 2000){
			tax = 2000;
		}

		if (tax != ceil(tax)){
			tax = ceil(tax);
		}

		printf("Case %d: %.0lf\n", count, tax);
		count++;
	}

	return 0;
}