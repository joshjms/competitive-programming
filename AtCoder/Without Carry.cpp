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

int n, arr[1000005];
int dp[1000005], akari;
// dp i5i4i3i2i1i0 = \sum dpj5j4j3j2j1j0 where i5>=j5, i4>=j4, ..., i0>=j0

int invert(int x){
    return 999999 - x;
}

int _10[6] = {1, 10, 100, 1000, 10000, 100000};

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[arr[i]]++;
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 1e6; j++){
            if((j / _10[i]) % 10 < 9){
                dp[j + _10[i]] += dp[j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
        akari += dp[invert(arr[i])];
    for(int i = 1; i <= n; i++){
        bool ok = 1;
        for(int j = 0; j < 6; j++){
            if(((arr[i] / _10[j]) % 10) * 2 > 9){
                ok = 0;
                break;
            }
        }
        if(ok) akari--;
    }
    cout << akari / 2 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}