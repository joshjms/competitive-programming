#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, q;
vector <int> ps;

void solve () {
    cin >> n;
    ps.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    // for(int i = 0; i <= n; i++)
    //     cout << ps[i] << " ";
    // cout << "\n";
    cin >> q;
    for(int i = 1, x; i <= q; i++) {
        cin >> x;
        cout << lower_bound(ps.begin(), ps.end(), x) - ps.begin() << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}