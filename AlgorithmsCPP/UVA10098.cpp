#include <iostream>
#include "stdio.h"
#include "string"
#include "sstream"
#include <math.h>
#include "set"
#include "vector"

using namespace std;

void getPermutation(set<string>&, vector<bool>&, string&, string&);

int main() {
	int total;
	string line, str;
	set<string> mySet;
	set<string>::iterator it;
	
	scanf("%d", &total);
	getline(cin, line);

	while (total--){
		getline(cin, line);

		//printf("%s", line.c_str());
		mySet.clear();
		vector<bool> vt(line.size(), false);
		str = "";
		getPermutation(mySet, vt, line, str);
		
		for (it = mySet.begin(); it != mySet.end(); it++){
			printf("%s\n", (*it).c_str());
		}

		printf("\n");

	}
	return 0;
}

void getPermutation(set<string>& mySet, vector<bool>& vt, string &line, string &str){
	if (str.size() == line.size()){
		mySet.insert(str);
		return;
	}

	for (int i = 0; i < vt.size(); i++){
		if (!vt[i]){
			vt[i] = true;
			str.push_back(line[i]);
			getPermutation(mySet, vt, line, str);
			vt[i] = false;
			str.pop_back();
		}
	}
}