#include<iostream>
using namespace std;

// Min cost to climb the tree - > LeetCode (https://leetcode.com/problems/min-cost-climbing-stairs/)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int dp[n];
    if (n == 1)
        return cost[0];
    dp[0] = cost[0];
    dp[1] = cost[1];
 
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]) ;
    }
     return min(dp[n - 2], dp[n - 1]);
    }
};