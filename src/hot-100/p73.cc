#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
  static void fillRow(std::vector<std::vector<int>> &matrix, int row) {
    std::fill(matrix[row].begin(), matrix[row].end(), 0); 
  }

  static void fillColumn(std::vector<std::vector<int>> &matrix, int col) {
    for (size_t i = 0; i < matrix.size(); i++) {
      matrix[i][col] = 0;
    }
  }

public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    std::unordered_set<int> rows, cols;

    // Iterate through the matrix to find zeroes
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    // Fill the rows with zeroes
    for (const int row : rows) {
      fillRow(matrix, row);
    }

    // Fill the columns with zeroes
    for (const int col : cols) {
      fillColumn(matrix, col);
    }
  }
};