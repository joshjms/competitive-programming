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

int n, e, l[1005], r[1005], dp[1005][1005];
int maxi[1005][1005];

void solve(){
    cin >> n >> e;
    for(int i = 1; i < n; i++)
        cin >> r[i] >> l[i + 1];
    l[1] = e;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            maxi[i][j] = max(maxi[i][j - 1], max(r[j - 1], l[j]));
            cout << maxi[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}