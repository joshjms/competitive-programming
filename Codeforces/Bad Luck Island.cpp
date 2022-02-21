// AKARINNN!!!!!!!!! <3

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

int r, s, p;
ld dp[105][105][105];
ld a, b, c;

void solve(){
    cin >> r >> s >> p;
    dp[r][s][p] = 1;
    for(int i = r; i >= 0; i--){
        for(int j = s; j >= 0; j--){
            for(int k = p; k >= 0; k--){
                int akari = i * j + i * k + j * k;
                if(akari == 0) continue;
                if(i >= 1)
                    dp[i - 1][j][k] += (ld) (i * k) / akari * dp[i][j][k];
                if(j >= 1)
                    dp[i][j - 1][k] += (ld) (j * i) / akari * dp[i][j][k];
                if(k >= 1)
                    dp[i][j][k - 1] += (ld) (k * j) / akari * dp[i][j][k];
            }
        }
    }
    for(int i = 1; i <= r; i++)
        a += dp[i][0][0];
    for(int i = 1; i <= s; i++)
        b += dp[0][i][0];
    for(int i = 1; i <= p; i++)
        c += dp[0][0][i];
    cout << fixed << setprecision(10) << a << " " << b << " " << c << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}