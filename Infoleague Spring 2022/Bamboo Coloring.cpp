#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n;
vector <int> g[100005];
int c[100005], dp[100005], bt[100005];
int tmr, a, b;

void dfs(int pos, int par) {
    dp[pos] = pos;
    pair <int,int> p = {1e9 + 7, 1e9 + 7};
    pair <pair<int,int>, pair<int,int>> q = {{1e9 + 7, 1e9 + 7}, {1e9 + 7, 1e9 + 7}};
    for(auto i : g[pos]) if(i != par && c[i] == 0) {
        dfs(i, pos);
        dp[pos] = min(dp[pos], dp[i]);
        p = min(p, {dp[i], i});
        pair <pair<int,int>,pair<int,int>> qa = {{dp[i], i}, q.fi};
        pair <pair<int,int>,pair<int,int>> qb = {q.fi, {dp[i], i}};
        q = min(q, min(qa, qb));
    }
    a = q.fi.se, b = q.se.se;
    bt[pos] = p.se;
    return;
}

void solve (){
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; i++) if(c[i] == 0){
        for(int j = 1; j <= n; j++) {
            dp[j] = 1e9 + 7;
            bt[j] = 1e9 + 7;
        }
        c[i] = ++tmr;
        dfs(i, -1);
        while(a >= 1 && a <= n) {
            c[a] = tmr;
            a = bt[a];
        }
        while(b >= 1 && b <= n) {
            c[b] = tmr;
            b = bt[b];
        }
    }
    for(int i = 1; i <= n; i++) 
        cout << c[i] << " ";
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}