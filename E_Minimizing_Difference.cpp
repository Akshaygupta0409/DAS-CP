#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    while (i < j) {
        // Calculate the cost to increase the smallest elements or decrease the largest elements
        long long di = (a[i + 1] - a[i]) * (i + 1);
        long long dj = (a[j] - a[j - 1]) * (n - j);

        if (di <= dj) {
            if (k >= di) {
                k -= di;
                i++;
            } else {
                a[i] += k / (i + 1);
                k = 0;
                break;
            }
        } else {
            if (k >= dj) {
                k -= dj;
                j--;
            } else {
                a[j] -= k / (n - j);
                k = 0;
                break;
            }
        }
    }

    cout << a[j] - a[i] << endl;
    return 0;
}
