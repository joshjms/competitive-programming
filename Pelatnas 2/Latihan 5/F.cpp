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

int n, ans;
int c[55][55];

void combin(){
    for(int i = 0; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            if(j == 0 || i == j)
                c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

void solve(){
    combin();
    cin >> n; n--;
    for(int i = 0; i <= n; i++)
        ans += c[n][i];
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}