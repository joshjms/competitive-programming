
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
	int n, q; cin >> n >> q;
	int B = log2(n) - 1;

	vector <int> a(n + 5);

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	
	struct Node {
		int sum = 0;
		vector <int> ssum;

		Node() {
			sum = 0;
		}

		Node(int v) {
			sum = v;
			ssum = {v};
		}
	};
	
	Node tree[4 * n + 5];

	function <void(int, int, int)> build = [&](int idx, int l, int r) {
		if(l == r) {
			tree[idx] = Node(a[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(idx * 2, l, mid);
		build(idx * 2 + 1, mid + 1, r);

		int L = r - l + 1;
		tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
		tree[idx].ssum.assign(L, 0);

		for(int i = 0; i < L; i++) {
			if(i < L / 2) {
				tree[idx].ssum[i] = tree[idx * 2].ssum[i] + tree[idx * 2 + 1].sum * L / 2 + tree[idx * 2 + 1].ssum[i];
			} else {
				tree[idx].ssum[i] = tree[idx * 2 + 1].ssum[i - L/2] + tree[idx * 2].sum * L / 2 + tree[idx * 2].ssum[i - L/2];
			}
		}
	};

	build(1, 1, n);

	int X = 0;

	function <int(int, int, int, int, int, int)> query2 = [&](int idx, int l, int r, int x, int y, int b) {
		if(l > r || l > y || r < x) return 0ll;
		if(l >= x && r <= y) {
			return tree[idx].sum;
		}

		int L = r - l + 1;
		int mid = (l + r) / 2;

		if(X & (1ll << b)) {
			// swap exists
			int dx = x - l;
			int dy = y - l;

			int nx = (dx + L / 2) % L + l;
			int ny = (dy + L / 2) % L + l;

			int sum = 0;

			if(nx > ny) {
				sum += query2(idx * 2, l, mid, l, ny, b - 1);
				sum += query2(idx * 2 + 1, mid + 1, r, nx, r, b - 1);
			} else {
				sum += query2(idx * 2, l, mid, nx, min(mid, ny), b - 1);
				sum += query2(idx * 2 + 1, mid + 1, r, max(mid + 1, nx), ny, b - 1);
			}
			
			return sum;
		} else {
			int nx = x;
			int ny = y;

			int sum = 0;

			sum += query2(idx * 2, l, mid, nx, min(mid, ny), b - 1);
			sum += query2(idx * 2 + 1, mid + 1, r, max(mid + 1, nx), ny, b - 1);

			return sum;
		}

		return 0ll;
	};

	function <pair<int,int>(int, int, int, int, int, int)> query3 = [&](int idx, int l, int r, int x, int y, int b) -> pair<int,int> {
		if(l > r || l > y || r < x) return {0ll, 0ll};
		if(l >= x && r <= y) {
			int L = r - l + 1;
			int _X = X % L;
			return {tree[idx].ssum[_X], tree[idx].sum};
		}

		int L = r - l + 1;
		int mid = (l + r) / 2;

		if(X & (1ll << b)) {
			// swap exists
			int dx = x - l;
			int dy = y - l;

			int nx = (dx + L / 2) % L + l;
			int ny = (dy + L / 2) % L + l;

			int sum = 0;

			if(nx > ny) {
				pair <int,int> p, q;
				p = query3(idx * 2, l, mid, l, ny, b - 1);
				q = query3(idx * 2 + 1, mid + 1, r, nx, r, b - 1);

				int resulting = q.fi + p.se * (r - nx + 1) + p.fi;
				return {resulting, p.se + q.se};
			} else {
				pair <int,int> p, q;
				p = query3(idx * 2, l, mid, nx, min(mid, ny), b - 1);
				q = query3(idx * 2 + 1, mid + 1, r, max(mid + 1, nx), ny, b - 1);

				int resulting = p.fi + q.se * max(0ll, (min(mid, ny) - nx + 1)) + q.fi;
				return {resulting, p.se + q.se};
			}
		} else {
			int nx = x;
			int ny = y;

			pair <int,int> p, q;

			p = query3(idx * 2, l, mid, nx, min(mid, ny), b - 1);
			q = query3(idx * 2 + 1, mid + 1, r, max(mid + 1, nx), ny, b - 1);

			int resulting = p.fi + q.se * max(0ll, (min(mid, ny) - nx + 1)) + q.fi;
			return {resulting, p.se + q.se};
		}

		return {0ll, 0ll};
	};

	for(int i = 1; i <= q; i++) {
		int type; cin >> type;

		if(type == 1) {
			int x; cin >> x;
			X ^= x;
		}

		if(type == 2) {
			int l, r; cin >> l >> r;
			int ans = query2(1, 1, n, l + 1, r + 1, B);
			cout << ans << "\n";
		}

		if(type == 3) {
			int l, r; cin >> l >> r;
			int ans = query3(1, 1, n, l + 1, r + 1, B).fi;
			cout << ans << "\n";
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
