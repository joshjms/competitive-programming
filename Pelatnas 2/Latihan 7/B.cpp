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

int dp[2505];

int catalan(int u){
    if(u <= 1) return dp[u] = 1;
    if(dp[u] != 0) return dp[u];
    int res = 0;
    for(int i = 0; i < u; i++){
        (res += (catalan(i) * catalan(u - i - 1)) % m) %= m;
    }
    return dp[u] = res;
}

void solve(){
    cin >> r >> n >> m;
    cout << catalan(n - 1) % m << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}