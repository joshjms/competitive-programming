
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int tree[1000005];

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

void upd(int idx, int l, int r, int x, int v) {
	if(l == r) {
		tree[idx] = v;
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) {
		upd(idx * 2, l, mid, x, v);
	} else upd(idx * 2 + 1, mid + 1, r, x, v);

	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y) {
	if(l > r || l > y || r < x) return 0;
	if(l >= x && r <= y) return tree[idx];

	int mid = (l + r) / 2;
	return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

void solve() {
	int n, q;
	cin >> n >> q;

	build(1, 1, n);

	int a[n + 1];
	int moves[n + 1], movesHalf[n + 1];
	memset(moves, 0, sizeof(moves));
	memset(movesHalf, 0, sizeof(movesHalf));

	for(int i = 1; i <= n; i++) {
		cin >> a[i];

		int tmp = a[i] / 2;
		while(tmp > 1) {
			tmp++;
			tmp /= 2;
			moves[i]++;
		}
		moves[i]++;
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << moves[i] << " ";
	// cout << "\n";

	int ps[n + 1], cnt[n + 1];
	memset(ps, 0, sizeof(ps));
	memset(cnt, 0, sizeof(cnt));

	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + moves[i];
	}

	for(int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1];
		for(int j = 1; j <= 30; j++) {
			if(a[i] == (1ll << j) + 1) {
				cnt[i]++;
				break;
			}
		}
	}

	for(int t = 1; t <= q; t++) {
		int l, r; cin >> l >> r;

		int sum = ps[r] - ps[l - 1] + (cnt[r] - cnt[l - 1]) / 2;
		cout << sum << "\n";
	}
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
