#include "stdio.h"
#include "iostream"
#include "string"
#include "vector"
#include "map"

using namespace std;

int main(){
	vector<string> nameList;
	char name[13];
	int total, amount, dividend, counter = 0;
	map<string, int> map;

	while (scanf("%d", &total) != EOF){
		if (counter > 0){
			printf("\n");
		}
		counter++;
		nameList.clear();
		for (int i = 0; i < total; i++){
			scanf("%s", name);
			nameList.push_back(name);
			map[nameList[i]] = 0;
		}
		
		while (total--){
			scanf("%s", name);
			scanf("%d", &amount);
			scanf("%d", &dividend);
			//printf("Name: %s\n", name);
			//printf("Amount: %d\n", amount);
			//printf("Dividend: %d\n", dividend);
			
			if (dividend != 0){
				map[string(name)] -= dividend*(amount / dividend);
				for (int i = 0; i < dividend; i++){
					scanf("%s", name);
					map[name] += amount / dividend;
				}
			}
		}

		for (int i = 0; i < nameList.size(); i++){
			printf("%s %d\n", nameList[i].c_str(), map[nameList[i]]);
		}
	}

	return 0;
}