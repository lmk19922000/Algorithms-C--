#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
	int n, m, num=1;
	string sol, ans, line;
	bool WA, PE;
	vector<int> solLen, ansLen;
	
	while(scanf("%d", &n) != EOF){
		if(n==0){
			break;
		}
		
		getline(cin, line);
		
		solLen.clear();
		sol = "";
		for(int i = 0; i<n; i++){
			getline(cin, line);
			solLen.push_back(line.size());
			sol+=line;
		}
		
		scanf("%d", &m);
		getline(cin, line);
		
		ansLen.clear();
		ans="";
		for(int i = 0; i<m; i++){
			getline(cin, line);
			ansLen.push_back(line.size());
			ans+=line;
		}
		
		//printf("%s\n", sol.c_str());
		//printf("%s\n", ans.c_str());
		
		WA=false; PE=false;
		if(n!=m){
			PE = true;
		} else{
			if(sol.size() != ans.size()){
				PE = true;
			} else{
				for(int i = 0; i<solLen.size(); i++){
					if(solLen[i] !=ansLen[i]){
						PE = true;
						break;
					}
				}
				if(!PE){
					for(int i = 0; i<sol.size(); i++){
						if(sol[i]!=ans[i]){
							PE=true;
							break;
						}
					}
				}
			}
		}
		
		string::iterator itSol = sol.begin();
		string::iterator itAns = ans.begin();
		
		while(itSol!=sol.end() || itAns!= ans.end()){
			while(!isdigit(*itSol) && itSol != sol.end()){
				itSol++;
			}
			while(!isdigit(*itAns) && itAns != ans.end()){
				itAns++;
			}
			
			if(itSol == sol.end() && itAns == ans.end()){
				break;
			}
			
			if((itSol != sol.end() && itAns == ans.end()) || (itAns != ans.end() && itSol == sol.end()) || *itSol != *itAns){
				WA=true;
				break;
			}
			
			itSol++;
			itAns++;
		}
		
		if(WA){
			printf("Run #%d: Wrong Answer\n", num);
		} else if(PE){
			printf("Run #%d: Presentation Error\n", num);
		} else{
			printf("Run #%d: Accepted\n", num);
		}
		
		num++;
	}
	
	return 0;
}
