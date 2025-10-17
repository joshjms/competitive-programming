
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, a[105], l, r;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	l = 1, r = n;
	for(int i = 1; i <= n; i++) {
		if(a[l] == i) {
			l++;
		} else if(a[r] == i) {
			r--;
		} else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
