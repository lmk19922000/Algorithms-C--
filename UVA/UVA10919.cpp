#include <iostream>
#include "stdio.h"
#include "ctype.h"
#include "string"
#include "vector"
#include <algorithm> 

using namespace std;

int main() {
	int numCourse, numCategory;
	vector<int> courseTaken;
	int course, category, count, require;
	bool quit, pass;

	while (scanf("%d", &numCourse) != EOF){
		if (numCourse == 0){
			break;
		}
		courseTaken.clear();
		scanf("%d", &numCategory);

		pass = true;
		for (int i = 0; i<numCourse; i++){
			scanf("%d", &course);
			courseTaken.push_back(course);
		}

		for (int i = 0; i<numCategory; i++){
			quit = false;
			scanf("%d %d", &category, &require);
			count = 0;
			if (count == require){
				quit = true;
			}
			for (int j = 0; j<category; j++){
				scanf("%d", &course);
				if (find(courseTaken.begin(), courseTaken.end(), course) != courseTaken.end()){
					//printf("%d\n", course);
					count++;
				}
				if (count == require){
					quit = true;
				}
			}
			if (!quit){
				pass = false;
			}
		}

		if (pass){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}