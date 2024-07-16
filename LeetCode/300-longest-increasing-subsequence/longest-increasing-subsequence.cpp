class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return lengthOfLISHelper(nums, -1, 0, memo);
    }
    
private:
    int lengthOfLISHelper(vector<int>& nums, int prevIndex, int currIndex, vector<vector<int>>& memo) {
        if (currIndex == nums.size()) return 0;
        
        if (memo[prevIndex + 1][currIndex] != -1) return memo[prevIndex + 1][currIndex];
        
        int taken = 0;
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            taken = 1 + lengthOfLISHelper(nums, currIndex, currIndex + 1, memo);
        }
        int notTaken = lengthOfLISHelper(nums, prevIndex, currIndex + 1, memo);
        
        memo[prevIndex + 1][currIndex] = max(taken, notTaken);
        return memo[prevIndex + 1][currIndex];
    }
};
