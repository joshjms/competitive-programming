#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, pos, ans, idx;
vector <int> v[2];

char c;
int p;

void solve() {
    cin >> n;
    for(int i = 1, p; i <= n; i++) {
        cin >> c >> p;
        if(c == 'L') v[1].pb(p);
        if(c == 'G') v[0].pb(p);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    for(int i = 0; i < v[0].size(); i++){
        pos = v[0][i];
        idx = lower_bound(v[1].begin(), v[1].end(), pos) - v[1].begin();
        ans = max(ans, (i + 1) + (int) v[1].size() - idx);
    }
    for(int i = 0; i < v[1].size(); i++){
        pos = v[1][i];
        idx = upper_bound(v[0].begin(), v[0].end(), pos) - v[0].begin();
        ans = max(ans, ((int) v[1].size() - i) + idx);
    }
    cout << n - ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}