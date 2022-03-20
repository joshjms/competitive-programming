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

int r, n, m;

int dp[255][255][255];
map <pair<int,pair<int,int>>, int> mp;

int calc(int node, int partial, int emp){
    if(node < 1) return 1;
    if(mp[{node, {partial, emp}}]) return dp[node][partial][emp];
    int p = 0, q = 0;
    if(partial)
        p = partial * calc(node - 1, partial - 1, emp + 1);
    if(emp)
        q = emp * calc(node - 1, partial + 1, emp);
    return mp[{node, {partial, emp}}] = (p + q) % m;
}

void solve(){
    cin >> r >> n >> m;
    cout << calc(n - 1, 0, 1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}