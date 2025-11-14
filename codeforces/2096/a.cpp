
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve() {
	int n; cin >> n;
	char s[n + 1];
	int ans[n + 1];
	memset(ans, 0, sizeof(ans));

	for(int i = 1; i < n; i++) 
		cin >> s[i];

	int it = 1;
	for(int i = n - 1; i >= 1; i--) {
		if(s[i] == '<') {
			ans[i + 1] = it++;
		}
	}

	for(int i = 1; i <= n; i++) {
		if(ans[i] == 0) ans[i] = it++;	
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";
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
