#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

const int SIZE = 8*60+1;

int main() {
	int total, start, end, max, startMax, count, currStart, order = 1, ansH, ansM, ansStartH, ansStartM;
	string line, startH, startM, endH, endM, word1, word2;
	istringstream ss;
	
	bool arr[SIZE];
	
	while(scanf("%d", &total) != EOF){
		for(int i =0; i<SIZE; i++){
			arr[i] = true;
		}
		
		getline(cin, line);
		while(total--){
			getline(cin, line);
			ss.clear();
			ss.str(line);
			getline(ss, word1, ' ');
			getline(ss, word2, ' ');
			
			ss.clear();
			ss.str(word1);
			getline(ss, startH, ':');
			getline(ss, startM, ':');
			
			ss.clear();
			ss.str(word2);
			getline(ss, endH, ':');
			getline(ss, endM, ':');
			//printf("%s %s %s %s\n", startH.c_str(), startM.c_str(), endH.c_str(), endM.c_str());
			
			start = (atoi(startH.c_str())-10)*60+atoi(startM.c_str());
			end = (atoi(endH.c_str())-10)*60+atoi(endM.c_str());
			
			for(int i = start; i<end; i++){
				arr[i] = false;
			}
		}
		
		max=0;
		startMax = -1;
		currStart = -1;
		count = 0;
		for(int i = 0; i<SIZE; i++){
			if(arr[i]){
				if(count==0){
					currStart = i;
				}
				count++;
			} else{
				if(i>0 && arr[i-1]){
					count++;
				}
				if(count>max){
					max = count;
					startMax = currStart;
				}
				count = 0;
			}
		}
		
		if(count>max){
			max = count;
			startMax = currStart;
		}
		max--;
		ansStartH = startMax/60+10;
		ansStartM = startMax%60;

		if(max>=60){
			ansH=max/60;
			ansM=max%60;
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", order, ansStartH, ansStartM, ansH, ansM);
			
		} else{
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", order, ansStartH, ansStartM, max);
		}
		
		order++;
	}
	return 0;
}
