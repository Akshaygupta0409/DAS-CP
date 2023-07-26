#include <bits/stdc++.h>
using namespace std;

int n; // Size of the array
map<int, int> mp; // Map to store the frequency of each number
vector<int> b; // Vector to store the current permutation

// Recursive function to generate permutations
void rec(int l)
{
    // If the current permutation is of size n, print it
    if (l == n)
    {
        for (int i = 0; i < n; i++)
            cout << b[i] << " "; // Print each number in the current permutation
        cout << endl;
        return;
    }
    // Iterate over each unique number in the array
    for (auto &it : mp)
    {
        // If the current number is still available (frequency is not 0)
        if (it.second != 0)
        {
            b.push_back(it.first); // Add the current number to the permutation
            it.second--; // Decrease the frequency of the current number
            rec(l + 1); // Recurse with the next position
            it.second++; // Restore the frequency of the current number
            b.pop_back(); // Remove the current number from the permutation
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; // Read the size of the array
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a; // Read each number in the array
        mp[a]++; // Increase the frequency of the current number
    }
    rec(0); // Start generating permutations from the first position
    return 0;
}
