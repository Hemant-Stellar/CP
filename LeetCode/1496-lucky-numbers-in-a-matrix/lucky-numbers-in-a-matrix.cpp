class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> min_in_rows, max_in_columns;
    
    for (const auto& row : matrix) {
        min_in_rows.push_back(*min_element(row.begin(), row.end()));
    }

    for (int col = 0; col < matrix[0].size(); ++col) {
        int max_in_col = INT_MIN;
        for (int row = 0; row < matrix.size(); ++row) {
            max_in_col = max(max_in_col, matrix[row][col]);
        }
        max_in_columns.push_back(max_in_col);
    }

    vector<int> lucky_nums;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == min_in_rows[i] && matrix[i][j] == max_in_columns[j]) {
                lucky_nums.push_back(matrix[i][j]);
            }
        }
    }

    return lucky_nums;
}
};