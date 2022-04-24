#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, k, q;
int l[200005], r[200005], a[200005], b[200005];
int ps[200005], ps2[200005];

void solve () {
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        ps[l[i]]++;
        ps[r[i] + 1]--;
    }
    for(int i = 1; i <= 200000; i++) {
        ps[i] += ps[i - 1];
        if(ps[i] >= k) ps2[i] = 1;
    }
    for(int i = 1; i <= 200000; i++) 
        ps2[i] += ps2[i - 1];
    for(int i = 1; i <= q; i++) {
        cin >> a[i] >> b[i];
        cout << ps2[b[i]] - ps2[a[i] - 1] << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}