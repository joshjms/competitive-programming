
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

struct Node {
	int G, L, R, S;

	Node * left, * right;

	Node() {
		G = 0, L = 0, R = 0, S = 0;
		left = nullptr;
		right = nullptr;
	}

	Node(int l, int r) {
		G = 0, L = 0, R = 0, S = -(r - l + 1);
		left = nullptr;
		right = nullptr;
	}

	Node operator+ (Node b) {
		Node res;
		res.G = max(max(G, b.G), R + b.L);
		res.L = max(L, S + b.L);
		res.R = max(b.R, b.S + R);
		res.S = S + b.S;

		return res;
	}

	void upd(int idx, int l, int r, int x, int v) {
		if(l == r) {
			G = max(0, v);
			L = max(0, v);
			R = max(0, v);
			S = v;
			return;
		}

		int mid = (l + r) / 2;
		if(x <= mid) {
			if(!left) {
				left = new Node(l, mid);
			}
			left -> upd(idx * 2, l, mid, x, v);
		} else {
			if(!right) {
				right = new Node(mid + 1, r);
			}
			right -> upd(idx * 2 + 1, mid + 1, r, x, v);
		}
		
		Node leftCh = left ? *left : Node(l, mid);
		Node rightCh = right ? *right : Node(mid + 1, r);
		Node newNode = leftCh + rightCh;

		G = newNode.G;
		L = newNode.L;
		R = newNode.R;
		S = newNode.S;
	}

	Node query(int idx, int l, int r, int x, int y) {
		if(l > y || r < x) return Node();
		if(l >= x && r <= y) {
			return * this;
		}

		int mid = (l + r) / 2;
		Node leftQuery = left ? left -> query(idx * 2, l, mid, x, y) : Node(l, mid);
		Node rightQuery = right ? right -> query(idx * 2 + 1, mid + 1, r, x, y) : Node(mid + 1, r);

		return leftQuery + rightQuery;
	} 
};
Node * x[300005];

int n, q, a[300005];

int tree[1200005];

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
	if(x <= mid) upd(idx * 2, l, mid, x, v);
	else upd(idx * 2 + 1, mid + 1, r, x, v);

	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y) {
	if(l > y || r < x) return 0;
	if(l >= x && r <= y) return tree[idx];
	int mid = (l + r) / 2;
	return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		x[i] = new Node(1, n);
	}
	build(1, 1, n);

	for(int i = 1; i <= n; i++) {
		x[a[i]] -> upd(1, 1, n, i, 1);
	}

	for(int i = 1; i <= n; i++) {
		int maxi = x[i] -> query(1, 1, n, 1, n).G;
		upd(1, 1, n, i, maxi);
	}

	// for(int k = 1; k <= n; k++) {
	// 	cout << x[k] -> query(1, 1, n, 1, n).G << " ";
	// }
	// cout << "\n";

	for(int i = 1, j, newV; i <= q; i++) {
		cin >> j >> newV;
		int curV = a[j];

		x[curV] -> upd(1, 1, n, j, -1);
		x[newV] -> upd(1, 1, n, j, 1);

		int qCur = x[curV] -> query(1, 1, n, 1, n).G;
		int qNew = x[newV] -> query(1, 1, n, 1, n).G;

		upd(1, 1, n, curV, qCur);
		upd(1, 1, n, newV, qNew);

		a[j] = newV;

		// for(int k = 1; k <= n; k++) {
		// 	cout << x[k] -> query(1, 1, n, 1, n).G << " ";
		// }
		// cout << "\n";

		// cout << x[4] -> query(x[4], 1, 1, n, 1, n).G << "\n";

		cout << query(1, 1, n, 1, n) / 2 << " ";
	}
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
