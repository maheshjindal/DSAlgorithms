// Recursive Naive Approach - https://leetcode.com/problems/minimum-number-of-refueling-stops/ 
// Time Complexity 2^n

#include<iostream>
using namespace std;

class Solution {
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int result = solve(target, startFuel, stations, 0, 0);
      if (result == INT_MAX) return -1;
      else return result;

    }

  int solve(int target, int nMilesCanBeCovered, vector<vector<int>>& stations, int hopCount, int currInd) {
    if (target <= nMilesCanBeCovered) {
      return hopCount;
    }
    if (currInd >= stations.size()) {
      return INT_MAX;
    }
    int result = INT_MAX;
    if (stations[currInd][0] <= nMilesCanBeCovered) {
      result = min(
      	solve(target, nMilesCanBeCovered + stations[currInd][1], stations, hopCount + 1, currInd + 1), 
      	solve(target, nMilesCanBeCovered, stations, hopCount, currInd + 1)
      	);
    }
    return result;
  }
};