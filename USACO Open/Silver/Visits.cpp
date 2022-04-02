#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, ans;
pair <int,int> arr[100005];
vector <pair<int,pair<int,int>>> segments;
bool vis[100005];

int par[100005];

int find(int u){
    if(u == par[u])
        return u;
    return par[u] = find(par[u]);
}

int join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    par[u] = v;
    return 1;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].fi >> arr[i].se;
        segments.pb({arr[i].se, {i, arr[i].fi}});
    }
    sort(segments.begin(), segments.end());
    reverse(segments.begin(), segments.end());
    for(int i = 1; i <= n; i++)
        par[i] = i;
    for(auto i : segments) {
        int w = i.fi;
        int u = i.se.fi;
        int v = i.se.se;
        if(join(u, v)) ans += w;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}