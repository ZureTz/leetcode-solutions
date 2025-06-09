#include <algorithm>
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
    bool firstRowHasZero = false, firstColHasZero = false;
    // Check if the first row has any zeroes
    for (size_t j = 0; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        firstRowHasZero = true;
        break;
      }
    }
    // Check if the first column has any zeroes
    for (size_t i = 0; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        firstColHasZero = true;
        break;
      }
    }

    // Iterate through the matrix to find zeroes (using first row and column as markers)
    for (size_t i = 1; i < matrix.size(); i++) {
      for (size_t j = 1; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0; // Mark the first column
          matrix[0][j] = 0; // Mark the first row
        }
      }
    }

    // Fill the rows based on the markers
    for (size_t i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        fillRow(matrix, i);
      }
    }

    // Fill the columns based on the markers
    for (size_t j = 1; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        fillColumn(matrix, j);
      }
    }

    // Finally, handle the first row and column if they had zeroes
    if (firstRowHasZero) {
      fillRow(matrix, 0);
    }

    if (firstColHasZero) {
      fillColumn(matrix, 0);
    }
  }
};