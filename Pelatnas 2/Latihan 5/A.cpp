// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, arr[1500005], g, ans[1500005];
vector <int> marbs[1505];

int sz[1505];
priority_queue <pair<int,int>> pq;

void solve(){
    cin >> n;
    for(int i = 1; i <= n * n; i++){
        cin >> arr[i];
        marbs[arr[i]].pb(i);
    }
    for(int i = 1; i <= n + 1; i++){
        sz[i] = marbs[i].size();
        pq.push({-sz[i], i}); // count and color
    }
    while(!pq.empty()){
        int cnt = -pq.top().fi;
        int clr = pq.top().se;
        // debug(cnt);
        // debug(clr);
        pq.pop();
        if(sz[clr] != cnt) continue;
        if(cnt == 0) continue;
        ++g;
        if(cnt >= n){
            // fill this with all of this color:
            for(int i = 1; i <= n; i++){
                ans[marbs[clr].back()] = g;
                marbs[clr].pop_back();
            }
            sz[clr] = marbs[clr].size();
            pq.push({-sz[clr], clr});
        }
        else{
            pair <int,int> p = {1e18 + 7, 1e18 + 7};
            for(int i = 1; i <= n + 1; i++){
                if(i != clr && sz[i] + sz[clr] >= n){
                    p = min(p, {sz[i], i});
                }
            }
            if(p.fi == 1e18 + 7){
                cout << "NO\n";
                return;
            }
            int take = n - sz[clr];
            // debug(take);
            // debug(p.se);
            // debug(sz[p.se]);
            // debug(marbs[p.se].size());
            for(int i = 1; i <= take; i++){
                ans[marbs[p.se].back()] = g;
                marbs[p.se].pop_back();
            }
            for(int i = 1; i <= sz[clr]; i++){
                ans[marbs[clr].back()] = g;
                marbs[clr].pop_back();
            }
            sz[p.se] = marbs[p.se].size();
            sz[clr] = marbs[clr].size();
            pq.push({-sz[p.se], p.se});
        }
    }
    if(g > n){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= n * n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}