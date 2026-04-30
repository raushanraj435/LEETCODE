//Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int srow = 0;
        int erow = row - 1;
        int scol = 0;
        int ecol = col - 1;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }
            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }
            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};

int main() {
    // 1. Initialize a sample 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 2. Create an instance of the Solution class
    Solution sol;

    // 3. Call the spiralOrder function
    vector<int> result = sol.spiralOrder(matrix);

    // 4. Print the result
    cout << "Spiral Order: [ ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << " ]" << endl;

    return 0;
}