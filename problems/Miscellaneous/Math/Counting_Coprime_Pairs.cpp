#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int MAX = 1000000; // maximum value of x_i
    vector<ll> freq(MAX + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    vector<ll> notCoprime(MAX + 1, 0);
    for (int i = 1; i <= MAX; i++) {
        ll count = 0;
        for (int j = i; j <= MAX; j += i) {
            count += freq[j];
        }
        notCoprime[i] = count * (count - 1) / 2; // pairs of multiples of i
    }

    // Apply inclusion-exclusion principle
    for (int i = MAX; i >= 1; i--) {
        for (int j = 2 * i; j <= MAX; j += i) {
            notCoprime[i] -= notCoprime[j];
        }
    }

    ll totalPairs = (ll)n * (n - 1) / 2;
    ll invalid = 0;
   for(int i=2; i<=MAX; i++){
            invalid += notCoprime[i];
   }

    cout << totalPairs - invalid << endl;

    return 0;
}
