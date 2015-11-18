#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	int total, num=1, wStartH, wStartM, wEndH, wEndM, mStartH, mStartM, mEndH, mEndM, wStart, wEnd, mStart, mEnd, cum=1;
	char arr[6];
	string timeStr1,timeStr2, tempStr;
	istringstream ss;
	
	scanf("%d", &total);
	
	while(total--){
		scanf("%s", arr);
		timeStr1=string(arr);
		
		ss.clear();
		ss.str(timeStr1);
		
		getline(ss, tempStr, ':');
		wStartH = atoi(tempStr.c_str());
		getline(ss, tempStr, ':');
		wStartM = atoi(tempStr.c_str());
		
		scanf("%s", arr);
		timeStr2=string(arr);
		
		ss.clear();
		ss.str(timeStr2);
		
		getline(ss, tempStr, ':');
		wEndH = atoi(tempStr.c_str());
		getline(ss, tempStr, ':');
		wEndM = atoi(tempStr.c_str());
		
		scanf("%s", arr);
		timeStr1=string(arr);
		
		ss.clear();
		ss.str(timeStr1);
		
		getline(ss, tempStr, ':');
		mStartH = atoi(tempStr.c_str());
		getline(ss, tempStr, ':');
		mStartM = atoi(tempStr.c_str());
		
		scanf("%s", arr);
		timeStr2=string(arr);
		
		ss.clear();
		ss.str(timeStr2);
		
		getline(ss, tempStr, ':');
		mEndH = atoi(tempStr.c_str());
		getline(ss, tempStr, ':');
		mEndM = atoi(tempStr.c_str());
		
		wStart = wStartH*60+wStartM;
		wEnd = wEndH*60+wEndM;
		
		mStart = mStartH*60+mStartM;
		mEnd = mEndH*60+mEndM;
		
		if((wStart>=mStart &&wStart<=mEnd) || (wEnd>=mStart && wEnd<=mEnd) || (wEnd>=mEnd && wStart<=mStart) || (wEnd<=mEnd && wStart>=mStart)){
			printf("Case %d: Mrs Meeting\n", num);
		} else{
			printf("Case %d: Hits Meeting\n", num);
		}
		
		num++;
	}
	return 0;
}
