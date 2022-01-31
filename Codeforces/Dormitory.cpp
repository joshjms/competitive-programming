#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, d, arr[405], m;
vector <pair<int,int>> v[405];
pair<int,int> dp[405][405];
pair <int,int> backtrack[405][405];
int ans;
pair <int,int> stp;
vector <int> ansv[405];

void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        v[i].pb({0, 0});
    }
    cin >> m;
    for(int i = 1, l, r, f; i <= m; i++){
        cin >> l >> r >> f;
        for(int j = l; j <= r; j++){
            v[j].pb({f, i});
        }
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
        for(int j = 1; j < v[i].size(); j++){
            v[i][j].fi += v[i][j - 1].fi;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j].fi << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < 405; i++){
        for(int j = 0; j < 405; j++){
            dp[i][j] = {-1, 0};
        }
    }
    dp[1][0] = {0, 0};
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 400; j++){
            if(dp[i][j].fi == -1) continue;
            int food = j + arr[i] - d;
            if(food < 0) continue;
            for(int k = 0; k < v[i].size() && v[i][k].fi <= food; k++){
                int nid = min(arr[i], food - v[i][k].fi);
                // debug(nid);
                int uu = dp[i + 1][nid].fi;
                int vv = dp[i][j].fi + k;
                if(uu < vv){
                    dp[i + 1][nid] = {dp[i][j].fi + k, k};
                    backtrack[i + 1][nid] = {i, j};
                }   
            }
        }
    }
    for(int i = 0; i <= 400; i++){
        ans = max(ans, dp[n + 1][i].fi);
    }
    cout << ans << "\n";
    for(int i = 0; i <= 400; i++){
        if(dp[n + 1][i].fi == ans){
            stp = {n + 1, i};
            break;
        }
    }
    while(stp.fi > 1){
        for(int i = 1; i <= dp[stp.fi][stp.se].se; i++)
            ansv[stp.fi - 1].pb(v[stp.fi - 1][i].se);
        stp = backtrack[stp.fi][stp.se];
    }
    for(int i = 1; i <= n; i++){
        cout << ansv[i].size() << " ";
        for(auto j : ansv[i])
            cout << j << " ";
        cout << "\n";
    }
}

signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}