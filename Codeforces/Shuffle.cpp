#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, k, a, b;
int ps[5005];
char s[5005];

int c[5005][5005];
int ans = 0;

void combin(){
    for(int i = 0; i <= 5000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

void solve(){
    combin();
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        ps[i] += ps[i - 1] + (s[i] - '0');
    }
    if(ps[n] < k){
        cout << 1 << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            a = ps[j] - ps[i - 1];
            b = j - i + 1 - a;
            if(a > k) continue;
            if(s[i] == '0') a--;
            else b--;
            if(s[j] == '0') a--;
            else b--;
            if(a >= 0 && a + b >= 0) (ans += c[a + b][a]) %= mod;
        }
    }
    cout << (ans + 1) % mod << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}