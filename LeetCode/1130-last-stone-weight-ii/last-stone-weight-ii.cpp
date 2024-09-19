class Solution {
vector<vector<int>> dp;
int solve(vector<int>& stones,int index, int cSum,int &target,int &sum){
    if(cSum>=target|| index >= stones.size()){
        return abs(sum-(2*cSum));
    }
    if(dp[index][cSum]!=-1) return dp[index][cSum];
    return dp[index][cSum] = min(solve(stones,index+1,cSum+stones[index],target,sum),solve(stones,index+1,cSum,target,sum));
}
public:
    int lastStoneWeightII(vector<int>& stones) {
       int  n = stones.size();
       int sum = accumulate(stones.begin(),stones.end(),0);
       int target = ceil(sum/2);
        dp.resize(n+1,vector<int>(target+1,-1));
       return solve(stones,0,0,target,sum);
    }
};