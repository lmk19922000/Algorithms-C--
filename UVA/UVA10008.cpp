#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
#include <ctype.h>
#include "vector"
#include <algorithm>

using namespace std;

int main(){
	int total;
	string line;
	map<char, int> m;
	map<char, int>::iterator it;
	vector<pair<int, char>> vt;
	char c;

	scanf("%d", &total);
	getline(cin, line);
	while (total--){
		getline(cin, line);

		for (int i = 0; i < line.size(); i++){
			c = toupper(line.c_str()[i]);
			if (!isalpha(c)){
				continue;
			}
			//printf("%c\n", c);
			it = m.find(c);
			if (it == m.end()){
				m[c] = 1;
			}
			else{
				m[c] += 1;
			}
		}
	}

	for (it = m.begin(); it != m.end(); it++){
		vt.push_back(make_pair(it->second, it->first));
	}

	sort(vt.begin(), vt.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2)
	{
		return (p1.first > p2.first ||
			(!(p2.first > p1.first) && p1.second < p2.second));
	});

	for (int i = 0; i < vt.size(); i++){
		printf("%c %d\n", vt[i].second, vt[i].first);
	}

	return 0;
}