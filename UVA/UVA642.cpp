#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
	int count;
	string str, sortedStr;
	vector<pair<string, string>> vt;
	
	while(getline(cin, str)){
		if(str == "XXXXXX"){
			break;
		}
		
		sortedStr = str;
		
		sort(sortedStr.begin(), sortedStr.end());
		
		vt.push_back(make_pair(str, sortedStr));
	}
	
	sort(vt.begin(), vt.end());
	
	while(getline(cin, str)){
		if(str == "XXXXXX"){
			break;
		}
		
		sort(str.begin(), str.end());
		
		count = 0;
		for(int i = 0; i<vt.size(); i++){
			if(vt[i].second==str){
				printf("%s\n", vt[i].first.c_str());
				count++;
			}
		}
		if(count==0){
			printf("NOT A VALID WORD\n");
		}
		printf("XXXXXX\n");
	}
	
	return 0;
}