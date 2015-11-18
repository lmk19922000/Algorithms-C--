#include <iostream>
#include <string>
#include <utility>
#include <stack>

using namespace std;

std::string PatternSearch(const unsigned char* pStr, const unsigned char* pMatch);

void main(){
	unsigned char searchStr[] = "a]bcccd[efgfg}2mnnmnn\\ 000";
	unsigned char pattern[] = "a\\]b[c]{3}d\\[e[[fg]{2}]{1}}[2]{1}[m[n]{2}]{2}\\";

	std:string ans = PatternSearch(&searchStr[0], &pattern[0]);
	cout << ans <<endl;
	
	getchar();
}

std::string PatternSearch(const unsigned char* pStr, const unsigned char* pMatch)
{
	// This function searches given null terminated string pStr by given subset of regular 
	// expression pMatch.
	// Return value is matched string appeared in pStr.
	// If nothing has matched, return value is empty string.
	//
	// The subset of regular expression grammar is defined as follows.
	//  - A string is set of 8-bit characters. Beware that it is not 7-bit.
	//  - The metacharacter \ is an escape character, that means any single letter appeared next 
	// used as is.
	//  - The characters in squared brackets metacharacters [ and ] is a sequence of literal 
	// characters or metacharacters.
	// Immediately after ], another metacharacters in curly braces { num } must be followed. 
	// The num is a sequence of
	// digits which specifies the number of times the previous literal character or 
	// metacharacter sequence in squared
	// brackets must be repeated.
	//  e.g. "abc[def]{2}ghi" matches "abcdefdefghi".
	//  - The squared brackets metacharacters can be nested.
	// e.g. "abc[def[ghi]{3}jkl]{2}mno matches "abcdefghighighijkldefghighighijklmno".
	//  - In case of matching pattern given by pMatch is a grammatical error, this function 
	// returns a string "ERROR".
	//
	// Complete rest of this function. Have fun!
	
	int numBrackets = 0;
	std::stack<pair<bool, char>> myStack;
	std::string patternString;	// The pattern to search in full string form

	std::string tempStr;
	std::string tempFullStr;
	std::string tempStrNum;
	bool prevIsEscapeInner = false;
	bool prevIsEscapeOutter = false;
	pair<bool, char> tempPair;
	int num;
	
	while ((char)*pMatch != '\0'){
		if ((char)*pMatch == '[' && !prevIsEscapeOutter){
			myStack.push(std::make_pair(false, (char)*pMatch));
			numBrackets++;
			pMatch++;
		}
		else if ((char)*pMatch == ']' && !prevIsEscapeOutter){
			tempStr.clear();
			tempStrNum.clear();
			tempFullStr.clear();

			if (!myStack.empty()){
				while ((myStack.top().second != '[') || (myStack.top().first && myStack.top().second == '[')){	// get the pattern to repeat
					tempPair = myStack.top();
					myStack.pop();
					tempStr.push_back(tempPair.second);

					if (myStack.empty()){
						return "ERROR";
					}
				}

				myStack.pop();	// pop the '[' character
				numBrackets--;
				
				pMatch++;
				if ((char)*pMatch == '\\'){	// ignore escape charater
					pMatch++;
				}

				if ((char)*pMatch != '{'){
					return "ERROR";
				}
				else {	//get the number to repeat
					pMatch++;
					prevIsEscapeInner = false;
					while ((char)*pMatch != '\0' && (char)*pMatch != '}'){
						if ((char)*pMatch == '\\' && !prevIsEscapeInner){
							pMatch++;
							prevIsEscapeInner = true;
							continue;
						}
						if (!isdigit((char)*pMatch)){
							return "ERROR";
						}
						tempStrNum.push_back((char)*pMatch);
						pMatch++;
					}

					if ((char)*pMatch != '}'){
						return "ERROR";
					}

					pMatch++;	// for next iteration

					num = atoi(tempStrNum.c_str());
					for (unsigned i = 0; i < num; i++){
						for (unsigned j = 0; j < tempStr.size(); j++){
							tempFullStr.push_back(tempStr[j]);
						}	
					}

					if (numBrackets == 0){	// append to the final pattern string directly
						for (int i = tempFullStr.size() - 1; i >= 0; i--){
							patternString.push_back(tempFullStr[i]);
						}
					}
					else{	// push back to the stack
						for (int i = tempFullStr.size() - 1; i >= 0; i--){
							myStack.push(std::make_pair(false, tempFullStr[i]));
						}
					}
				}
			}
			else{
				return "ERROR";
			}
		}
		else{
			if (*pMatch == '\\' && !prevIsEscapeOutter){
				prevIsEscapeOutter = true;
				pMatch++;
			}
			else{
				if (numBrackets == 0){
					patternString.push_back((char)*pMatch);
					pMatch++;
				}
				else if (numBrackets > 0){
					if (prevIsEscapeOutter){
						myStack.push(std::make_pair(true, (char)*pMatch));
					}
					else{
						myStack.push(std::make_pair(false, (char)*pMatch));
					}
					pMatch++;
				}
				else{
					return "ERROR";
				}

				prevIsEscapeOutter = false;
			}
			
		}
	}
	
	if (prevIsEscapeOutter){
		patternString.push_back('\\');
	}

	if (numBrackets > 0){
		return "ERROR";
	}
	
	std::string strToSearch;
	while ((char)*pStr != '\0'){
		strToSearch.push_back((char)*pStr);
		pStr++;
	}

	std::size_t found = strToSearch.find(patternString);
	if (found != std::string::npos){
		return patternString;
	}
	
	return "";
}