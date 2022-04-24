#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, k, arr[100005];
pair <int,int> p [100005], ans;

int cnt[200005], g;

int par[100005], sz[100005];

int find(int u) {
    return (u == par[u]) ? u : par[u] = find(par[u]);
}

int join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return 0;
    par[u] = v;
    cnt[sz[u]]--, cnt[sz[v]]--;
    sz[v] += sz[u];
    cnt[sz[v]]++;
    return 1;
}

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];   
        p[i] = {arr[i], i};
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i++) {
        k = p[i].fi + 1;
        g++;
        par[p[i].se] = p[i].se, sz[p[i].se] = 1;
        cnt[sz[find(p[i].se)]]++;
        if(par[p[i].se - 1] != 0) g -= join(p[i].se, p[i].se - 1); 
        if(par[p[i].se + 1] != 0) g -= join(p[i].se, p[i].se + 1); 
        if(cnt[sz[find(p[i].se)]] == g) ans = max(ans, {g, -k});
    }
    cout << -ans.se << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}