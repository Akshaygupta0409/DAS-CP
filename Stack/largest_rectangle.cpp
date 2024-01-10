
// max area of histogram 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define m 1000000007
const int N = 1e6;

void solve() {
	int n; cin >> n;
	int a[n], psi[n], nsi[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	stack<int> st;
	for (int i = 0; i < n; i++) {//previous smallar index
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();
		if (st.empty()) psi[i] = -1;
		else psi[i] = st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = n - 1; i > -1; i -- ) { //next smallar index
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();
		if (st.empty()) nsi[i] = n;
		else nsi[i] = st.top();
		st.push(i);
	}
	int area = -1e17;
	for (int i = 0; i < n; i++) {
		//if (psi[i] != -1 && nsi[i] != -1)
		//cout << psi[i] << " " << nsi[i] << " " << a[i] * (nsi[i] - psi[i] - 1) << endl;
		area = max(area, a[i] * (nsi[i] - psi[i] - 1));
	}
	cout << area << "\n"; //nsi[i] << " ";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t; while (t -- )
		solve();
}