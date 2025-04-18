class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> result;          // Result vector to store answers for each query
        vector<long long> prefixSum(n);   // Prefix sum to store counts of valid substrings
        vector<int> leftBound(n);         // Leftmost valid position for each index
        int left = 0;                     // Sliding window left pointer
        int countZeros = 0, countOnes = 0;

        // Calculate the left bounds using a sliding window
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') countOnes++;
            else countZeros++;

            // Adjust the window if constraints are violated
            while (countZeros > k && countOnes > k) {
                if (s[left] == '1') countOnes--;
                else countZeros--;
                left++;
            }
            leftBound[right] = left; // Store the valid leftmost position
        }

        // Calculate the prefix sums of valid substrings
        prefixSum[0] = 1;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + i - leftBound[i] + 1;
        }

        // Process each query
        for (const auto& query : queries) {
            long long queryLeft = query[0];
            long long queryRight = query[1];
            long long count = 0;
            long long position = queryRight + 1;

            // Binary search to find the first valid position within the range
            long long low = queryLeft, high = queryRight;
            while (low <= high) {
                long long mid = (low + high) / 2;
                if (leftBound[mid] >= queryLeft) {
                    position = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Calculate the result for the current query
            if (position <= queryRight) {
                count += prefixSum[queryRight];
                if (position > 0) count -= prefixSum[position - 1];
            }
            count += (position - queryLeft) * (position - queryLeft + 1) / 2;

            result.push_back(count); // Add the result to the output vector
        }

        return result;
    }
};
