// https://leetcode.com/problems/palindrome-pairs/ 

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wmap;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
            wmap[words[i]] = i;
        for (int i = 0; i < words.size(); i++) {
            //Case 1: When one string is empty
            if (words[i] == "") {
                for (int j = 0; j < words.size(); j++) {
                    string& w = words[j];
                    if (isPal(w, 0, w.size()-1) && j != i) {
                        ans.push_back(vector<int> {i, j});
                        ans.push_back(vector<int> {j, i});
                    }
                }
                continue;
            }
            // CASE: 2 Find the reverse of the word and checks if its present in the map 
            string bw = words[i];
            reverse(bw.begin(), bw.end());
            if (wmap.find(bw) != wmap.end()) {
                int res = wmap[bw];
                if (res != i) ans.push_back(vector<int> {i, res});
            }
            //CASE: 3 Splits up a word into palindrome + non-palindrome substrings and check if reverse exists for non-palindrome word
            for (int j = 1; j < bw.size(); j++) {
                // Find the palindrome substring
                if (isPal(bw, 0, j-1)) {
                    string s = bw.substr(j, bw.size()-j);
                    // Check if the reversed substr exists in the map
                    if (wmap.find(s) != wmap.end())
                        ans.push_back(vector<int> {i, wmap[s]});
                }
                if (isPal(bw, j, bw.size()-1)) {
                    string s = bw.substr(0, j);
                     // Check if the reversed substr exists in the map
                    if (wmap.find(s) != wmap.end())
                        ans.push_back(vector<int> {wmap[s], i});
                }
            }
        }
        return ans;
    }
    
private:
    // Checks if the word is palindrome or not
    bool isPal(string& word, int i, int j) {
        while (i < j)
            if (word[i++] != word[j--]) return false;
        return true;
    }
};