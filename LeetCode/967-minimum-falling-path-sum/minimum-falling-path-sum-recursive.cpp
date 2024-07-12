typedef long long ll;
typedef vector<vector<int>> vv32;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
class Solution {
private:
    ll minFallingPath(vv32 &grid, ll i, ll j, ll m, ll n,vv32 &dp) {
        if (i >= n || j >= m || i < 0 || j < 0) return LLONG_MAX;
        if (i == n - 1) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        ll ans = LLONG_MAX;
        ans = min(ans, minFallingPath(grid, i + 1, j, m, n,dp) + grid[i][j]);
        if (j + 1 < m) ans = min(ans, minFallingPath(grid, i + 1, j + 1, m, n,dp) + grid[i][j]);
        if (j - 1 >= 0) ans = min(ans, minFallingPath(grid, i + 1, j - 1, m, n,dp) + grid[i][j]);

    return dp[i][j]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        fast_cin();
        ll m = grid[0].size();
        ll n = grid.size();
        ll minSum = LLONG_MAX;
        vv32 dp(n,vector<int>(m,-1));
        for (ll j = 0; j < m; j++) {
            minSum = min(minSum, minFallingPath(grid, 0, j, m, n,dp));
        }
        return minSum;
    }
};
