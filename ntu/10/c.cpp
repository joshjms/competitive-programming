
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve(int n, int k) {
	int ans = 0;
	bool vis[n + 5];
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		int tmr = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis[j]) {
				tmr++;
				if((tmr - 1) % k == 0) {
					vis[j] = 1;
					ans = j;
				}
			}
		}
	}

	cout << ans << " " << ceil(1.0 * ans / (k - 1)) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 3; i <= 100; i++) {
		solve(i, 3);
	}

	return 0;
}
