#include "iostream"
#include "stdio.h"
#include "string"
#include <ctype.h>

using namespace std;

int main(){
	string line;
	int i, j;
	bool flag;

	while (getline(cin, line)){
		if (line == "DONE"){
			break;
		}

		flag = false;
		i = 0;
		j = line.size() - 1;
		while (i < j){
			while (!isalpha(line[i])){
				i++;
			}
			while (!isalpha(line[j])){
				j--;
			}
			if (i >= j){
				break;
			}

			if (tolower(line[i]) != tolower(line[j])){
				//printf("%c\n", tolower(line[i]));
				//printf("%c\n", tolower(line[j]));
				flag = true;
				break;
			}
			i++;
			j--;
		}

		if (flag){
			printf("Uh oh..\n");
		}
		else
		{
			printf("You won't be eaten!\n");
		}
	}
	return 0;
}