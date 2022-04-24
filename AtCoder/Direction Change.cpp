#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, r, d;

void solve () {
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 0 << '\n';
        return;
    }
    if(n == 1 && m > 2) {
        cout << -1 << "\n";
        return;
    }
    if(n > 2 && m == 1) {
        cout << -1 << "\n";
        return;
    }
    r = m - 1, d = n - 1;
    if((d - r) % 2 == 0) {cout << max(r, d) * 2 << "\n";}
    else cout << max(r, d) * 2 - 1 << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while(tc--)
        solve ();
}