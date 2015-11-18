#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	int total, num=1, numBus, currH, currM, min, busH, busM, waitMin, totalWait;
	string line, numStr, timeStr, tempStr;
	istringstream ss;
	
	scanf("%d", &total);
	getline(cin, line);
	
	while(total--){
		getline(cin, line);
		
		ss.clear();
		ss.str(line);
		getline(ss, numStr, ' ');
		numBus = atoi(numStr.c_str());
		getline(ss, timeStr, ' ');
		
		ss.clear();
		ss.str(timeStr);
		
		getline(ss, tempStr, ':');
		currH = atoi(tempStr.c_str());
		getline(ss, tempStr, ':');
		currM = atoi(tempStr.c_str());
		
		min = -1;
		while(numBus--){
			getline(cin, line);
			
			ss.clear();
			ss.str(line);
			getline(ss, timeStr, ' ');
			getline(ss, numStr, ' ');
			
			waitMin = atoi(numStr.c_str());
			
			ss.clear();
			ss.str(timeStr);
			getline(ss, tempStr, ':');
			busH = atoi(tempStr.c_str());
			getline(ss, tempStr, ':');
			busM = atoi(tempStr.c_str());
			
			totalWait = (busH-currH)*60+busM-currM;
			if(totalWait<0){
				totalWait+=24*60;
			}
			totalWait+=+waitMin;
			
			if(min>totalWait || min == -1){
				min=totalWait;
			}
		}
		
		printf("Case %d: %d\n", num, min);
		num++;
	}
	return 0;
}
