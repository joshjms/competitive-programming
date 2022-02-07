#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, q, l[200005], r[200005];
vector <int> g[200005];
bool vis[200005];

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= q; i++){
        cin >> l[i] >> r[i];
        g[l[i] - 1].pb(r[i]);
        g[r[i]].pb(l[i] - 1);
    }
    function <void(int)> dfs = [&](int pos){
        vis[pos] = true;
        for(auto i : g[pos]) if(vis[i] == false)
            dfs(i);
    };
    dfs(0);
    if(vis[n])
        cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}