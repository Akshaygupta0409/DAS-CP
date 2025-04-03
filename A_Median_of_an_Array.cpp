#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		sort(a.begin(), a.end());
        int idx = 0;
		if(n &1 ){
            idx = n/2;
        } else {
            idx = n/2 - 1;
        }
		int val = a[idx] + 1;
		int ans = 0;
		for(int i = idx; i<n; i++) {
			if(a[i] < val) ans += (val - a[i]);
		}
		
		cout << ans << '\n';
        

	}


return 0;

}
