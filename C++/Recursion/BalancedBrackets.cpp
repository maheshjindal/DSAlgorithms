/**
* Generate Balanced Brackets for a given number 'n' where means the number of pairs of brackets
*/

#include<iostream>
using namespace std;

class BracketHelper{

public:
	void generateBrackets(char* outBuffer, int idx, int openingCount, int closingCount, int n){
	
	// Base case when buffer is filled
	if(idx == 2*n){
		outBuffer[idx] = '\0';
		cout << outBuffer << endl;
	}

	// If openingCount limit is not reached add the opening bracket to the buffer
	if(openingCount < n){
		outBuffer[idx] = '(';
		generateBrackets(outBuffer,idx+1,openingCount+1,closingCount,n);

	}

	// Add the closing brace if possible
	if(openingCount > closingCount && openingCount <= n){
		outBuffer[idx] = ')';
		generateBrackets(outBuffer,idx+1,openingCount, closingCount+1,n);
	}
	return;
}

};

int main(){
	int n;
	cin >> n;
	char outBuffer[1000];
	BracketHelper* bracketHelper = new BracketHelper();
	bracketHelper->generateBrackets(outBuffer,0,0,0,n);
	return 0;
}