#include "stdio.h"
#include "iostream"
#include <set>

using namespace std;

int main(){
	int a, b, num, count1, count2;
	set<int> setA, setB;
	set<int>::iterator it;

	while (scanf("%d %d", &a, &b) != EOF){
		if (a == 0 && b == 0){
			break;
		}

		setA.clear();
		setB.clear();
		count1 = count2 = 0;
		for (int i = 0; i < a; i++){
			scanf("%d", &num);
			setA.insert(num);
		}

		for (int i = 0; i < b; i++){
			scanf("%d", &num);
			setB.insert(num);
		}

		for (it = setA.begin(); it != setA.end(); it++){
			if (setB.find(*it) == setB.end()){
				count1++;
			}
		}

		for (it = setB.begin(); it != setB.end(); it++){
			if (setA.find(*it) == setA.end()){
				count2++;
			}
		}

		if (count1 < count2){
			printf("%d\n", count1);
		}
		else{
			printf("%d\n", count2);
		}
	}

	return 0;
}