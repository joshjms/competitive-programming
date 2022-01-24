#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int l, r, k;

void solve(){
    cin >> l >> r >> k;
    if(l == 1 && r == 1){
        cout << "NO\n";
        return;
    }
    if(l == r){
        cout << "YES\n";
        return;
    }
    int odds = (r - l + 1) - (r / 2 - (l - 1) / 2);
    if(odds <= k){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}