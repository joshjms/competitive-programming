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

int n, m, c[400005], d[400005], arr[105][105];
int cost, newcost, ans;
int req[105];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n + m - 1; i++){
        cin >> c[i];
        cost += c[i];
    }
    for(int i = 0; i < n + m - 1; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = i + (m - j - 1);
            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }
    ans = cost;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            req[arr[i][j]] |= (1ll << (i + j));
        }
    }
    // for(int i = 0; i < n + m - 1; i++)
    //     cout << req[i] << " ";
    // cout << "\n";
    for(int i = 0; i < (1ll << (n + m - 1)); i++){
        int mask = i;
        int newcost = cost;
        int add = 0;
        for(int b = 0; b < n + m - 1; b++)
            if((mask & (1ll << b)))
                add += d[b];
        newcost += add;
        for(int b = 0; b < n + m - 1; b++)\
            if((mask & req[b]) == req[b])
                newcost -= c[b];
        ans = min(ans, newcost);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}