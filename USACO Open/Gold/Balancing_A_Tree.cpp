#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int t, b;

int n, ans, s[100005];
int p[100005];
vector <int> g[100005];
int l_node[100005], r_node[100005];
int nl, nr, bl[100005], br[100005];

int l, r;

bool res;

pair <int,int> dfs(int pos, int par, int dist) {
    if(!res) return {-1, -1};
    int a = 0;
    int b = 1e9;
    for(auto c : g[pos]) if(c != par) {
        pair <int,int> p = dfs(c, pos, dist);
        a = max(a, p.fi);
        b = min(b, p.se);
        if(!res) return {-1, -1};
    }
    nl = a - dist, nr = b + dist;
    bl[pos] = nl, br[pos] = nr;
    if(nl > nr) { res = 0; return {-1, -1}; }
    if(nr < l_node[pos] || nl > r_node[pos]) { res = 0; return {-1, -1}; }
    else return {max(a, l_node[pos]), min(b, r_node[pos])};
}

void backtrack(int pos, int par, int l, int r, int max_l, int min_r, int d) {
    if(l_node[pos] >= l && l_node[pos] <= r)
        s[pos] = l_node[pos];
    else if(r_node[pos] >= l && r_node[pos] <= r)
        s[pos] = r_node[pos];
    else if(l >= l_node[pos] && l <= r_node[pos])
        s[pos] = l;
    else if(r >= l_node[pos] && r <= r_node[pos])
        s[pos] = r;
    max_l = max(max_l, s[pos] - d);
    min_r = min(min_r, s[pos] + d);
    for(auto c : g[pos]) if(c != par) {
        backtrack(c, pos, max(bl[c], max_l), min(br[c], min_r), max_l, min_r, d);
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        g[p[i]].pb(i);
    }
    for(int i = 1; i <= n; i++) {
        cin >> l_node[i] >> r_node[i];
    }
    memset(s, -1, sizeof(s));
    memset(bl, -1, sizeof(bl));
    memset(br, -1, sizeof(br));
    l = 0, r = 1e9;
    while(l <= r) {
        int mid = (l + r) / 2;
        res = 1;
        pair <int,int> p = dfs(1, -1, mid);
        if(res) {
            r = mid - 1, ans = mid;
            memset(s, -1, sizeof(s));
            backtrack(1, -1, nl, nr, 0, 1e9, mid);
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
    if(b){
        for(int i = 1; i <= n; i++){
            assert(s[i] >= l_node[i] && s[i] <= r_node[i]);
            cout << s[i];
            if(i < n) cout << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> b;
    while(t--) solve();
}