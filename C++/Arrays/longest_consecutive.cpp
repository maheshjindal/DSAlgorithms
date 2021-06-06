// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int currCount=1,maxCount = 1;
        for(int i=1; i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                currCount++;
            }else if(nums[i] != nums[i-1]){
                // only increase count for non duplicate element in an array
              currCount = 1;
            }
            if(currCount > maxCount)
                maxCount = currCount;
        }
        return maxCount;

    }
};