
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

int _2[300005];

int n, a[300005];
int dpL[300005], cntL[300005], dpR[300005], cntR[300005];

vector <int> L, R;
int lSz, rSz;
int prv;

int tree[1200005], lazy[1200005];

void build(int idx, int l, int r) {
	if(l > r) return;
	if(l == r) {
		tree[idx] = 1;
		lazy[idx] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);
}

void propagate(int idx, int l, int r) {
	if(lazy[idx] != 1) {
		if(l == r) {
			(tree[idx] *= lazy[idx]) %= mod;
		} else {
			(lazy[idx * 2] *= lazy[idx]) %= mod;
			(lazy[idx * 2 + 1] *= lazy[idx]) %= mod;
		}
		lazy[idx] = 1;
	}
}

void upd(int idx, int l, int r, int x, int y) {
	propagate(idx, l, r);
	if(l > y || r < x) return;
	if(l >= x && r <= y) {
		(lazy[idx] *= 2) %= mod;
		propagate(idx, l, r);
		return;
	}

	int mid = (l + r) / 2;
	upd(idx * 2, l, mid, x, y);
	upd(idx * 2 + 1, mid + 1, r, x, y);
}

int query(int idx, int l, int r, int x) {
	propagate(idx, l, r);
	if(x > r || x < l) return 1;
	if(l == r) {
		int tmp = tree[idx];
		tree[idx] = 1;
		return tmp;
	}
	int mid = (l + r) / 2;
	if(x <= mid) {
		return query(idx * 2, l, mid, x);
	} else {
		return query(idx * 2 + 1, mid + 1, r, x);
	}
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];


	int max_val = *max_element(a + 1, a + n + 1);
	L.clear();
	R.clear();

	L.pb(0);
	prv = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > prv) {
			prv = a[i];
			L.push_back(a[i]);
		}
		if(a[i] == max_val) break;
	}
	//L.pop_back();
	lSz = L.size() - 1;

	R.pb(0);
	prv = 0;
	for(int i = n; i >= 1; i--) {
		if(a[i] > prv) {
			prv = a[i];
			R.push_back(a[i]);
		}
		if(a[i] == max_val) break;
	}
	R.pop_back();
	rSz = R.size() - 1;

	build(1, 1, lSz);

	// upd(1, 1, lSz, 1, lSz);
	// debug(query(1, 1, lSz, 1));

	for(int i = 1; i <= lSz; i++) {
		dpL[i] = 0;
	}

	dpL[0] = 1;
	for(int i = 1; i <= n; i++) {
		int v = a[i];
		int idx = lower_bound(L.begin(), L.end(), v) - L.begin();

		(dpL[lSz] *= query(1, 1, lSz, lSz)) %= mod;
		(dpL[lSz - 1] *= query(1, 1, lSz, lSz - 1)) %= mod;
		cntL[i] = (dpL[lSz] + dpL[lSz - 1]) % mod;
		
		upd(1, 1, lSz, idx, lSz);
		
		if(L[idx] == v) {
			(dpL[idx - 1] *= query(1, 1, lSz, idx - 1)) %= mod;
			(dpL[idx] *= query(1, 1, lSz, idx)) %= mod;
			// debug(dpL[idx - 1]);
			// debug(dpL[idx]);
			(dpL[idx] += dpL[idx - 1]) %= mod;
		}

		// for(int j = 1; j <= lSz; j++) {
		// 	dpL[j] *= query(1, 1, lSz, j);
		// 	cout << dpL[j] << " ";
		// }
		// cout << "\n";
	}

	build(1, 1, rSz);

	for(int i = 1; i <= rSz; i++)
		dpR[i] = 0;

	dpR[0] = 1;
	for(int i = n; i >= 1; i--) {
		int v = a[i];
		int idx = lower_bound(R.begin(), R.end(), v) - R.begin();
		upd(1, 1, rSz, idx, rSz);
		
		(dpR[rSz] *= query(1, 1, rSz, rSz)) %= mod;
		if(R[idx] == v) {
			(dpR[idx - 1] *= query(1, 1, rSz, idx - 1)) %= mod; 
			(dpR[idx] *= query(1, 1, rSz, idx)) %= mod; 
			(dpR[idx] += dpR[idx - 1]) %= mod;
		}
		cntR[i] = dpR[rSz];
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << cntL[i] << " ";
	// cout << "\n";
	// for(int i = 1; i <= n; i++)
	// 	cout << cntR[i] << " ";
	// cout << "\n";

	cntR[n + 1] = 1;
	cntL[0] = 1;

	// int ans = 0, counter = 0;    
	// for(int i = 1; i <= n;i++) {    
    //     if(a[i] == max_val){
    //         ans = (ans + (counter + cntL[i - 1]) % mod * cntR[i + 1]) % mod;
	// 		// cout << (counter + cntL[i - 1]) << " " << cntR[i + 1] << endl;
    //     }
    //     counter = (counter * 2) % mod;
    //     if(a[i] == max_val){
    //         counter = (counter + cntL[i - 1]) % mod;
    //     }
    // }
	int ans = 0;   
	for(int i = 1; i <= n;i++) {    
        if(a[i] == max_val){
            ans = (ans + cntL[i] * cntR[i + 1]) % mod;
			// cout << (counter + cntL[i - 1]) << " " << cntR[i + 1] << endl;
        }
	}
    cout << ans << endl;
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
