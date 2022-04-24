#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

string s, p, q;

void solve () {
    cin >> s;
    p = s;
    q = s;
    reverse(q.begin(), q.end());
    if(s != q) {
        cout << s << "\n";
        return;
    }
    sort(p.begin(), p.end());
    if(s == p) cout << -1 << "\n";
    else cout << p << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}