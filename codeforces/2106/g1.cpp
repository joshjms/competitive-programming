
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
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
	}

	int root = 0;

	auto query1 = [&](vector <int> &v) {
		cout << "? 1 " << v.size();
		for(auto i : v)
			cout << " " << i;
		cout << "\n";
		cout.flush();
		int resp; cin >> resp;
		return resp;
	};

	auto query11 = [&](int u) {
		cout << "? 1 1 " << u << "\n";
		cout.flush();
		int resp; cin >> resp;
		return resp;	
	};

	auto query2 = [&](int u) {
		cout << "? 2 " << u << "\n";
		cout.flush();
	};

	cout << "? 1 1 1\n";
	cout.flush();
	int resp; cin >> resp;
	if(resp % 2) {
		root = 1;
	}

	if(!root) {
		int l = 2, r = n;
		while(l < r) {
			int mid = (l + r) / 2;

			vector <int> tmp;
			for(int i = l; i <= mid; i++) 
				tmp.pb(i);

			int r1 = query1(tmp);

			query2(1);

			int r2 = query1(tmp);

			int sz = mid - l + 1;
			int d = abs(r2 - r1) / 2;

			assert(d == sz || d == sz - 1);

			if(d == sz - 1) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		assert(l == r);
		root = l;
	}

	vector <int> val(n + 5, 0);


	val[root] = query11(root);
	if(root != 1) {
		val[1] = query11(1) - val[root];
	}

	for(int i = 2; i <= n; i++) {
		if(i == root) continue;
		val[i] = query11(i) - val[root] - (root == 1 ? 0 : val[1]);
	}

	cout << "!";
	for(int i = 1; i <= n; i++)
		cout << " " << val[i];
	cout << "\n";
	cout.flush();
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
