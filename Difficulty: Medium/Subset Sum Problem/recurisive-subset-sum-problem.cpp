class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n,dp); 
        
        }
    bool solve(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(n==0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(arr[n-1]>sum)return dp[n-1][sum]=solve(arr,sum,n-1,dp);
        return dp[n-1][sum]= solve(arr,sum,n-1,dp)||solve(arr,sum-arr[n-1],n-1,dp);
    }
};
