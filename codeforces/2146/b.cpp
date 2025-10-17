
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
	int n, m;
	cin >> n >> m;

	int l[n + 1], cnt[m + 1], pos[m + 1];
	memset(cnt, 0, sizeof(cnt));
	memset(pos, -1, sizeof(pos));

	vector <int> a[n + 1];
	for(int i = 1; i <= n; i++) {
		cin >> l[i];
		a[i].resize(l[i] + 1);
		for(int j = 1; j <= l[i]; j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
			pos[a[i][j]] = i;
		}
	}

	bool mustChoose[n + 1];
	memset(mustChoose, 0, sizeof(mustChoose));

	for(int i = 1; i <= m; i++) {
		if(cnt[i] == 0) {
			cout << "NO\n";
			return;
		}
		if(cnt[i] == 1) {
			mustChoose[pos[i]] = 1;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!mustChoose[i]) ans++;
	}

	if(ans >= 2) cout << "YES\n";
	else cout << "NO\n";
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
