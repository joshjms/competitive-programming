#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, c[300005];
vector <int> g[300005], g2[300005];
int black[300005], par[300005];
int ans[300005];

int dfs(int pos){
    for(auto i : g[pos]) if(i != par[pos]){
        par[i] = pos;
        black[pos] += dfs(i);
    }
    return black[pos] + c[pos];
}

void dfs2(int pos){
    if(ans[pos]) return;
    ans[pos] = 1;
    for(auto i : g2[pos]) if(ans[i] == 0){
        dfs2(i);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    black[1] = dfs(1);
    for(int i = 1; i <= n; i++){
        for(auto j : g[i]){
            if(par[j] == i){
                if(c[i] || black[1] - black[j] > 1)
                    g2[i].pb(j);
            }
            else{
                if(c[i] || black[i] > 1)
                    g2[i].pb(j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(c[i]){
            dfs2(i);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}