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

int n, p[200005], q, k;
vector <int> g[200005];
vector <int> roots;

int ent[200005], ext[200005], sz[200005];
int kano;

void dfs(int pos){
    ent[pos] = ++kano;
    for(auto i : g[pos]){
        dfs(i);
        sz[pos] += sz[i];
    }
    ext[pos] = ++kano;
    sz[pos]++;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] == 0)
            roots.pb(i);
        else g[p[i]].pb(i); 
    }
    for(auto i : roots)
        dfs(i);
    cin >> q;
    while(q--){
        cin >> k;
        vector <pair<int,pair<int,int>>> peko;
        for(int i = 0, u; i < k; i++){
            cin >> u;
            peko.pb({ent[u], {0, u}});
            peko.pb({ext[u], {1, u}});
        }
        sort(peko.begin(), peko.end());
        int akarin = 0, ans = 0;
        for(auto i : peko){
            int t = i.se.fi;
            int box = i.se.se;
            if(t == 0){
                // entry
                if(akarin == 0)
                    ans += sz[box]; 
                akarin++;
            }
            else if(t == 1){
                // exit
                akarin--;
            }
        }
        cout << ans << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}