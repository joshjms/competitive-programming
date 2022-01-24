#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int n, arr[55], s, t;
pair <int,int> cur[55];
vector <int> adj[105];
bool vis[105];

void dfs(int pos){
    if(pos > n) t++; else s++;
    vis[pos] = 1;
    for(auto i : adj[pos]) if(vis[i] == false){
        dfs(i);
    }
}

void solve(){
    cin >> n;
    memset(vis, 0, sizeof(vis));
    memset(cur, -1, sizeof(cur));
    for(int i = 1; i <= 100; i++)
        adj[i].clear();
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++){
        while(arr[i]){
            if(arr[i] <= n){
                adj[n + i].push_back(arr[i]);
                adj[arr[i]].push_back(n + i);
            }
            arr[i] /= 2;
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[n + i]) continue;
        for(auto j : adj[n + i]){
            if(vis[j] == false){
                vis[n + i] = true;
                vis[j] = true;
                cur[j] = {adj[n + i].size(), n + i};
                // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
            }
            else{
                if(cur[j].fi > adj[n + i].size()){
                    vis[cur[j].se] = false;
                    vis[n + i] = true;
                    // cout << "divorce " << char(cur[j].se - n + 'A' - 1) << " and " << j << "\n";
                    cur[j] = {adj[n + i].size(), n + i};
                    // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
                }
            }
            if(vis[n + i]) break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[n + i]) continue;
        for(auto j : adj[n + i]){
            if(vis[j] == false){
                vis[n + i] = true;
                vis[j] = true;
                cur[j] = {adj[n + i].size(), n + i};
                // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
            }
            else{
                if(cur[j].fi > adj[n + i].size()){
                    vis[cur[j].se] = false;
                    vis[n + i] = true;
                    // cout << "divorce " << char(cur[j].se - n + 'A' - 1) << " and " << j << "\n";
                    cur[j] = {adj[n + i].size(), n + i};
                    // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
                }
            }
            if(vis[n + i]) break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[n + i]) continue;
        for(auto j : adj[n + i]){
            if(vis[j] == false){
                vis[n + i] = true;
                vis[j] = true;
                cur[j] = {adj[n + i].size(), n + i};
                // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
            }
            else{
                if(cur[j].fi > adj[n + i].size()){
                    vis[cur[j].se] = false;
                    vis[n + i] = true;
                    // cout << "divorce " << char(cur[j].se - n + 'A' - 1) << " and " << j << "\n";
                    cur[j] = {adj[n + i].size(), n + i};
                    // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
                }
            }
            if(vis[n + i]) break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[n + i]) continue;
        for(auto j : adj[n + i]){
            if(vis[j] == false){
                vis[n + i] = true;
                vis[j] = true;
                cur[j] = {adj[n + i].size(), n + i};
                // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
            }
            else{
                if(cur[j].fi > adj[n + i].size()){
                    vis[cur[j].se] = false;
                    vis[n + i] = true;
                    // cout << "divorce " << char(cur[j].se - n + 'A' - 1) << " and " << j << "\n";
                    cur[j] = {adj[n + i].size(), n + i};
                    // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
                }
            }
            if(vis[n + i]) break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[n + i]) continue;
        for(auto j : adj[n + i]){
            if(vis[j] == false){
                vis[n + i] = true;
                vis[j] = true;
                cur[j] = {adj[n + i].size(), n + i};
                // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
            }
            else{
                if(cur[j].fi > adj[n + i].size()){
                    vis[cur[j].se] = false;
                    vis[n + i] = true;
                    // cout << "divorce " << char(cur[j].se - n + 'A' - 1) << " and " << j << "\n";
                    cur[j] = {adj[n + i].size(), n + i};
                    // cout << "marry " << char(i + 'A' - 1) << " and " << j << "\n";
                }
            }
            if(vis[n + i]) break;
        }
    }
    for(int i = 1; i <= 2 * n; i++){
        if(vis[i] == 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    cin >> tc;
    while(tc--) solve();
} 