#include "stdio.h"
#include "iostream"
#include "vector"

using namespace std;

int main(){
	int total, count, min, dis;
	vector<int> vtR;
	vector<int>  vtD;
	char c;

	while (scanf("%d", &total) != EOF){
		//printf("total: %d\n", total);
		if (total == 0){
			break;
		}

		count = 0;
		min = -1;
		total++;
		vtR.clear();
		vtD.clear();
		while (total--){
			scanf("%c", &c);
			//printf("%c ", c);
			
			if (c == 'Z'){
				min = 0;
			}
			else if (c == 'R'){
				if (vtD.size() > 0){
					dis = count - vtD[vtD.size() - 1];
					//printf(" vl %d %d ", dis, min);
					if (min == -1 || dis < min){
						//printf(" hehe ");
						min = dis;
					}
				}

				vtR.push_back(count);
			}
			else if (c == 'D'){
				if (vtR.size() > 0){
					dis = count - vtR[vtR.size() - 1];
					//printf(" dm %d %d ", dis, min);
					if (min == -1 || dis < min){
						min = dis;
					}
				}

				vtD.push_back(count);
			}
			//printf(" %d ", min);
			count++;
		}

		printf("%d\n", min);
	}
	return 0;
}