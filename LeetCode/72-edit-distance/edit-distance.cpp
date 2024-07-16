class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();
        // Initialize a memoization table with -1
        vector<vector<int>> memo(N + 1, vector<int>(M + 1, -1));
        return solve(0, 0, word1, word2, memo);
    }
private:
    int solve(int i, int j, string& S1, string& S2, vector<vector<int>>& memo) {
        int N = S1.length();
        int M = S2.length();
        
        // If we have reached the end of both strings
        if (i == N && j == M) return 0;
        // If we have reached the end of S1, we need to insert all remaining characters of S2
        if (i == N) return M - j;
        // If we have reached the end of S2, we need to delete all remaining characters of S1
        if (j == M) return N - i;
        
        // If the subproblem is already solved
        if (memo[i][j] != -1) return memo[i][j];
        
        // If characters are the same, move to the next character in both strings
        if (S1[i] == S2[j]) {
            return memo[i][j] = solve(i + 1, j + 1, S1, S2, memo);
        } else {
            // Calculate the minimum number of operations
            int insertOp = solve(i, j + 1, S1, S2, memo) + 1;  // Insert a character
            int deleteOp = solve(i + 1, j, S1, S2, memo) + 1;  // Delete a character
            int replaceOp = solve(i + 1, j + 1, S1, S2, memo) + 1;  // Replace a character
            
            // Return the minimum of the three operations
            return memo[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }
};