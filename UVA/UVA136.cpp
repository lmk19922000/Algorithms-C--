#include "stdio.h"
#include "iostream"
#include <queue>
#include <functional>

using namespace std;

int main(){
	long long num, temp;
	int count;
	priority_queue<long long, vector<long long>, greater<long long> > heap;

	heap.push(1);
	count = 0;
	num = 0;
	while (count < 1500){
		while (!heap.empty()){
			temp = heap.top();
			
			heap.pop();

			if (temp != num){
				num = temp;
				//printf("%lli\n", temp);
				break;
			}
		}
		
		heap.push(num * 2);
		heap.push(num * 3);
		heap.push(num * 5);

		count++;
	}

	printf("The 1500'th ugly number is %d.\n", num);
}