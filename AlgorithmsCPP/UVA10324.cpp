#include "stdio.h"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main(){
	string num, str;
	vector<int> myVector;
	int numQuery, x, y, temp, counter, ans;

	counter = 1;
	while (getline(cin, num)){
		myVector.clear();
		if (num == ""){
			break;
		}
		if (num.at(0) == '0'){
			myVector.push_back(0);
		}
		else{
			myVector.push_back(1);
		}
		//printf("%d ", myVector[0]);
		for (int i = 1; i < num.size(); i++){
			if (num.at(i) == '0'){
				myVector.push_back(myVector[i - 1] + 0);
			}
			else{
				myVector.push_back(myVector[i - 1] + 1);
			}
			//printf("%d ", myVector[i]);
		}
		//printf("\n");
		scanf("%d", &numQuery);
		printf("Case %d:\n", counter);
		for (int i = 0; i < numQuery; i++){
			scanf("%d", &x);
			scanf("%d", &y);
			getline(cin, str);
			if (x>y){
				temp = x;
				x = y;
				y = temp;
			}
			
			if (y >= num.size()){
				printf("No\n");
				continue;
			}
			if (x > 0){
				ans = myVector[y] - myVector[x - 1];
			}
			else{
				ans = myVector[y];
			}
			
			if (ans == 0 || ans == y - x + 1){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		counter++;
	}
	return 0;
}