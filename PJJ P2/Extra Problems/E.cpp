// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

//#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, k;
int arr[35005], pos[35005], ne[35005], pre[35005];
int dp[105][35005];

int lf, rg, cur;

void calc(int l, int r){
    while(lf < l){
        if(ne[lf] && ne[lf] <= rg) cur -= ne[lf] - lf;
        lf++;
    }
    while(lf > l){
        lf--;
        if(ne[lf] && ne[lf] <= rg) cur += ne[lf] - lf;
    }
    while(rg > r){
        if(pre[rg] && pre[rg] >= lf) cur -= rg - pre[rg];
        rg--;
    }
    while(rg < r){
        rg++;
        if(pre[rg] && pre[rg] >= lf) cur += rg - pre[rg];
    }
}

void dnc(int peko, int l, int r, int optl, int optr){
    if(l > r || optl > optr) return;
    int mid = (l + r) / 2;
    pair <int,int> opt = {1e9 + 7, -1};
    for(int i = optl; i <= min(optr, mid - 1); i++){
        calc(i + 1, mid);
        opt = min(opt, {dp[peko - 1][i] + cur, i});
    }
    dp[peko][mid] = opt.fi;
    dnc(peko, l, mid - 1, optl, opt.se);
    dnc(peko, mid + 1, r, opt.se, optr);
}

void solve(){
    cin >> n >> k;
    lf = 1, rg = 1;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++){
        ne[pos[arr[i]]] = i, pre[i] = pos[arr[i]];
        pos[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        calc(1, i);
        dp[1][i] = cur;
    }
    for(int i = 2; i <= k; i++){
        dnc(i, i, n, 1, n);
    }
    // for(int i = 1; i <= k; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[k][n] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}