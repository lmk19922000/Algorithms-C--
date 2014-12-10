#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string line;
	bool isPalin, isMirror;
	map<char, char> myMap;
	myMap.insert(pair<char, char>('A', 'A'));
	myMap.insert(pair<char, char>('E', '3'));
	myMap.insert(pair<char, char>('H', 'H'));
	myMap.insert(pair<char, char>('I', 'I'));
	myMap.insert(pair<char, char>('J', 'L'));
	myMap.insert(pair<char, char>('M', 'M'));
	myMap.insert(pair<char, char>('L', 'J'));
	myMap.insert(pair<char, char>('O', 'O'));
	myMap.insert(pair<char, char>('S', '2'));
	myMap.insert(pair<char, char>('T', 'T'));
	myMap.insert(pair<char, char>('U', 'U'));
	myMap.insert(pair<char, char>('V', 'V'));
	myMap.insert(pair<char, char>('W', 'W'));
	myMap.insert(pair<char, char>('X', 'X'));
	myMap.insert(pair<char, char>('Y', 'Y'));
	myMap.insert(pair<char, char>('Z', '5'));
	myMap.insert(pair<char, char>('1', '1'));
	myMap.insert(pair<char, char>('2', 'S'));
	myMap.insert(pair<char, char>('3', 'E'));
	myMap.insert(pair<char, char>('5', 'Z'));
	myMap.insert(pair<char, char>('8', '8'));

	while (getline(cin, line)){
		isPalin = true;
		isMirror = true;

		line.erase(line.find_last_not_of(" \n\r\t") + 1);
		for (int i = 0; i < line.size() / 2 + 1; i++){
			if (line[i] != line[line.size() - 1 - i]){
				//printf("%d %c %c\n", i, line[i], line[line.size() - 2 - i]);
				isPalin = false;
				break;
			}
		}

		for (int i = 0; i < line.size() / 2 + 1; i++){
			if (myMap.find(line[i]) == myMap.end() || myMap[line[i]] != line[line.size() - 1 - i]){
				isMirror = false;
				break;
			}
		}

		if (!isPalin && !isMirror){
			printf("%s -- is not a palindrome.\n", line.c_str());
		}
		else if (isPalin && !isMirror){
			printf("%s -- is a regular palindrome.\n", line.c_str());
		}
		else if (!isPalin && isMirror){
			printf("%s -- is a mirrored string.\n", line.c_str());
		}
		else{
			printf("%s -- is a mirrored palindrome.\n", line.c_str());
		}
		printf("\n");
	}
	return 0;
}