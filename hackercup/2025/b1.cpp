
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve(int tc) {
	int n, a, b; cin >> n >> a >> b;

    vector <int> ans(2 * n, 1);
    ans[2 * n - 1] = b;

	cout << "Case #" << tc << ": ";
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
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
