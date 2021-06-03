// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = max(horizontalCuts[0], h - horizontalCuts.back()),
            maxv = max(verticalCuts[0], w - verticalCuts.back());
        
        for (int i = 1; i < horizontalCuts.size(); i++)
            maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
        
        for (int i = 1; i < verticalCuts.size(); i++)
            maxv = max(maxv, verticalCuts[i] - verticalCuts[i-1]);
        
        return (int)((long)maxh * maxv % 1000000007);
    }
};