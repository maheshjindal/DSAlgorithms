// https://leetcode.com/problems/palindrome-pairs/ 
// Complexity O(n^2 * k)

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        for(int i=0;i<words.size();i++){
            for(int j = i+1; j< words.size() ;j++){
                if(isPalindrome(words[i]+words[j])){
                    result.push_back({i,j});
                }
                if(isPalindrome(words[j]+words[i])){
                    result.push_back({j,i});
                }
            }
        }
        return result;  
    }
    bool isPalindrome(string s){
        int midInd = s.length()/2;
        for(int i=0; i<midInd;i++){
            if(s[i] != s[s.length() - 1 - i]){
                return false;
            }
        }
        return true;
    }
};