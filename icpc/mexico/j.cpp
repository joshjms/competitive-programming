
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int n, q;
int a[1000005];
int tree[4000005];

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);
	tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
}

void upd(int idx, int l, int r, int x, int y) {
	if(l == r) {
		tree[idx] += y;
		return;
	}

	int mid = (l + r) / 2;
	if(x <= mid) upd(idx * 2, l, mid, x, y);
	else upd(idx * 2 + 1, mid + 1, r, x, y);
	tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
}

int query(int idx, int l, int r, int x, int y) {
	if(l > r || l > y || r < x) return 0;
	if(l >= x && r <= y) return tree[idx];

	int mid = (l + r) / 2;
	return query(idx * 2, l, mid, x, y) ^ query(idx * 2 + 1, mid + 1, r, x, y);
}

void solve() {
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);

	for(int t = 1; t <= q; t++) {
		char c; cin >> c;
		if(c == 'P') {
			int l, r; cin >> l >> r;
			int q = query(1, 1, n, l, r);
			if(q == 0) {
				cout << "JUAN\n";
			} else {
				cout << "FRANK\n";
			}
			// cout << query(1, 1, n, l, r) << "\n";
		} else if(c == 'R') {
			int k, x; cin >> k >> x;
			upd(1, 1, n, k, x);
		} else {
			assert(false);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
