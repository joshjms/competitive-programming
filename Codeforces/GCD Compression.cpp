#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, a[2005];
vector <int> v[2];

void solve () {
    cin >> n;
    v[0].clear();
    v[1].clear();
    for(int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        v[a[i] % 2].pb(i);
    }
    if(v[0].size() % 2 || v[1].size() % 2) {v[0].pop_back(); v[1].pop_back();}
    else if(v[0].size() >= 2) {v[0].pop_back(); v[0].pop_back();}
    else if(v[1].size() >= 2) {v[1].pop_back(); v[1].pop_back();}
    assert(v[0].size() % 2 == 0 && v[1].size() % 2 == 0);
    for(int i = 0; i < v[0].size(); i += 2)
        cout << v[0][i] << " " << v[0][i + 1] << "\n";
    for(int i = 0; i < v[1].size(); i += 2)
        cout << v[1][i] << " " << v[1][i + 1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}