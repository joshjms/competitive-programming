
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve() {
	int n, q; cin >> n >> q;

	vector <int> a(n + 5);
	vector <int> loc[n + 5];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		loc[a[i]].pb(i);
	}

	vector <pair<int,int>> qr(q + 5);
	vector <pair<int,int>> qops[n + 5];
	for(int i = 1; i <= q; i++) {
		cin >> qr[i].fi >> qr[i].se;
		qops[a[qr[i].fi]].pb({i, -1});
		qops[qr[i].se].pb({i, +1});
		a[qr[i].fi] = qr[i].se;
	}

	struct Node{
		int maxSum = 0;
		int prefSum = 0;
		int suffSum = 0;
		int sum = 0;

		Node() {
			maxSum = 0;
			prefSum = 0;
			suffSum = 0;
			sum = 0;
		}
	};

	Node tree[4 * n + 5];

	function <void(int, int, int)> build = [&](int idx, int l, int r) {
		if(l == r) {
			tree[idx].maxSum = -1;
			tree[idx].prefSum = -1;
			tree[idx].suffSum = -1;
			tree[idx].sum = -1;
			return;
		}
		int mid = (l + r) / 2;
		build(idx * 2, l, mid);
		build(idx * 2 + 1, mid + 1, r);

		tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
		tree[idx].prefSum = max(tree[idx * 2].prefSum, tree[idx * 2].sum + tree[idx * 2 + 1].prefSum);
		tree[idx].suffSum = max(tree[idx * 2 + 1].suffSum, tree[idx * 2 + 1].sum + tree[idx * 2].suffSum);
		tree[idx].maxSum = max(tree[idx * 2].maxSum, max(tree[idx * 2 + 1].maxSum, tree[idx * 2].suffSum + tree[idx * 2 + 1].prefSum));
	};

	build(1, 1, n);

	function <void(int, int, int, int , int)> upd = [&](int idx, int l, int r, int x, int v) {
		if(l == r) {
			tree[idx].maxSum = v;
			tree[idx].prefSum = v;
			tree[idx].suffSum = v;
			tree[idx].sum = v;
			return;
		}

		int mid = (l + r) / 2;
		if(x <= mid)
			upd(idx * 2, l, mid, x, v);
		else upd(idx * 2 + 1, mid + 1, r, x, v);

		tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
		tree[idx].prefSum = max(tree[idx * 2].prefSum, tree[idx * 2].sum + tree[idx * 2 + 1].prefSum);
		tree[idx].suffSum = max(tree[idx * 2 + 1].suffSum, tree[idx * 2 + 1].sum + tree[idx * 2].suffSum);
		tree[idx].maxSum = max(tree[idx * 2].maxSum, max(tree[idx * 2 + 1].maxSum, tree[idx * 2].suffSum + tree[idx * 2 + 1].prefSum));
	};
	
	vector <int> maxi(n + 5, 0);

	for(int i = 1; i <= n; i++) {
		for(auto j : loc[i]) upd(1, 1, n, j, 1);
		maxi[i] = tree[1].maxSum;
		for(auto j : loc[i]) upd(1, 1, n, j, -1);
	}

	int mt[4 * n + 5];

	function <void(int, int, int)> buildmax = [&](int idx, int l, int r) {
		if(l == r) {
			mt[idx] = maxi[l];
			return;
		}
		int mid = (l + r) / 2;
		buildmax(idx * 2, l, mid);
		buildmax(idx * 2 + 1, mid + 1, r);
		mt[idx] = max(mt[idx * 2], mt[idx * 2 + 1]);
	};
	
	function <void(int, int, int, int, int)> updmax = [&](int idx, int l, int r, int x, int v) {
		if(l == r) {
			mt[idx] = v;
			return;
		}
		int mid = (l + r) / 2;
		if(x <= mid) updmax(idx * 2, l, mid, x, v);
		else updmax(idx * 2 + 1, mid + 1, r, x, v);
		mt[idx] = max(mt[idx * 2], mt[idx * 2 + 1]);
	};

	buildmax(1, 1, n);

	vector <int> res(q + 5, 0);
	vector <pair<int,int>> ops[q + 5];

	for(int i = 1; i <= n; i++) {
		for(auto j : loc[i]) upd(1, 1, n, j, 1);

		for(auto qop : qops[i]) {
			int qidx = qop.fi;
			int qd = qop.se;
			int pos = qr[qidx].fi;

			if(qd == 1) {
				upd(1, 1, n, pos, 1);
				ops[qidx].pb({i, tree[1].maxSum});
			} else {
				upd(1, 1, n, pos, -1);
				ops[qidx].pb({i, tree[1].maxSum});
			}
		}

		for(auto qop : qops[i]) upd(1, 1, n, qr[qop.fi].fi, -1);
		for(auto j : loc[i]) upd(1, 1, n, j, -1);
	}

	for(int i = 1; i <= q; i++) {
		for(auto j : ops[i])
			updmax(1, 1, n, j.fi, j.se);
		res[i] = mt[1];
	}

	for(int i = 1; i <= q; i++)
		cout << res[i] / 2 << " ";
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
