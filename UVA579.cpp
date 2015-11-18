#include "stdio.h"
#include "iostream"
#include <sstream>
#include "string"
#include "stdlib.h"

using namespace std;

int main(){
	string line;
	istringstream ss;
	string hour, min;
	int h, m;
	float ans;

	while (getline(cin, line)){
		//printf("%s\n", line.c_str());
		//ss.str("");
		ss.clear();
		ss.str(line);
		getline(ss, hour, ':');
		//cout << hour << '\n';
		getline(ss, min, ':');
		//cout << min << '\n';

		if (hour == "0" && min == "00"){
			break;
		}

		h = atoi(hour.c_str());
		m = atoi(min.c_str());
		
		h = h % 12;
		//printf("%s %s\n", hour.c_str(), min.c_str());
		//printf("%d %d\n", h, m);
		ans = (float)30 * h + (float)m/2 -6*m;
		if (ans<0){
			ans = -ans;
		}

		if (ans > 180){
			ans = 360 - ans;
		}
		printf("%.3f\n", ans);
	}
	
	
	return 0;
}