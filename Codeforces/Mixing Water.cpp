#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

ld h, c, t;
int l, r, md;
pair <ld, int> ans;

ld f(int a, int b){
    return (a * h + b * c) / (a + b);
}

void solve(){
    cin >> h >> c >> t;
    ans = {abs(t - f(1, 1)), 2};
    l = 0, r = 1e9;
    while(l <= r){
        md = (l + r) / 2;
        ans = min(ans, {abs(t - f(md + 1, md)), md + md + 1});
        if(f(md + 1, md) > t)
            l = md + 1;
        else r = md - 1;
    }
    cout << ans.se << "\n";
}

signed main(){
    cout << fixed << setprecision(6);

    int tc; cin >> tc;
    while(tc--) solve();
}