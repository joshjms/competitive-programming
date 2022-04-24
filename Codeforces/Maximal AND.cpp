#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, k, a[200005], cost[35], ans;

void solve () {
    cin >> n >> k;
    for(int i = 0; i <= 30; i++)
        cost[i] = n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j <= 30; j++) {
            if(a[i] & (1ll << j)) {
                cost[j]--;
            }
        }
    }
    ans = 0;
    for(int i = 30; i >= 0; i--) {
        if(k >= cost[i]) {
            k -= cost[i];
            ans |= (1ll << i);
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}