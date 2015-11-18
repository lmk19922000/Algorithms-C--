#include "stdio.h"
#include "iostream"

using namespace std;

int main(){
	char c;

	c = getchar();
	while (c != EOF){
		if (c == '\n'){
			putchar(c);
		}
		else{
			putchar(c - 7);
		}
		c = getchar();
	}

	return 0;
}