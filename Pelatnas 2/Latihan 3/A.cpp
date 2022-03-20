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
int ag[2005][2005], g[2005][2005], cg[2005][2005];
int color[2005], cnt[3];

bool flag = 0;

void brute(int idx, vector <int> v){
    if(flag) return;
    if(idx > n){
        int color[n + 1], cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 1; i <= n; i++){
            color[i] = v[i - 1];
            cnt[color[i]]++;
        }
        // for(int i = 1; i <= n; i++)
        //     cout << color[i] << " ";
        // cout << "\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = ag[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(color[i] != color[j]){
                    g[i][j] = g[j][i] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                int edges = 0;
                for(int j = 1; j <= n; j++){
                    edges += g[i][j];
                }
                if(edges != cnt[0] - 1){
                    return;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == 1){
                int edges = 0;
                for(int j = 1; j <= n; j++){
                    edges += g[i][j];
                }
                if(edges != cnt[1] - 1){
                    return;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == 2){
                int edges = 0;
                for(int j = 1; j <= n; j++){
                    edges += g[i][j];
                }
                if(edges != cnt[2] - 1){
                    return;
                }
            }
        }
        for(int i = 1; i <= n; i++)
            if(color[i] == 1)
                cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= n; i++)
            if(color[i] == 2)
                cout << i << " ";
        cout << "\n";
        flag = 1;
        return;
    }
    for(int i = 0; i <= 2; i++){
        v.pb(i);
        brute(idx + 1, v);
        v.pop_back();
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ag[i][j] = 0;
            cg[i][j] = 1;
        }
    }
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        ag[u][v] = ag[v][u] = 1;
        cg[u][v] = cg[v][u] = 0;
    }
    vector <int> cur = {1, 2};
    brute(3, cur);
    if(!flag){
        cout << "impossible\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}