#include<iostream>
#include<vector>
#include "../Utils/IOUtils.cpp"

using namespace std;

class CoordinateHelper{

public:
    std::vector<string> ambiguousCoordinates(string s) {
    	std::vector<string> v;
    	int n = s.length();

    	//Exclude braces from the input string
        s = s.substr(1,n-2);
        n = s.length();

    	for(int i=1; i<n; i++){
    		// take substring from 0 to i(exclusive)
    		vector<string> str1 = getPossibleDecimals(s,0,i);
    		vector<string> str2 = getPossibleDecimals(s,i,n);

    		// Generate all possible string pairs and push them to vector
    		for (auto x: str1)
    			for(auto y: str2)
    				v.push_back("("+x+", "+y+")");
    	}        
    	return v;
    }
private:
	/*
	* Generates the list of valid possible decimal numbers from the given string
	*/
	vector<string> getPossibleDecimals(string str, int from, int to){
		std::vector<string> v;
		string partStr = str.substr(from,to);
		int subStrLen = partStr.length();
		// The substr should not start with zero and shouldn't have more than one characters
		if(!(partStr[0] == '0' && partStr.length() > 1)){
			v.push_back(partStr);
		}
		for(int k=1; k < subStrLen;k++){
			string left = partStr.substr(0,k);
			string right = partStr.substr(k,subStrLen);
			if(!(left[0] == '0' && left.length() > 1) && !(right[right.length()-1] == '0')){
				v.push_back(left+ (right.length() > 0 ? ".":"")+right);
			}
		}
		return v;
	}
};

int main(){

	ioutils::enableFastIO();

	string s;
	cin >> s;
	
	assert(s.length() > 2 && s[0] == '(' && s[s.length()-1] == ')');
	CoordinateHelper* coordinateHelper = new CoordinateHelper();
	std::vector<string> coordinatesList = coordinateHelper -> ambiguousCoordinates(s);

	ioutils::print(coordinatesList);
	return 0;
}