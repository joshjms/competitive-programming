#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int g, l, ab;
pair <int,int> ans;

void solve () {
    ans = {1e18, 1e18};
    cin >> g >> l;
    if(l % g) {cout << -1 << " " << -1 << "\n"; return;}
    ab = l / g;
    for(int i = 1; i * i <= ab; i++) {
        if(ab % i == 0) {
            int j = ab / i;
            if(__gcd(i, j) == 1) ans = min(ans, {g * (i + j), i});
        }
    }
    cout << ans.se * g << " " << (ab / ans.se) * g << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}