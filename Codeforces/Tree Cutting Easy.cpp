#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, arr[300005], cnt[300005][3], total[3], ans;
vector <int> g[300005];

void dfs(int pos, int par) {
    for(int c : g[pos]) if(c != par) {
        dfs(c, pos);
        for(int i = 0; i < 3; i++)
            cnt[pos][i] += cnt[c][i];
    }
    cnt[pos][arr[pos]]++;
    if((cnt[pos][1] == total[1] && cnt[pos][2] == 0) || (cnt[pos][2] == total[2] && cnt[pos][1] == 0))
        ans++;
}

void solve (){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        total[arr[i]]++;
    }
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}