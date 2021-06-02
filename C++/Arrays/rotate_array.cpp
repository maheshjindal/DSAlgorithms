// Problem: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(),sz=0;

        if(k == 0 || k == n){
            return;
        }
        if(k > n){
            k %= n;
        }
        int* cache = new int[k];
        for(int i = n-k;i<n;i++){
            cache[sz++] = nums[i];
        }
        for(int i = n-k-1; i>=0;i--){
            nums[i+k] = nums[i];
        }
        for(int j=0;j<sz;j++){
            nums[j] = cache[j];
        }
        delete[] cache;
    }
};