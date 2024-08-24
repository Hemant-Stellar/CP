class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r,
               int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == '0' || visited[r][c])
            return;
        visited[r][c]= true;
        for(int i=0;i<4;i++){
            solve(grid,visited,r+dx[i],c+dy[i]);
        }
        
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), count = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (!visited[r][c] && grid[r][c] == '1') {
                    count++;
                    solve(grid, visited, r, c);
                }
            }
        }
        return count;
    }
};