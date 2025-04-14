#include <iostream>
#include <vector>
using namespace std;

/**
 * FenwickTree2D - A two-dimensional Binary Indexed Tree (BIT) implementation.
 * 
 * This data structure efficiently handles point updates and range sum queries
 * in a 2D grid with O(log n * log m) time complexity for both operations.
 */
class FenwickTree2D {
private:
    int n, m;                    // Dimensions of the original array: n rows, m columns
    vector<vector<int>> bit;     // 2D BIT array, size (n+1) x (m+1)

public:
    /**
     * Constructor: initialize BIT from a 2D 0-indexed array "A" with n rows and m columns.
     * 
     * @param A - The input 2D array to initialize the BIT
     * Time Complexity: O(n*m*log(n)*log(m))
     */
    FenwickTree2D(const vector<vector<int>>& A) {
        n = A.size();
        m = (n > 0) ? A[0].size() : 0;
        bit.assign(n + 1, vector<int>(m + 1, 0));

        // Build BIT by performing point updates for each element of A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                update(i, j, A[i][j]);
            }
        }
    }

    /**
     * Point update: add "delta" to the element at (x, y) in the original array (0-indexed).
     * 
     * @param x - Row index (0-indexed)
     * @param y - Column index (0-indexed)
     * @param delta - Value to add to the element
     * Time Complexity: O(log(n)*log(m))
     */
    void update(int x, int y, int delta) {
        // Convert x, y to 1-indexed for BIT operations
        for (int i = x + 1; i <= n; i += i & -i) {  // Add the least significant bit (LSB)
            for (int j = y + 1; j <= m; j += j & -j) {  // Add the LSB
                bit[i][j] += delta;
            }
        }
    }

    /**
     * Compute the prefix sum from (0,0) to (x, y) (0-indexed).
     * 
     * @param x - Row index (0-indexed)
     * @param y - Column index (0-indexed)
     * @return The sum of all elements in the rectangle from (0,0) to (x,y)
     * Time Complexity: O(log(n)*log(m))
     */
    int prefixSum(int x, int y) {
        int sum = 0;
        // Convert x, y to 1-indexed for BIT operations
        for (int i = x + 1; i > 0; i -= i & -i) {  // Remove the least significant bit (LSB)
            for (int j = y + 1; j > 0; j -= j & -j) {  // Remove the LSB
                sum += bit[i][j];
            }
        }
        return sum;
    }

    /**
     * Range sum query for rectangle with top-left (x1, y1) and bottom-right (x2, y2) (0-indexed).
     * 
     * @param x1 - Top-left row index (0-indexed)
     * @param y1 - Top-left column index (0-indexed)
     * @param x2 - Bottom-right row index (0-indexed)
     * @param y2 - Bottom-right column index (0-indexed)
     * @return The sum of all elements in the rectangle from (x1,y1) to (x2,y2)
     * Time Complexity: O(log(n)*log(m))
     */
    int rangeSum(int x1, int y1, int x2, int y2) {
        // Use inclusion-exclusion principle to calculate the sum for the specified rectangle
        int total = prefixSum(x2, y2);                                  // Full rectangle from (0,0) to (x2,y2)
        int subtractUp = (x1 > 0) ? prefixSum(x1 - 1, y2) : 0;          // Subtract rectangle above 
        int subtractLeft = (y1 > 0) ? prefixSum(x2, y1 - 1) : 0;        // Subtract rectangle to the left
        int addOverlap = (x1 > 0 && y1 > 0) ? prefixSum(x1 - 1, y1 - 1) : 0;  // Add back the double-subtracted area
        return total - subtractUp - subtractLeft + addOverlap;
    }
};

int main() {
    // Example 2D array (0-indexed)
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create a 2D Fenwick Tree from the array
    FenwickTree2D ft2d(A);

    // Example 1: Query the sum of rectangle from (0,0) to (1,1)
    // This includes elements A[0][0], A[0][1], A[1][0], A[1][1] = 1+2+4+5 = 12
    cout << "Range Sum (0,0) to (1,1): " << ft2d.rangeSum(0, 0, 1, 1) << "\n";

    // Example 2: Update operation - add 10 to element at (1,1)
    // This changes A[1][1] from 5 to 15
    ft2d.update(1, 1, 10);

    // Example 3: Query again after update
    // Now the sum is 1+2+4+15 = 22
    cout << "After update, Range Sum (0,0) to (1,1): " << ft2d.rangeSum(0, 0, 1, 1) << "\n";

    // Example 4: Query the sum of the entire matrix
    cout << "Range Sum (0,0) to (2,2): " << ft2d.rangeSum(0, 0, 2, 2) << "\n";

    return 0;
}
