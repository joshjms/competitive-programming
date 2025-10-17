
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

#pragma GCC unroll 32
 
const int mod = 998244353;

int _2[35];

int n, q;

void solve() {
	cin >> n >> q;

	int a[n + 1];
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	pair <int,int> b[q + 1];

	for(int i = 1, x; i <= q; i++) {
		cin >> x;
		b[i] = {x, i};
	}

	sort(b + 1, b + q + 1);

	multiset <pair<int,int>> mst[35];
	multiset <int> cnt[35];
	
	int require[35], ps[35];
	memset(require, 0, sizeof(require));
	memset(ps, 0, sizeof(ps));

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 32; j++) {
			if(a[i] & _2[j]) cnt[j].insert(a[i]);
			mst[j].insert({a[i] % _2[j], a[i]});
		}
	}

	for(int i = 0; i < 32; i++) {

		if(cnt[i].size()) {
			require[i] = 0;
			continue;
		}

		for(int j = i; j >= 0; j--) {
			// give me i
			if(cnt[j].size() == 0) {
				auto tp = prev(mst[j].end());
				pair <int,int> t = * tp;

				int cur = t.fi;
				int num = t.se;

				for(int k = 0; k < 32; k++) {
					auto it = cnt[k].find(num);
					if(it != cnt[k].end()) {
						// cout << "erase at " << k << "\n";
						cnt[k].erase(it);
					}

					auto it2 = mst[k].find({num % _2[k], num});
					if(it2 != mst[k].end())
						mst[k].erase(it2);
				}

				int add = _2[j] - cur;
				int newNum = num + add;

				for(int k = 0; k < 32; k++) {
					if(newNum & _2[k]) {
						// cout << "insert at " << k << "\n";
						cnt[k].insert(newNum);
					}

					mst[k].insert({newNum % _2[k], newNum});
				}

				require[i] += _2[j] - cur;
			}
		}
	}

	// for(int i = 0; i < 32; i++)
	// 	debug(require[i]);

	for(int i = 0; i < 32; i++) {
		ps[i] = require[i];
		if(i > 0) ps[i] += ps[i - 1];
	}

	vector <int> josh;

	for(int i = 0; i < 32; i++) {
		if(require[i] == 0) {
			ps[i] = 0;
		}
		josh.pb(ps[i]);
	}
	sort(josh.begin(), josh.end());

	// for(int i = 0; i < 32; i++)
	// 	debug(josh[i]);

	int j = 0, ans = 0;
	int pika[q + 5];
	
	for(int i = 1; i <= q; i++) {
		while(j < josh.size() && josh[j] <= b[i].fi) {
			ans++;
			j++;
		}

		pika[b[i].se] = ans;
	}

	for(int i = 1; i <= q; i++)
		cout << pika[i] << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	_2[0] = 1;
	for(int i = 1; i <= 32; i++) {
		_2[i] = _2[i - 1] * 2;
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
