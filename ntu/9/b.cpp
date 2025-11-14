
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

// void solve() {
// 	int n; cin >> n;

// 	vector <pair<int,pair<int,int>>> ans;

// 	int l = 2;
// 	int r = 2;

// 	bool vis[n + 1];
// 	memset(vis, 0, sizeof(vis));

// 	int a = 2, b = 2;

// 	while(l <= n && r <= n) {
// 		while(a <= n && vis[a]) a++;
// 		if(a <= n) vis[a] = 1;
// 		while(b <= n && vis[b]) b++;
// 		if(b <= n) vis[b] = 1;

// 		int lo = b + 1, hi = (a + b - 1);
// 		while(lo < hi){
// 			int mid = (lo + hi)/2;
// 			if(mid * mid > a * a + b * b) lo = mid;
// 			else hi = mid - 1;
// 		}

// 		if(a > n || b > n || lo > n) break;
// 		vis[lo] = 1;
		
// 		ans.pb({a, {b, lo}});

// 		if(a > n || b > n || lo > n) break;
// 	}

// 	cout << ans.size() << "\n";
// 	for(auto i : ans)
// 		cout << i.fi << " " << i.se.fi << " " << i.se.se << "\n";
// }

void solve() {
	int n; cin >> n;
	
	int l = 2, r = n, ans = 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		int _r = n;

		bool valid = 1;
		for(int i = mid; i >= 2; i--) {
			int a = i;
			int b = _r - 1;
			int c = _r;

			while(a > 1 && (a + b > c) && (a * a + b * b < c * c)) {
				a--;
			}

			if(a == 1) {
				
			}

			_r -= 2;

			if(!valid) break;
		}

		if(_r <= mid) valid = false;

		if(valid) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}


	cout << ans - 1 << "\n";
	int _r = n;

	for(int i = ans; i >= 2; i--) {
		int a = i;
		int b = _r - 1;
		int c = _r;
		assert((a + b > c) && (a * a + b * b < c * c));

		cout << a << " " << b << " " << c << "\n";

		_r -= 2;
	}
}

// void solve2() {
// 	int n; cin >> n;

// 	vector <pair<int,pair<int,int>>> ans;

// 	int l = 2;
// 	int r = 2;

// 	bool vis[n + 1];
// 	memset(vis, 0, sizeof(vis));

// 	int a = 2, b = 2, c = 2;

// 	while(l <= n && r <= n) {
// 		while(a <= n && vis[a]) a++;
// 		if(a <= n) vis[a] = 1;
// 		while(b <= n && vis[b]) b++;
// 		if(b <= n) vis[b] = 1;

// 		while(c <= n && (a + b < c || a * a + b * b >= c * c)) c++;
// 		if(c <= n) vis[c] = 1;

// 		if(a > n || b > n || c > n) break;
		
// 		ans.pb({a, {b, c}});

// 		if(a > n || b > n || c > n) break;
// 	}

// 	cout << ans.size() << "\n";
// 	for(auto i : ans){
// 		assert(i.fi + i.se.fi > i.se.se);
// 		assert(i.fi * i.fi + i.se.fi * i.se.fi < i.se.se * i.se.se);
// 		cout << i.fi << " " << i.se.fi << " " << i.se.se << "\n";
// 	}
// }

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
