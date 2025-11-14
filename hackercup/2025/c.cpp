
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

void solve(int tc) {
    int n; cin >> n;
    vector <int> a(n + 5, 0);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector <int> px(n + 5, 0);
    unordered_map <int,int> mp;
    int ans = 0;
    
    ans = n * (n + 1) * (n + 2) / 6;

    mp[0]++;
    for(int i = 1; i <= n; i++) {
        px[i] = px[i - 1] ^ a[i];
        mp[px[i]]++;
    }

    debug(ans);

    for(auto i : mp) {
        int v = i.se;
        ans -= (v - 1) * v * (v + 1) / 6;
    }

	cout << "Case #" << tc << ": ";
    cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
