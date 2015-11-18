#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	string line;
	long long int h1, m1, s1, c1, h2, m2, s2, c2, total;
	
	while(getline(cin, line)){
		h1=atoi(line.substr(0,2).c_str());
		m1=atoi(line.substr(2,2).c_str());
		s1=atoi(line.substr(4,2).c_str());
		c1=atoi(line.substr(6,2).c_str());
		
		total = h1*360000+m1*6000+s1*100+c1;
		//printf("%lli\n", total);
		total = total*100000/(24*3600);
		//printf("%lli\n", total);
		
		h2=total/1000000;
		total%=1000000;
		m2=total/10000;
		total%=10000;
		s2=total/100;
		total%=100;
		c2=total;
		//printf("%02d%02d%02d%02d\n", h1, m1, s1, c1);
		printf("%01lli%02lli%02lli%02lli\n", h2, m2, s2, c2);
	}
	
	return 0;
}
