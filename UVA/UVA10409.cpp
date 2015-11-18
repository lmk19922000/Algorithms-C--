#include "stdio.h"
#include "iostream"
#include "string"

using namespace std;

int main(){
	int num, face;
	string line;

	while (scanf("%d", &num) != EOF){
		if (num == 0){
			break;
		}

		getline(cin, line);
		face = 1;
		while (num--){
			getline(cin, line);
			if (line == "north"){
				if (face == 1){
					face = 5;
				}
				else if (face == 2){
					face = 1;
				}
				else if (face == 3){
					face = 5;
				}
				else if (face == 4){
					face = 5;
				}
				else if (face == 5){
					face = 6;
				}
				else if (face == 6){
					face = 2;
				}
			}
			else if (line == "east"){
				if (face == 1){
					face = 3;
				}
				else if (face == 2){
					face = 3;
				}
				else if (face == 3){
					face = 6;
				}
				else if (face == 4){
					face = 1;
				}
				else if (face == 5){
					face = 3;
				}
				else if (face == 6){
					face = 4;
				}
			}
			else if (line == "south"){
				if (face == 1){
					face = 2;
				}
				else if (face == 2){
					face = 6;
				}
				else if (face == 3){
					face = 2;
				}
				else if (face == 4){
					face = 2;
				}
				else if (face == 5){
					face = 1;
				}
				else if (face == 6){
					face = 5;
				}
			}
			else if (line == "west"){
				if (face == 1){
					face = 4;
				}
				else if (face == 2){
					face = 4;
				}
				else if (face == 3){
					face = 1;
				}
				else if (face == 4){
					face = 6;
				}
				else if (face == 5){
					face = 4;
				}
				else if (face == 6){
					face = 3;
				}
			}
		}
		printf("%d\n", face);
	}
	return 0;
}