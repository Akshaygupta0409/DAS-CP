#include <iostream>
#include <vector>
using namespace std;

class FenwickTree2D {
private:
    int n, m;
    vector<vector<int>> bit; // 2D BIT array, size (n+1) x (m+1)

public:
    // Constructor: initialize BIT from a 2D 0-indexed array "A" with n rows and m columns.
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

    // Point update: add "delta" to the element at (x, y) in the original array (0-indexed)
    void update(int x, int y, int delta) {
        // Convert x, y to 1-indexed.
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    // Compute the prefix sum from (0,0) to (x, y) (0-indexed)
    int prefixSum(int x, int y) {
        int sum = 0;
        // Convert x, y to 1-indexed.
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    // Range sum query for rectangle with top-left (x1, y1) and bottom-right (x2, y2) (0-indexed)
    int rangeSum(int x1, int y1, int x2, int y2) {
        int total = prefixSum(x2, y2);
        int subtractUp = (x1 > 0) ? prefixSum(x1 - 1, y2) : 0;
        int subtractLeft = (y1 > 0) ? prefixSum(x2, y1 - 1) : 0;
        int addOverlap = (x1 > 0 && y1 > 0) ? prefixSum(x1 - 1, y1 - 1) : 0;
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

    FenwickTree2D ft2d(A);

    // Query the sum of rectangle from (0,0) to (1,1): expected 1+2+4+5 = 12
    cout << "Range Sum (0,0) to (1,1): " << ft2d.rangeSum(0, 0, 1, 1) << "\n";

    // Update: add 10 to element at (1,1)
    ft2d.update(1, 1, 10);

    // Now query again the sum of rectangle from (0,0) to (1,1): expected 1+2+4+(5+10)=22
    cout << "After update, Range Sum (0,0) to (1,1): " << ft2d.rangeSum(0, 0, 1, 1) << "\n";

    // Query the sum of the entire matrix.
    cout << "Range Sum (0,0) to (2,2): " << ft2d.rangeSum(0, 0, 2, 2) << "\n";

    return 0;
}
