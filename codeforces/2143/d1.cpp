
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

int n, a[2005];

int tree[2005][8005];

int upd(int I, int idx, int l, int r, int x, int v) {
	if(l == r) {
		(tree[I][idx] += v) %= mod;
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) upd(I, idx * 2, l, mid, x, v);
	else upd(I, idx * 2 + 1, mid + 1, r, x, v);

	tree[I][idx] = (tree[I][idx * 2] + tree[I][idx * 2 + 1]) % mod;
}

int query(int I, int idx, int l, int r, int x, int y) {
	if(l > y || r < x) return 0;
	if(l >= x && r <= y) {
		return tree[I][idx];
	}

	int mid = (l + r) / 2;
	return (query(I, idx * 2, l, mid, x, y) + query(I, idx * 2 + 1, mid + 1, r, x, y)) % mod;
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++) {
		memset(tree[i], 0, sizeof(tree[i]));
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= a[i]; j++) {
			int v = query(j, 1, 1, 2001, 2001, 2001);
			upd(a[i], 1, 1, 2001, 2001, v);
		}

		for(int j = a[i] + 1; j <= 2001; j++) {
			int sum = query(j, 1, 1, 2001, 1, a[i]);
			upd(j, 1, 1, 2001, a[i], sum);

			int v = query(j, 1, 1, 2001, 2001, 2001);
			upd(j, 1, 1, 2001, a[i], v);

			(dp[j][a[i]][cur] += dp[j][301][prv]) %= mod;
		}
		
		for(int j = 0; j <= a[i]; j++) {
			for(int k = 0; k < j; k++) {
				(dp[a[i]][k][cur] += dp[j][k][prv]) %= mod;
			}
		}

		// if(i <= n) {
		// int tmp = 0;
		// for(int i = 0; i <= 301; i++) {
		// 	for(int j = 0; j <= 301; j++) {
		// 		tmp += dp[i][j][cur];
		// 	}
		// }
		// debug(tmp);

		// }
	}

	int ans = 0;
	for(int i = 0; i <= 301; i++) {
		for(int j = 0; j <= 301; j++) {
			(ans += dp[i][j][n % 2]) %= mod;
		}
	}

	cout << ans + 1 << "\n";
	
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
