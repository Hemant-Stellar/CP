class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }

private:
    int solve(int i, int remaining, vector<int>& coins, vector<vector<int>>& dp) {
        if (remaining == 0) return 1;
        if (i >= coins.size() || remaining < 0) return 0;
        
        if (dp[i][remaining] != -1) return dp[i][remaining];
        
        int taken = solve(i, remaining - coins[i], coins, dp);
        int skipped = solve(i + 1, remaining, coins, dp);
        
        return dp[i][remaining] = taken + skipped;
    }
};
