/*A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
At least one digit.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.
*/

// start from the beginning (Excluding 0, 1)

#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;
bool isSign(char c){
	return (c == '+' || c == '-');
}
//"6e6.5"

bool isNumber(string s){
	bool valid = false;
	bool eFound = false;
	int n = s.length();
	bool dotFound = false;
	for(int i=0; i<n;i++){
		valid = false;
		valid = isdigit(s[i]);

		if((i == 0) && !valid && isSign(s[i]))
			valid = true;
		
		if(!valid && !eFound && (s[i] == 'e' || s[i]=='E')){
			eFound = true;
			if(i> 0 &&(isdigit(s[i-1]) || s[i-1] == '.')&& (i < n-1) && isdigit(s[i+1]))
				valid = true;
		}

		if(!valid && !dotFound && s[i] == '.'){
			dotFound = true;
           if((i>0 && isdigit(s[i-1])) || (i<n-1) && isdigit(s[i+1]))
            	valid = true;
		}
        if(!valid) return false;

	}
	return valid;
}


int main(){
	string s;
	cin >>s;
	cout << "IsValid: "<< isNumber(s)<<endl;
	return 0;
}