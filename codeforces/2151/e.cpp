
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

struct Node{
	int value;
	Node() : value(0) {}
	Node(int v) : value(v) {}
};

class Segtree{
	private:
		int n;
		Node defaultValue;
		function <Node(Node, Node)> mergeFunc;
		vector <Node> tree;

		void buildTree(int idx, int l, int r) {
			if(l == r) {
				tree[idx] = defaultValue;
				return;
			}
			int mid = (l + r) / 2;
			buildTree(idx * 2, l, mid);
			buildTree(idx * 2 + 1, mid + 1, r);

			tree[idx] = mergeFunc(tree[idx * 2], tree[idx * 2 + 1]);
		}

		void updTree(int idx, int l, int r, int x, Node v) {
			if(l == r) {
				tree[idx] = v;
				return;
			}
			int mid = (l + r) / 2;
			if(x <= mid) updTree(idx * 2, l, mid, x, v);
			else updTree(idx * 2 + 1, mid + 1, r, x, v);

			tree[idx] = mergeFunc(tree[idx * 2], tree[idx * 2 + 1]);
		}

		Node queryTree(int idx, int l, int r, int x, int y) {
			if(l > r || l > y || r < x) return this -> defaultValue;
			if(l >= x && r <= y) return tree[idx];

			int mid = (l + r) / 2;
			return mergeFunc(queryTree(idx * 2, l, mid, x, y), queryTree(idx * 2 + 1, mid + 1, r, x, y));
		}

	public:
		Segtree(int n, Node defaultValue, function<Node(Node, Node)> mergeFunc) {
			this->n = n;
			this->defaultValue = defaultValue;
			this->mergeFunc = mergeFunc;
			this->tree.assign(n * 4, defaultValue);
		}

		void build() {
			buildTree(1, 1, this->n);
		}

		void upd(int x, Node v) {
			updTree(1, 1, this->n, x, v);
		}

		Node query(int l, int r) {
			queryTree(1, 1, this->n, l, r);
		}
};

int tree[800005], tree2[800005];

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = 0;
		tree2[idx] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);

	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	tree2[idx] = min(tree2[idx * 2], tree2[idx * 2 + 1]);
}

void build2(int idx, int l, int r) {
	if(l == r) {
		tree2[idx] = 0;
	}
}

void upd(int idx, int l, int r, int x, int y) {
	if(l == r) {
		tree[idx] = y;
		return;
	}

	int mid = (l + r) / 2;
	if(x <= mid) upd(idx * 2, l, mid, x, y);
	else upd(idx * 2 + 1, mid + 1, r, x, y);

	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

void upd2(int idx, int l, int r, int x, int y) {
	if(l == r) {
		tree2[idx] = y;
		return;
	}

	int mid = (l + r) / 2;
	if(x <= mid) upd2(idx * 2, l, mid, x, y);
	else upd2(idx * 2 + 1, mid + 1, r, x, y);

	tree2[idx] = min(tree2[idx * 2], tree2[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y) {
	if(l > r || l > y || r < x) return 1e18;
	if(l >= x && r <= y)  return tree[idx];

	int mid = (l + r) / 2;
	return min(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

int query2(int idx, int l, int r, int x, int y) {
	if(l > r || l > y || r < x) return 1e18;
	if(l >= x && r <= y)  return tree2[idx];

	int mid = (l + r) / 2;
	return min(query2(idx * 2, l, mid, x, y), query2(idx * 2 + 1, mid + 1, r, x, y));
}

int n, v[200005], a[200005], b[200005];

void solve() {
	cin >> n;
	build(1, 1, n);
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
