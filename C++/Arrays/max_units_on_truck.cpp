// https://leetcode.com/problems/maximum-units-on-a-truck/
#include<iostream>
using namespace std;

class Solution {
public:
    static bool compareVectors(vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compareVectors);
        int nUnits = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            int minBoxes = min(truckSize, boxTypes[i][0]);
            truckSize -= minBoxes;
            // Update the units count
            nUnits += minBoxes * boxTypes[i][1];
            if (!truckSize) 
                return nUnits;
        }
        return nUnits;
    }
 
};