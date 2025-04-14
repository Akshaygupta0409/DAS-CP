#include <bits/stdc++.h>

using namespace std;

// Example check function - replace with actual condition
bool check(double mid) {
    // Implement your condition here
    // Return true if mid satisfies your condition
    // Return false otherwise
    return mid * mid < 100; // Example condition
}

int main() {
    // Binary search on real domain (continuous values)
    
    // Method 1: Fixed number of iterations
    // This approach runs for a fixed number of iterations
    // More iterations = higher precision
    double lo = 0, hi = 100; // Initialize search range [lo, hi]
    int iterations = 40;     // Number of iterations for desired precision
    
    for(int i = 0; i <= iterations; i++) {
        double mid = lo + (hi - lo) / 2; // Calculate midpoint
        if(check(mid)) {
            lo = mid; // Answer is in the upper half
        } else {
            hi = mid; // Answer is in the lower half
        }
    }
    
    double ans1 = (lo + hi) / 2; // Final answer is the middle of our range
    cout << "Method 1 result: " << ans1 << endl;
   
    // Method 2: Precision-based approach
    // This approach runs until we reach desired precision
    lo = 0;
    hi = 100;
    double eps = 1e-9; // Precision threshold (10^-9)
    
    while(hi - lo > eps) {
        double mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            lo = mid; // Answer is in the upper half
        } else {
            hi = mid; // Answer is in the lower half
        }
    }
    
    double ans2 = (lo + hi) / 2;
    cout << "Method 2 result: " << ans2 << endl;

    return 0;
}

