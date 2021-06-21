// https://leetcode.com/problems/pascals-triangle/


#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        result.push_back({1});
        
        if(numRows == 1)
            return result;
        
        for(int i=2; i<=numRows; i++){
            vector<int> currRow = {1};
            vector<int> prevRow = result.back();
            for(int j=0;j<prevRow.size()-1;j++)
                currRow.push_back(prevRow[j] + prevRow[j+1]);
            currRow.push_back(1);
            result.push_back(currRow);
        }
        return result; 
    }
};