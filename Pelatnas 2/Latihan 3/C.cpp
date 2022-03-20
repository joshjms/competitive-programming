// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m;
pair <int,int> pts[2005];
vector <pair <int, pair<int,int>>> e;
int dp[2005];
vector <pair <int,int>> nxt;

int length(int u, int v){
    return (pts[u].fi - pts[v].fi) * (pts[u].fi - pts[v].fi) + (pts[u].se - pts[v].se) * (pts[u].se - pts[v].se);
}

void solve(){
    cin >> n;
    pts[0] = {0, 0};
    for(int i = 1; i <= n; i++)
        cin >> pts[i].fi >> pts[i].se;
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int akarin = length(i, j);
            e.pb({akarin, {i, j}});
        }
    }
    sort(e.begin(), e.end());
    e.pb({1e18 + 7, {1e18 + 7, 1e18 + 7}});
    for(int i = 0; i < e.size(); i++){
        int u = e[i].se.fi;
        int v = e[i].se.se;
        if(i == 0 || e[i].fi > e[i - 1].fi){
            for(; !nxt.empty(); nxt.pop_back()){
                dp[nxt.back().fi] = max(dp[nxt.back().fi], nxt.back().se);
            }
        }
        if(u == 1e18 + 7) break;
        if(v != 0)
            nxt.push_back({u, max(dp[u], dp[v] + 1)});
        if(u != 0)
            nxt.push_back({v, max(dp[u] + 1, dp[v])});
    }
    cout << dp[0] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}