
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
	vector <pair<int,int>> tmp(n + 1, {0, 0});
	vector <int> loc(n + 1, 0);
	vector <bool> vis(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> tmp[i].fi;
		loc[tmp[i].fi] = i;
	}
	for(int i = 1; i <= n; i++)
		cin >> tmp[i].se;

	vector <vector<pair<int,int>>> a;

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vector <pair<int,int>> T;

			T.pb(tmp[i]);
			vis[i] = 1;

			int cur = tmp[i].se;
			while(cur != tmp[i].fi) {
				int l = loc[cur];
				vis[l] = 1;
				T.pb(tmp[l]);
				cur = tmp[l].se;
			}

			a.pb(T);
		}
	}

	// for(vector <pair<int,int>> v : a) {
	// 	for(auto i : v) {
	// 		cout << i.fi << " ";
	// 	}
	// 	cout << "\n";
	// }

	function <int(vector<int>&)> countInversions = [&](vector <int> &a) {
		int n = a.size();
		vector <int> pos(n + 1, 0);
		vector <pair<int,int>> sorted;

		for(int i = 0; i < n; i++)
			sorted.pb({a[i], i});
		sort(sorted.begin(), sorted.end());

		for(int i = 0; i < n; i++)
			pos[sorted[i].se] = i + 1;

		vector <int> tree(4 * n, 0ll);

		function <void(int, int, int , int, int)> upd = [&](int idx, int l, int r, int x, int v) {
			if(l == r) {
				tree[idx] = v;
				return;
			}
			int mid = (l + r) / 2;
			if(x <= mid) upd(idx * 2, l, mid, x, v);
			else upd(idx * 2 + 1, mid + 1, r, x, v);

			tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		};


		function <int(int, int, int , int, int)> query = [&](int idx, int l, int r, int x, int y) {
			if(l > r || l > y || r < x) return 0ll;
			if(l >= x && r <= y) return tree[idx];
			int mid = (l + r) / 2;
			return query(idx * 2, l, mid, x, y) + query(idx * 2 + 1, mid + 1, r, x, y);
		};

		int invs = 0;

		for(int i = 0; i < n; i++) {
			invs += query(1, 1, n, pos[i] + 1, n);
			upd(1, 1, n, pos[i], 1);
		}

		return invs;
	};

	vector <pair<int,int>> ans;
	vector <int> pos(n + 1, 0);

	int sum = 0, delta = 1;
	for(auto cycle : a) {
		if(cycle.size() % 2 == 0) {
			// even length, (+1, 0) or (0, +1)
			vector <int> A, B, sorted;
			for(int i = 0; i < cycle.size(); i++) {
				A.pb(cycle[i].fi);
				B.pb(cycle[i].se);
				sorted.pb(cycle[i].fi);
			}

			int invA = countInversions(A);
			int invB = countInversions(B);

			sort(sorted.begin(), sorted.end());
			for(int i = 0; i < sorted.size(); i++)
				pos[sorted[i]] = i;
			
			int cycleSize = cycle.size();
			for(int i = 0; i < cycleSize; i++) {
				invA += (cycleSize - pos[A[i]] - 1) - pos[A[i]];
				invB += (cycleSize - pos[B[i]] - 1) - pos[B[i]];

				if(invA - invB == delta) {
					sum += delta;
					delta *= -1;

					for(int j = 0; j < cycleSize; j++) {
						ans.pb({A[(j + i + 1) % cycleSize], B[(j + i + 1) % cycleSize]});
					}

					break;
				}
			}

		} else {
			// odd length, (0, 0)
			vector <int> A, B, sorted;
			for(int i = 0; i < cycle.size(); i++) {
				A.pb(cycle[i].fi);
				B.pb(cycle[i].se);
				sorted.pb(cycle[i].fi);
			}

			int invA = countInversions(A);
			int invB = countInversions(B);

			sort(sorted.begin(), sorted.end());
			for(int i = 0; i < sorted.size(); i++)
				pos[sorted[i]] = i;
			
			int cycleSize = cycle.size();
			for(int i = 0; i < cycleSize; i++) {
				invA += (cycleSize - pos[A[i]] - 1) - pos[A[i]];
				invB += (cycleSize - pos[B[i]] - 1) - pos[B[i]];

				if(invA - invB == 0) {
					for(int j = 0; j < cycleSize; j++) {
						ans.pb({A[(j + i + 1) % cycleSize], B[(j + i + 1) % cycleSize]});
					}

					break;
				}
			}
		}
	}

	if(sum != 0 || ans.size() < n) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].fi << " ";
	cout << "\n";
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].se << " ";
	cout << "\n";
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
