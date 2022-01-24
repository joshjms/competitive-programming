#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int n, tmp, ans, l;

int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}

void solve(){
    cin >> n;
    tmp = n;
    ans = 0, l = 1;
    for(int i = 2; i <= 500; i++){
        l = lcm(l, i);
        (ans += (n - tmp / l) * i) %= mod;
        n = tmp / l;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}