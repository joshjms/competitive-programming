#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

vector <int> g[100005];
// g[i] berisi semua node yg terhubung dengan node i

bool vis[100005];

void dfs(int pos) {
    vis[pos] = true;
    for(int c : g[pos]) if(!vis[pos]) {
        dfs(c);
    }
}

void solve () {
    dfs(1);

    queue <int> q;
    q.push(1);
    while(!q.empty()) { // q.size() > 0
        int pos = q.front();
        q.pop();
        for(int c : g[pos]) if(!vis[pos]) {
            vis[c] = true;
            q.push(c);
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}