//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    DFS(grid, visited, i, j, n, m);
                    ++islandCount;
                }
            }
        }
        
        return islandCount;
    }
    
private:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) {
        // Directions arrays for 8 possible movements (vertical, horizontal, diagonal)
        static int rowDir[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        static int colDir[] = {0, 1, 0, -1, -1, 1, -1, 1};
        
        // Stack for the DFS
        stack<pair<int, int>> s;
        s.push({x, y});
        
        visited[x][y] = true;
        
        while (!s.empty()) {
            pair<int, int> current = s.top();
            s.pop();
            
            int currX = current.first;
            int currY = current.second;
            
            // Check all 8 possible directions
            for (int k = 0; k < 8; ++k) {
                int newX = currX + rowDir[k];
                int newY = currY + colDir[k];
                
                if (isValid(grid, visited, newX, newY, n, m)) {
                    visited[newX][newY] = true;
                    s.push({newX, newY});
                }
            }
        }
    }
    
    bool isValid(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !visited[x][y]);
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends